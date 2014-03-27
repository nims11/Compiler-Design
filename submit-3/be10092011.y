%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int line_no;
#define INT 0x1
#define FLOAT 0x2
#define DOUBLE 0x4
#define CHAR 0x8
#define PTR 0x10
#define ARR 0x20
struct constValList;
typedef struct constVal{
	int type;
	void *value;
	int intVal;
	double doubleVal;
	struct constVal *next;
	struct constValList *parentLL;
}constVal;

typedef struct constValList{
	int size;
	struct constVal *head, *tail;
}constValList;

constValList *newConstValList(){
	constValList *ret = (constValList*)malloc(sizeof(constValList));
	ret->head = ret->tail = NULL;
	ret->size = 0;
	return ret;
}

typedef struct symItem {
	char *name;
	int type, line_no, size, init;
	int arr_dim;
	int newDec;
	constVal *value;
	union {
		char *str;
		int intVal;
		char charVal;
		float floatVal;
		double doubleVal;
	}val;
	struct symItem *next, *prev;
}symItem;

symItem *symTable = NULL, *symTableTail = NULL;
int symTableSize = 0;
symItem *findSymItem(const char *name){
	symItem *curr = symTable;
	while(curr){
		if(strcmp(curr->name, name) == 0)
			return curr;
		curr = curr->next;
	}
	return NULL;
}
symItem *addSymItem(const char *name){
	symItem *ret = (symItem *)malloc(sizeof(symItem));
	ret->type = 0;
	ret->size = -1;
	ret->init = 0;
	ret->line_no = line_no;
	ret->arr_dim = 0;
	ret->name = malloc(32);
	ret->value = NULL;
	ret->newDec = 1;
	strcpy(ret->name, name);
	ret->next = ret->prev = NULL;
	if(symTable == NULL){
		symTable = symTableTail = ret;
	}else{
		symTableTail->next = ret;
		ret->prev = symTableTail;
		symTableTail = ret;
	}
	symTableSize++;
	return ret;
}

void printSymTable(){
	symItem *curr = symTable;
	printf("\n***Symbol Table***\n");
	printf("Size: %d\n", symTableSize);
	printf("INT: %d, CHAR: %d, FLOAT: %d, DOUBLE: %d\n", INT, CHAR, FLOAT, DOUBLE);
	printf("Line\tID\ttype\tis_array\t(size)\tinit_value(s)\n");
	while(curr){
		printf("%d\t%s\t%d\t%d\t\t%d\t", curr->line_no, curr->name, curr->type, (curr->arr_dim > 0), curr->size);
		if(curr->init && curr->value){
			if(curr->arr_dim == 0){
				switch(curr->type){
					case INT: printf("%d\n", curr->val.intVal);
					break;
					case DOUBLE: printf("%lf\n", curr->val.doubleVal);
					break;
					case FLOAT: printf("%f\n", curr->val.floatVal);
					break;
					case CHAR: printf("%c\n", curr->val.charVal);
					break;
				}
			}else{
				constVal *tmp = curr->value->parentLL->head;
				while(tmp){
					switch(curr->type){
						case INT: printf("%d ", tmp->intVal);
						break;
						case DOUBLE: printf("%lf ", tmp->doubleVal);
						break;
						case FLOAT: printf("%f ", tmp->doubleVal);
						break;
						case CHAR: printf("%c ", tmp->intVal);
						break;
					}
					tmp = tmp->next;
				}
				printf("\n");
			}
		}else
			printf("---\n");
		curr = curr->next;
	}
}

%}

%union
{
	int intVal;
	char charVal;
	char* strVal;
	double doubleVal;
	float floatVal;
	void *voidPtr;
	constVal *consts;
	constValList *constList;

	symItem *symPtr;
}

%token KW_auto KW_double KW_int KW_struct KW_break KW_else KW_long KW_switch KW_case KW_enum KW_register KW_typedef KW_char KW_extern KW_return KW_union KW_const KW_float KW_short KW_unsigned KW_continue KW_for KW_signed KW_void KW_default KW_goto KW_sizeof KW_volatile KW_do KW_if KW_static KW_while OP_PLUS OP_MINUS OP_STAR OP_AMP OP_COMP OP_NEGATE OP_DIV OP_MOD OP_LT OP_GT OP_BITOR OP_BITXOR OP_ASSIGN OP_COMMA OP_DOT OP_QUES OP_INCR OP_DECR OP_LSHIFT OP_RSHIFT OP_LTE OP_GTE OP_EQ OP_NEQ OP_LOGAND OP_LOGOR OP_PLUSEQ OP_DIVEQ OP_MODEQ OP_MINUSEQ OP_MULEQ OP_LSHIFTEQ OP_RSHIFTEQ OP_OREQ OP_ANDEQ OP_XOREQ OP_DEREF OP_ELLIPSIS PUNC_OPBRACE PUNC_CLOSEBRACE PUNC_OPSQRBKT PUNC_CLOSESQRBKT PUNC_OPBKT PUNC_CLOSEBKT PUNC_SEMICOLON PUNC_COLON IDENTIFIER NUMBER REAL_NUMBER EXP_NUMBER CHAR_CONSTANT STRING_CONSTANT

%type <intVal> type-specifier declaration-specifiers
%type <symPtr> direct-declarator declarator init-declarator init-declarator-list declaration external-declaration
%type <consts> constant primary-expression postfix-expression unary-expression cast-expression multiplicative-expression additive-expression shift-expression relational-expression equality-expression AND-expression exclusive-OR-expression inclusive-OR-expression logical-OR-expression logical-AND-expression conditional-expression assignment-expression initializer constant-expression
%type <constList> initializer-list
%%
translation-unit: external-declaration  {printf("\ttranslation-unit ->  external-declaration \n");}
| translation-unit external-declaration  {printf("\ttranslation-unit ->  translation-unit external-declaration \n");}
	;

external-declaration: function-definition  {printf("\texternal-declaration ->  function-definition \n");}
| declaration  {printf("\texternal-declaration ->  declaration \n"); $$ = $1;}
	;

function-definition: declaration-specifiers declarator declaration-list compound-statement  {printf("\tfunction-definition ->  declaration-specifiers declarator declaration-list compound-statement \n");}
| declaration-specifiers declarator compound-statement  {printf("\tfunction-definition ->  declaration-specifiers declarator compound-statement \n");}
| declarator declaration-list compound-statement  {printf("\tfunction-definition ->  declarator declaration-list compound-statement \n");}
| declarator compound-statement  {printf("\tfunction-definition ->  declarator compound-statement \n");}
	;

declaration: declaration-specifiers init-declarator-list PUNC_SEMICOLON  {
	symItem *tmp = $2;
	printf("\tdeclaration ->  declaration-specifiers init-declarator-list PUNC_SEMICOLON \n");
	$$ = $2;
	while(tmp){
		if(tmp->newDec == 0){
			yyerror();
			printf("Redeclaration of variable %s, previously declared at line %d\n", tmp->name, tmp->line_no);
			exit(-1);
			YYERROR;
		}
		tmp->type |= $1;
		tmp->newDec = 0;
		if(tmp->init && tmp->value && tmp->size == -1){
			switch(tmp->type){
				case INT: tmp->val.intVal = tmp->value->intVal;
				break;
				case CHAR: tmp->val.charVal = tmp->value->intVal;
				break;
				case FLOAT: tmp->val.floatVal = tmp->value->doubleVal;
				break;
				case DOUBLE: tmp->val.doubleVal = tmp->value->doubleVal;
				break;
			}
		}
		tmp = tmp->next;
	}
}
| declaration-specifiers PUNC_SEMICOLON  {printf("\tdeclaration ->  declaration-specifiers PUNC_SEMICOLON \n");}
	;

declaration-list: declaration  {printf("\tdeclaration-list ->  declaration \n");}
| declaration-list declaration  {printf("\tdeclaration-list ->  declaration-list declaration \n");}
	;

declaration-specifiers: storage-class-specifier declaration-specifiers  {printf("\tdeclaration-specifiers ->  storage-class-specifier declaration-specifiers \n");}
| storage-class-specifier  {printf("\tdeclaration-specifiers ->  storage-class-specifier \n");}
| type-specifier declaration-specifiers  {printf("\tdeclaration-specifiers ->  type-specifier declaration-specifiers \n");}
| type-specifier  {printf("\tdeclaration-specifiers ->  type-specifier \n");$$ = $<intVal>1;}
| type-qualifier declaration-specifiers  {printf("\tdeclaration-specifiers ->  type-qualifier declaration-specifiers \n");}
| type-qualifier  {printf("\tdeclaration-specifiers ->  type-qualifier \n");}
	;

storage-class-specifier: KW_auto  {printf("\tstorage-class-specifier ->  KW_auto \n");}
| KW_register  {printf("\tstorage-class-specifier ->  KW_register \n");}
| KW_static  {printf("\tstorage-class-specifier ->  KW_static \n");}
| KW_extern  {printf("\tstorage-class-specifier ->  KW_extern \n");}
| KW_typedef  {printf("\tstorage-class-specifier ->  KW_typedef \n");}
	;

type-specifier: KW_void  {printf("\ttype-specifier ->  KW_void \n");}
| KW_char  {printf("\ttype-specifier ->  KW_char \n"); $$ = $<intVal>1;}
| KW_short  {printf("\ttype-specifier ->  KW_short \n");}
| KW_int  {printf("\ttype-specifier ->  KW_int \n"); $$ = $<intVal>1;}
| KW_long  {printf("\ttype-specifier ->  KW_long \n");}
| KW_float  {printf("\ttype-specifier ->  KW_float \n"); $$ = $<intVal>1;}
| KW_double  {printf("\ttype-specifier ->  KW_double \n"); $$ = $<intVal>1;}
| KW_signed  {printf("\ttype-specifier ->  KW_signed \n");}
| KW_unsigned  {printf("\ttype-specifier ->  KW_unsigned \n");}
| struct-or-union-specifier  {printf("\ttype-specifier ->  struct-or-union-specifier \n");}
| enum-specifier  {printf("\ttype-specifier ->  enum-specifier \n");}
// | typedef-name  {printf("\ttype-specifier ->  | typedef-name \n");}
	;

type-qualifier: KW_const  {printf("\ttype-qualifier ->  KW_const \n");}
| KW_volatile  {printf("\ttype-qualifier ->  KW_volatile \n");}
	;

struct-or-union-specifier: struct-or-union IDENTIFIER PUNC_OPBRACE struct-declaration-list PUNC_CLOSEBRACE  {printf("\tstruct-or-union-specifier ->  struct-or-union IDENTIFIER PUNC_OPBRACE struct-declaration-list PUNC_CLOSEBRACE \n");}
| struct-or-union PUNC_OPBRACE struct-declaration-list PUNC_CLOSEBRACE  {printf("\tstruct-or-union-specifier ->  struct-or-union PUNC_OPBRACE struct-declaration-list PUNC_CLOSEBRACE \n");}
| struct-or-union IDENTIFIER  {printf("\tstruct-or-union-specifier ->  struct-or-union IDENTIFIER \n");}
	;

struct-or-union: KW_struct  {printf("\tstruct-or-union ->  KW_struct \n");}
| KW_union  {printf("\tstruct-or-union ->  KW_union \n");}
	;

struct-declaration-list: struct-declaration  {printf("\tstruct-declaration-list ->  struct-declaration \n");}
| struct-declaration-list struct-declaration  {printf("\tstruct-declaration-list ->  struct-declaration-list struct-declaration \n");}
	;

init-declarator-list: init-declarator  {printf("\tinit-declarator-list ->  init-declarator \n"); $$ = $1;}
| init-declarator-list OP_COMMA init-declarator  {
	printf("\tinit-declarator-list ->  init-declarator-list OP_COMMA init-declarator \n");
	$$ = $1;
}
	;

init-declarator: declarator  {printf("\tinit-declarator ->  declarator \n"); $$ = $1;}
| declarator OP_ASSIGN initializer  {
	printf("\tinit-declarator ->  declarator OP_ASSIGN initializer \n");
	if($$->newDec){
		$$ = $1;
		$$->init = 1;
		$$->value = $3;
		if($$->size == -2){
			$$->size = $$->value->parentLL->size;
		}else if($$->size != -1){
			
		}
	}
}
	;

struct-declaration: specifier-qualifier-list struct-declarator-list PUNC_SEMICOLON  {printf("\tstruct-declaration ->  specifier-qualifier-list struct-declarator-list PUNC_SEMICOLON \n");}
	;

specifier-qualifier-list: type-specifier specifier-qualifier-list  {printf("\tspecifier-qualifier-list ->  type-specifier specifier-qualifier-list \n");}
| type-specifier  {printf("\tspecifier-qualifier-list ->  type-specifier \n");}
| type-qualifier specifier-qualifier-list  {printf("\tspecifier-qualifier-list ->  type-qualifier specifier-qualifier-list \n");}
| type-qualifier  {printf("\tspecifier-qualifier-list ->  type-qualifier \n");}
	;

struct-declarator-list: struct-declarator  {printf("\tstruct-declarator-list ->  struct-declarator \n");}
| struct-declarator-list OP_COMMA struct-declarator  {printf("\tstruct-declarator-list ->  struct-declarator-list OP_COMMA struct-declarator \n");}
	;

struct-declarator: declarator  {printf("\tstruct-declarator ->  declarator \n");}
| declarator PUNC_COLON constant-expression  {printf("\tstruct-declarator ->  declarator PUNC_COLON constant-expression \n");}
| PUNC_COLON constant-expression  {printf("\tstruct-declarator ->  PUNC_COLON constant-expression \n");}
	;

enum-specifier: KW_enum IDENTIFIER PUNC_OPBRACE enumerator-list PUNC_CLOSEBRACE  {printf("\tenum-specifier ->  KW_enum IDENTIFIER PUNC_OPBRACE enumerator-list PUNC_CLOSEBRACE \n");}
| KW_enum PUNC_OPBRACE enumerator-list PUNC_CLOSEBRACE  {printf("\tenum-specifier ->  KW_enum PUNC_OPBRACE enumerator-list PUNC_CLOSEBRACE \n");}
| KW_enum IDENTIFIER  {printf("\tenum-specifier ->  KW_enum IDENTIFIER \n");}
	;

enumerator-list: enumerator  {printf("\tenumerator-list ->  enumerator \n");}
| enumerator-list OP_COMMA enumerator  {printf("\tenumerator-list ->  enumerator-list OP_COMMA enumerator \n");}
	;

enumerator: IDENTIFIER  {printf("\tenumerator ->  IDENTIFIER \n");}
| IDENTIFIER OP_ASSIGN constant-expression  {printf("\tenumerator ->  IDENTIFIER OP_ASSIGN constant-expression \n");}
	;

declarator: pointer direct-declarator  {printf("\tdeclarator ->  pointer direct-declarator \n");}
| direct-declarator  {printf("\tdeclarator ->  direct-declarator \n"); $$ = $1;}
	;

direct-declarator: IDENTIFIER  {
	symItem *prev = findSymItem($<strVal>1);
	printf("\tdirect-declarator ->  IDENTIFIER \n");
	if(prev == NULL){
		$$ = addSymItem($<strVal>1);
	}else {
		$$ = prev;
	}
}
| PUNC_OPBKT declarator PUNC_CLOSEBKT  {printf("\tdirect-declarator ->  PUNC_OPBKT declarator PUNC_CLOSEBKT \n");}
| direct-declarator PUNC_OPSQRBKT constant-expression PUNC_CLOSESQRBKT  {
	printf("\tdirect-declarator ->  direct-declarator PUNC_OPSQRBKT constant-expression PUNC_CLOSESQRBKT \n");
	$$ = $1;
	$$->arr_dim++;
	if(($3->type & INT) || ($3->type & CHAR))
		$$->size = *(int*)$3->value;
	else{
		yyerror();
		printf("Only Integer values allowed as array index\n");
		exit(-1);
		YYERROR;
	}
}
| direct-declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT  {
	printf("\tdirect-declarator ->  direct-declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT \n");
	$$ = $1;
	$$->arr_dim++;
	$$->size = -2;	// Variable;
}
| direct-declarator PUNC_OPBKT parameter-type-list PUNC_CLOSEBKT  {printf("\tdirect-declarator ->  direct-declarator PUNC_OPBKT parameter-type-list PUNC_CLOSEBKT \n");}
| direct-declarator PUNC_OPBKT identifier-list PUNC_CLOSEBKT  {printf("\tdirect-declarator ->  direct-declarator PUNC_OPBKT identifier-list PUNC_CLOSEBKT \n");}
| direct-declarator PUNC_OPBKT PUNC_CLOSEBKT  {printf("\tdirect-declarator ->  direct-declarator PUNC_OPBKT PUNC_CLOSEBKT \n");}
	;

pointer: OP_STAR type-qualifier-list  {printf("\tpointer ->  OP_STAR type-qualifier-list \n");}
| OP_STAR  {printf("\tpointer ->  OP_STAR \n");}
| OP_STAR type-qualifier-list pointer  {printf("\tpointer ->  OP_STAR type-qualifier-list pointer \n");}
| OP_STAR pointer  {printf("\tpointer ->  OP_STAR pointer \n");}
	;

type-qualifier-list: type-qualifier  {printf("\ttype-qualifier-list ->  type-qualifier \n");}
| type-qualifier-list type-qualifier  {printf("\ttype-qualifier-list ->  type-qualifier-list type-qualifier \n");}
	;

parameter-type-list: parameter-list  {printf("\tparameter-type-list ->  parameter-list \n");}
| parameter-list OP_COMMA OP_ELLIPSIS  {printf("\tparameter-type-list ->  parameter-list OP_COMMA OP_ELLIPSIS \n");}
	;

parameter-list: parameter-declaration  {printf("\tparameter-list ->  parameter-declaration \n");}
| parameter-list OP_COMMA parameter-declaration  {printf("\tparameter-list ->  parameter-list OP_COMMA parameter-declaration \n");}
	;

parameter-declaration: declaration-specifiers declarator  {printf("\tparameter-declaration ->  declaration-specifiers declarator \n");}
| declaration-specifiers abstract-declarator  {printf("\tparameter-declaration ->  declaration-specifiers abstract-declarator \n");}
| declaration-specifiers  {printf("\tparameter-declaration ->  declaration-specifiers \n");}
	;

identifier-list: IDENTIFIER  {printf("\tidentifier-list ->  IDENTIFIER \n");}
| identifier-list OP_COMMA IDENTIFIER  {printf("\tidentifier-list ->  identifier-list OP_COMMA IDENTIFIER \n");}
	;

initializer: assignment-expression  {printf("\tinitializer ->  assignment-expression \n"); $$ = $1;}
| PUNC_OPBRACE initializer-list PUNC_CLOSEBRACE  {
	printf("\tinitializer ->  PUNC_OPBRACE initializer-list PUNC_CLOSEBRACE \n");
	$$ = $2->head;
}
| PUNC_OPBRACE initializer-list OP_COMMA PUNC_CLOSEBRACE  {printf("\tinitializer ->  PUNC_OPBRACE initializer-list OP_COMMA PUNC_CLOSEBRACE \n");}
	;

initializer-list: initializer  {
	printf("\tinitializer-list ->  initializer \n");
	$$ = newConstValList();
	$$->size = 1;
	$$->head = $$->tail = $1;
	$1->parentLL = $$;
}
| initializer-list OP_COMMA initializer  {
	printf("\tinitializer-list ->  initializer-list OP_COMMA initializer \n");
	$$ = $1;
	$$->size++;
	$$->tail->next = $3;
	$$->tail = $3;
	$3->parentLL = $$;
}
	;

type-name: specifier-qualifier-list abstract-declarator  {printf("\ttype-name ->  specifier-qualifier-list abstract-declarator \n");}
| specifier-qualifier-list  {printf("\ttype-name ->  specifier-qualifier-list \n");}
	;

abstract-declarator: pointer  {printf("\tabstract-declarator ->  pointer \n");}
| pointer direct-abstract-declarator  {printf("\tabstract-declarator ->  pointer direct-abstract-declarator \n");}
| direct-abstract-declarator  {printf("\tabstract-declarator ->  direct-abstract-declarator \n");}
	;

direct-abstract-declarator: PUNC_OPBKT abstract-declarator PUNC_CLOSEBKT  {printf("\tdirect-abstract-declarator ->  PUNC_OPBKT abstract-declarator PUNC_CLOSEBKT \n");}
| direct-abstract-declarator PUNC_OPSQRBKT constant-expression PUNC_CLOSESQRBKT  {printf("\tdirect-abstract-declarator ->  direct-abstract-declarator PUNC_OPSQRBKT constant-expression PUNC_CLOSESQRBKT \n");}
| direct-abstract-declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT  {printf("\tdirect-abstract-declarator ->  direct-abstract-declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT \n");}
| PUNC_OPSQRBKT constant-expression PUNC_CLOSESQRBKT  {printf("\tdirect-abstract-declarator ->  PUNC_OPSQRBKT constant-expression PUNC_CLOSESQRBKT \n");}
| PUNC_OPSQRBKT PUNC_CLOSESQRBKT  {printf("\tdirect-abstract-declarator ->  PUNC_OPSQRBKT PUNC_CLOSESQRBKT \n");}
| direct-abstract-declarator PUNC_OPBKT parameter-type-list PUNC_CLOSEBKT  {printf("\tdirect-abstract-declarator ->  direct-abstract-declarator PUNC_OPBKT parameter-type-list PUNC_CLOSEBKT \n");}
| direct-abstract-declarator PUNC_OPBKT PUNC_CLOSEBKT  {printf("\tdirect-abstract-declarator ->  direct-abstract-declarator PUNC_OPBKT PUNC_CLOSEBKT \n");}
| PUNC_OPBKT parameter-type-list PUNC_CLOSEBKT  {printf("\tdirect-abstract-declarator ->  PUNC_OPBKT parameter-type-list PUNC_CLOSEBKT \n");}
| PUNC_OPBKT PUNC_CLOSEBKT  {printf("\tdirect-abstract-declarator ->  PUNC_OPBKT PUNC_CLOSEBKT \n");}
	;


statement: labeled-statement  {printf("\tstatement ->  labeled-statement \n");}
| expression-statement  {printf("\tstatement ->  expression-statement \n");}
| compound-statement  {printf("\tstatement ->  compound-statement \n");}
| selection-statement  {printf("\tstatement ->  selection-statement \n");}
| iteration-statement  {printf("\tstatement ->  iteration-statement \n");}
| jump-statement  {printf("\tstatement ->  jump-statement \n");}
	;

labeled-statement: IDENTIFIER PUNC_COLON statement  {printf("\tlabeled-statement ->  IDENTIFIER PUNC_COLON statement \n");}
| KW_case constant-expression PUNC_COLON statement  {printf("\tlabeled-statement ->  KW_case constant-expression PUNC_COLON statement \n");}
| KW_default PUNC_COLON statement  {printf("\tlabeled-statement ->  KW_default PUNC_COLON statement \n");}
	;

expression-statement: expression PUNC_SEMICOLON  {printf("\texpression-statement ->  expression PUNC_SEMICOLON \n");}
| PUNC_SEMICOLON  {printf("\texpression-statement ->  PUNC_SEMICOLON \n");}
	;

compound-statement: PUNC_OPBRACE declaration-list statement-list PUNC_CLOSEBRACE  {printf("\tcompound-statement ->  PUNC_OPBRACE declaration-list statement-list PUNC_CLOSEBRACE \n");}
| PUNC_OPBRACE statement-list PUNC_CLOSEBRACE  {printf("\tcompound-statement ->  PUNC_OPBRACE statement-list PUNC_CLOSEBRACE \n");}
| PUNC_OPBRACE declaration-list PUNC_CLOSEBRACE  {printf("\tcompound-statement ->  PUNC_OPBRACE declaration-list PUNC_CLOSEBRACE \n");}
| PUNC_OPBRACE PUNC_CLOSEBRACE  {printf("\tcompound-statement ->  PUNC_OPBRACE PUNC_CLOSEBRACE \n");}
	;

statement-list: statement  {printf("\tstatement-list ->  statement \n");}
| statement-list statement  {printf("\tstatement-list ->  statement-list statement \n");}
	;

selection-statement: KW_if PUNC_OPBKT expression PUNC_CLOSEBKT statement  {printf("\tselection-statement ->  KW_if PUNC_OPBKT expression PUNC_CLOSEBKT statement \n");}
| KW_if PUNC_OPBKT expression PUNC_CLOSEBKT statement KW_else statement  {printf("\tselection-statement ->  KW_if PUNC_OPBKT expression PUNC_CLOSEBKT statement KW_else statement \n");}
| KW_switch PUNC_OPBKT expression PUNC_CLOSEBKT statement  {printf("\tselection-statement ->  KW_switch PUNC_OPBKT expression PUNC_CLOSEBKT statement \n");}
	;

iteration-statement: KW_while PUNC_OPBKT expression PUNC_CLOSEBKT statement  {printf("\titeration-statement ->  KW_while PUNC_OPBKT expression PUNC_CLOSEBKT statement \n");}
| KW_do statement KW_while PUNC_OPBKT expression PUNC_CLOSEBKT PUNC_SEMICOLON  {printf("\titeration-statement ->  KW_do statement KW_while PUNC_OPBKT expression PUNC_CLOSEBKT PUNC_SEMICOLON \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement  {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement  {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement  {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement  {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement  {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement  {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement  {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement  {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
	;

jump-statement: KW_goto IDENTIFIER PUNC_SEMICOLON  {printf("\tjump-statement ->  KW_goto IDENTIFIER PUNC_SEMICOLON \n");}
| KW_continue PUNC_SEMICOLON  {printf("\tjump-statement ->  KW_continue PUNC_SEMICOLON \n");}
| KW_break PUNC_SEMICOLON  {printf("\tjump-statement ->  KW_break PUNC_SEMICOLON \n");}
| KW_return expression PUNC_SEMICOLON  {printf("\tjump-statement ->  KW_return expression PUNC_SEMICOLON \n");}
| KW_return PUNC_SEMICOLON  {printf("\tjump-statement ->  KW_return PUNC_SEMICOLON \n");}
	;

expression: assignment-expression  {printf("\texpression ->  assignment-expression \n");}
| expression OP_COMMA assignment-expression  {printf("\texpression ->  expression OP_COMMA assignment-expression \n");}
	;

assignment-expression: conditional-expression  {printf("\tassignment-expression ->  conditional-expression \n"); $$ = $1;}
| unary-expression assignment-operator assignment-expression  {printf("\tassignment-expression ->  unary-expression assignment-operator assignment-expression \n");}
	;

assignment-operator: OP_ASSIGN  {printf("\tassignment-operator ->  OP_ASSIGN \n");}
| OP_MULEQ  {printf("\tassignment-operator ->  OP_MULEQ \n");}
| OP_DIVEQ  {printf("\tassignment-operator ->  OP_DIVEQ \n");}
| OP_MODEQ  {printf("\tassignment-operator ->  OP_MODEQ \n");}
| OP_PLUSEQ  {printf("\tassignment-operator ->  OP_PLUSEQ \n");}
| OP_MINUSEQ  {printf("\tassignment-operator ->  OP_MINUSEQ \n");}
| OP_LSHIFTEQ  {printf("\tassignment-operator ->  OP_LSHIFTEQ \n");}
| OP_RSHIFTEQ  {printf("\tassignment-operator ->  OP_RSHIFTEQ \n");}
| OP_ANDEQ  {printf("\tassignment-operator ->  OP_ANDEQ \n");}
| OP_XOREQ  {printf("\tassignment-operator ->  OP_XOREQ \n");}
| OP_OREQ  {printf("\tassignment-operator ->  OP_OREQ \n");}
	;

conditional-expression: logical-OR-expression  {printf("\tconditional-expression ->  logical-OR-expression \n"); $$ = $1;}
| logical-OR-expression OP_QUES expression PUNC_COLON conditional-expression  {printf("\tconditional-expression ->  logical-OR-expression OP_QUES expression PUNC_COLON conditional-expression \n");}
	;

constant-expression: conditional-expression  {printf("\tconstant-expression ->  conditional-expression \n"); $$ = $1;}
	;

logical-OR-expression: logical-AND-expression  {printf("\tlogical-OR-expression ->  logical-AND-expression \n"); $$ = $1;}
| logical-OR-expression OP_LOGOR logical-AND-expression  {printf("\tlogical-OR-expression ->  logical-OR-expression OP_LOGOR logical-AND-expression \n");}
	;

logical-AND-expression: inclusive-OR-expression  {printf("\tlogical-AND-expression ->  inclusive-OR-expression \n"); $$ = $1;}
| logical-AND-expression OP_LOGAND inclusive-OR-expression  {printf("\tlogical-AND-expression ->  logical-AND-expression OP_LOGAND inclusive-OR-expression \n");}
	;

inclusive-OR-expression: exclusive-OR-expression  {printf("\tinclusive-OR-expression ->  exclusive-OR-expression \n"); $$ = $1;}
| inclusive-OR-expression OP_BITOR exclusive-OR-expression  {printf("\tinclusive-OR-expression ->  inclusive-OR-expression OP_BITOR exclusive-OR-expression \n");}

exclusive-OR-expression: AND-expression  {printf("\texclusive-OR-expression ->  AND-expression \n"); $$ = $1;}
| exclusive-OR-expression OP_BITXOR AND-expression  {printf("\texclusive-OR-expression ->  exclusive-OR-expression OP_BITXOR AND-expression \n");}
	;

AND-expression: equality-expression  {printf("\tAND-expression ->  equality-expression \n"); $$ = $1;}
| AND-expression OP_AMP equality-expression  {printf("\tAND-expression ->  AND-expression OP_AMP equality-expression \n");}
	;

equality-expression: relational-expression  {printf("\tequality-expression ->  relational-expression \n"); $$ = $1;}
| equality-expression OP_EQ relational-expression  {printf("\tequality-expression ->  equality-expression OP_EQ relational-expression \n");}
| equality-expression OP_NEQ relational-expression  {printf("\tequality-expression ->  equality-expression OP_NEQ relational-expression \n");}
	;

relational-expression: shift-expression  {printf("\trelational-expression ->  shift-expression \n"); $$ = $1;}
| relational-expression OP_LT shift-expression  {printf("\trelational-expression ->  relational-expression OP_LT shift-expression \n");}
| relational-expression OP_GT shift-expression  {printf("\trelational-expression ->  relational-expression OP_GT shift-expression \n");}
| relational-expression OP_LTE shift-expression  {printf("\trelational-expression ->  relational-expression OP_LTE shift-expression \n");}
| relational-expression OP_GTE shift-expression  {printf("\trelational-expression ->  relational-expression OP_GTE shift-expression \n");}
	;

shift-expression: additive-expression  {printf("\tshift-expression ->  additive-expression \n"); $$ = $1;}
| shift-expression OP_LSHIFT additive-expression  {printf("\tshift-expression ->  shift-expression OP_LSHIFT additive-expression \n");}
| shift-expression OP_RSHIFT additive-expression  {printf("\tshift-expression ->  shift-expression OP_RSHIFT additive-expression \n");}
	;

additive-expression: multiplicative-expression  {printf("\tadditive-expression ->  multiplicative-expression \n"); $$ = $1;}
| additive-expression OP_PLUS multiplicative-expression  {printf("\tadditive-expression ->  additive-expression OP_PLUS multiplicative-expression \n");}
| additive-expression OP_MINUS multiplicative-expression  {printf("\tadditive-expression ->  additive-expression OP_MINUS multiplicative-expression \n");}
	;

multiplicative-expression: cast-expression  {printf("\tmultiplicative-expression ->  cast-expression \n"); $$ = $1;}
| multiplicative-expression OP_STAR cast-expression  {printf("\tmultiplicative-expression ->  multiplicative-expression OP_STAR cast-expression \n");}
| multiplicative-expression OP_DIV cast-expression  {printf("\tmultiplicative-expression ->  multiplicative-expression OP_DIV cast-expression \n");}
| multiplicative-expression OP_MOD cast-expression  {printf("\tmultiplicative-expression ->  multiplicative-expression OP_MOD cast-expression \n");}
	;

cast-expression: unary-expression  {printf("\tcast-expression ->  unary-expression \n"); $$ = $1;}
| PUNC_OPBKT type-name PUNC_CLOSEBKT cast-expression  {printf("\tcast-expression ->  PUNC_OPBKT type-name PUNC_CLOSEBKT cast-expression \n");}
	;

unary-expression: postfix-expression  {printf("\tunary-expression ->  postfix-expression \n"); $$ = $1;}
| OP_INCR unary-expression  {printf("\tunary-expression ->  OP_INCR unary-expression \n");}
| OP_DECR unary-expression  {printf("\tunary-expression ->  OP_DECR unary-expression \n");}
| unary-operator cast-expression  {printf("\tunary-expression ->  unary-operator cast-expression \n");}
| KW_sizeof unary-expression  {printf("\tunary-expression ->  KW_sizeof unary-expression \n");}
| KW_sizeof PUNC_OPBKT type-name PUNC_CLOSEBKT  {printf("\tunary-expression ->  KW_sizeof PUNC_OPBKT type-name PUNC_CLOSEBKT \n");}
	;

unary-operator: OP_AMP  {printf("\tunary-operator ->  OP_AMP \n");}
| OP_STAR  {printf("\tunary-operator ->  OP_STAR \n");}
| OP_PLUS  {printf("\tunary-operator ->  OP_PLUS \n");}
| OP_MINUS  {printf("\tunary-operator ->  OP_MINUS \n");}
| OP_COMP  {printf("\tunary-operator ->  OP_COMP \n");}
| OP_NEGATE  {printf("\tunary-operator ->  OP_NEGATE \n");}
	;

postfix-expression: primary-expression  {printf("\tpostfix-expression ->  primary-expression \n");$$ = $1;}
| postfix-expression PUNC_OPSQRBKT expression PUNC_CLOSESQRBKT  {printf("\tpostfix-expression ->  postfix-expression PUNC_OPSQRBKT expression PUNC_CLOSESQRBKT \n");}
| postfix-expression PUNC_OPBKT argument-expression-list PUNC_CLOSEBKT  {printf("\tpostfix-expression ->  postfix-expression PUNC_OPBKT argument-expression-list PUNC_CLOSEBKT \n");}
| postfix-expression PUNC_OPBKT PUNC_CLOSEBKT  {printf("\tpostfix-expression ->  postfix-expression PUNC_OPBKT PUNC_CLOSEBKT \n");}
| postfix-expression OP_DOT IDENTIFIER  {printf("\tpostfix-expression ->  postfix-expression OP_DOT IDENTIFIER \n");}
| postfix-expression OP_DEREF IDENTIFIER  {printf("\tpostfix-expression ->  postfix-expression OP_DEREF IDENTIFIER \n");}
| postfix-expression OP_INCR  {printf("\tpostfix-expression ->  postfix-expression OP_INCR \n");}
| postfix-expression OP_DECR  {printf("\tpostfix-expression ->  postfix-expression OP_DECR \n");}
	;

primary-expression: IDENTIFIER  {
	printf("\tprimary-expression ->  IDENTIFIER \n");
	if(findSymItem($<strVal>1) == NULL){
		yyerror();
		printf("%s not declared\n", $<strVal>1);
		exit(-1);
		YYERROR;
	}
}
| constant  {printf("\tprimary-expression ->  constant \n");$$ = $1;}
| STRING_CONSTANT  {printf("\tprimary-expression ->  STRING_CONSTANT \n");}
| PUNC_OPBKT expression PUNC_CLOSEBKT  {printf("\tprimary-expression ->  PUNC_OPBKT expression PUNC_CLOSEBKT \n");}
	;

argument-expression-list: assignment-expression  {printf("\targument-expression-list ->  assignment-expression \n");}
| argument-expression-list OP_COMMA assignment-expression  {printf("\targument-expression-list ->  argument-expression-list OP_COMMA assignment-expression \n");}
	;


constant: NUMBER  {
	printf("\tconstant ->  NUMBER \n"); 
	$$ = malloc(sizeof(constVal));
	$$->type = INT;
	$$->value = malloc(sizeof(int));
	*((int *)$$->value) = $<intVal>1;
	$$->intVal = $<intVal>1;
	$$->doubleVal = $$->intVal;
	$$->next = NULL;
}
| CHAR_CONSTANT  {
	printf("\tconstant ->  CHAR_CONSTANT \n"); 
	$$ = malloc(sizeof(constVal));
	$$->type = CHAR;
	$$->value = malloc(sizeof(char));
	*((char *)$$->value) = $<charVal>1;
	$$->intVal = $<charVal>1;
	$$->doubleVal = $$->intVal;
	$$->next = NULL;
}
| REAL_NUMBER  {
	printf("\tconstant ->  REAL_NUMBER \n"); 
	$$ = malloc(sizeof(constVal));
	$$->type = DOUBLE;
	$$->value = malloc(sizeof(double));
	*((double *)$$->value) = $<doubleVal>1;
	$$->doubleVal = $<doubleVal>1;
	$$->intVal = $$->doubleVal;
	$$->next = NULL;
}
| EXP_NUMBER  {
	printf("\tconstant ->  EXP_NUMBER \n"); 
	$$ = malloc(sizeof(constVal));
	$$->type = DOUBLE;
	$$->value = malloc(sizeof(double));
	*((double *)$$->value) = $<doubleVal>1;
	$$->doubleVal = $<doubleVal>1;
	$$->intVal = $$->doubleVal;
	$$->next = NULL;
}
	;


%%
#include "lex.yy.c"

int yyerror()
{
	printf("Error at line %d\n", line_no);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Enter filename to be Compiled\n");
		return -1;
	}
	yyin = fopen(argv[1], "r");
	yyparse();
	printSymTable();
	return 0;
}
