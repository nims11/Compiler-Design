%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symTable.c"
extern int line_no, labelCnt;
FILE *interout;
#define INT 0x1
#define FLOAT 0x2
#define DOUBLE 0x4
#define CHAR 0x8
#define PTR 0x10
#define ARR 0x20
//#define LABEL_TMP_UNIFIED
int tmpCnt = 0;
char *getVar(){
    char *ret = (char*)malloc(20);
    #ifdef LABEL_TMP_UNIFIED
    sprintf(ret, "t_%d", labelCnt++);
    #else
    sprintf(ret, "t_%d", tmpCnt++);
    #endif
    return ret;
}

char *resolveND(char *, constValList *);
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

%type <intVal> type_specifier declaration_specifiers
%type <symPtr> direct_declarator declarator init_declarator init_declarator_list declaration external_declaration
%type <consts> constant primary_expression postfix_expression unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression AND_expression exclusive_OR_expression inclusive_OR_expression logical_OR_expression logical_AND_expression conditional_expression assignment_expression initializer constant_expression expression
%type <constList> initializer_list
%%
translation_unit: external_declaration  {printf("\ttranslation_unit ->  external_declaration \n");}
| translation_unit external_declaration  {printf("\ttranslation_unit ->  translation_unit external_declaration \n");}
        ;

external_declaration: function_definition  {printf("\texternal_declaration ->  function_definition \n");}
| declaration  {printf("\texternal_declaration ->  declaration \n"); $$ = $1;}
        ;

function_definition: declaration_specifiers declarator declaration_list compound_statement  {printf("\tfunction_definition ->  declaration_specifiers declarator declaration_list compound_statement \n");}
| declaration_specifiers declarator compound_statement  {printf("\tfunction_definition ->  declaration_specifiers declarator compound_statement \n");}
| declarator declaration_list compound_statement  {printf("\tfunction_definition ->  declarator declaration_list compound_statement \n");}
| declarator compound_statement  {printf("\tfunction_definition ->  declarator compound_statement \n");}
        ;

declaration: declaration_specifiers init_declarator_list PUNC_SEMICOLON  {
        symItem *tmp = $2;
        printf("\tdeclaration ->  declaration_specifiers init_declarator_list PUNC_SEMICOLON \n");
        $$ = $2;
        while(tmp){
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
| declaration_specifiers PUNC_SEMICOLON  {printf("\tdeclaration ->  declaration_specifiers PUNC_SEMICOLON \n");}
        ;

declaration_list: declaration  {printf("\tdeclaration_list ->  declaration \n");}
| declaration_list declaration  {printf("\tdeclaration_list ->  declaration_list declaration \n");}
        ;

declaration_specifiers: storage_class_specifier declaration_specifiers  {printf("\tdeclaration_specifiers ->  storage_class_specifier declaration_specifiers \n");}
| storage_class_specifier  {printf("\tdeclaration_specifiers ->  storage_class_specifier \n");}
| type_specifier declaration_specifiers  {printf("\tdeclaration_specifiers ->  type_specifier declaration_specifiers \n");}
| type_specifier  {printf("\tdeclaration_specifiers ->  type_specifier \n");$$ = $<intVal>1;}
| type_qualifier declaration_specifiers  {printf("\tdeclaration_specifiers ->  type_qualifier declaration_specifiers \n");}
| type_qualifier  {printf("\tdeclaration_specifiers ->  type_qualifier \n");}
        ;

storage_class_specifier: KW_auto  {printf("\tstorage_class_specifier ->  KW_auto \n");}
| KW_register  {printf("\tstorage_class_specifier ->  KW_register \n");}
| KW_static  {printf("\tstorage_class_specifier ->  KW_static \n");}
| KW_extern  {printf("\tstorage_class_specifier ->  KW_extern \n");}
| KW_typedef  {printf("\tstorage_class_specifier ->  KW_typedef \n");}
        ;

type_specifier: KW_void  {printf("\ttype_specifier ->  KW_void \n");}
| KW_char  {printf("\ttype_specifier ->  KW_char \n"); $$ = $<intVal>1;}
| KW_short  {printf("\ttype_specifier ->  KW_short \n");}
| KW_int  {printf("\ttype_specifier ->  KW_int \n"); $$ = $<intVal>1;}
| KW_long  {printf("\ttype_specifier ->  KW_long \n");}
| KW_float  {printf("\ttype_specifier ->  KW_float \n"); $$ = $<intVal>1;}
| KW_double  {printf("\ttype_specifier ->  KW_double \n"); $$ = $<intVal>1;}
| KW_signed  {printf("\ttype_specifier ->  KW_signed \n");}
| KW_unsigned  {printf("\ttype_specifier ->  KW_unsigned \n");}
| struct_or_union_specifier  {printf("\ttype_specifier ->  struct_or_union_specifier \n");}
| enum_specifier  {printf("\ttype_specifier ->  enum_specifier \n");}
// | typedef_name  {printf("\ttype_specifier ->  | typedef_name \n");}
        ;

type_qualifier: KW_const  {printf("\ttype_qualifier ->  KW_const \n");}
| KW_volatile  {printf("\ttype_qualifier ->  KW_volatile \n");}
        ;

struct_or_union_specifier: struct_or_union IDENTIFIER PUNC_OPBRACE struct_declaration_list PUNC_CLOSEBRACE  {printf("\tstruct_or_union_specifier ->  struct_or_union IDENTIFIER PUNC_OPBRACE struct_declaration_list PUNC_CLOSEBRACE \n");}
| struct_or_union PUNC_OPBRACE struct_declaration_list PUNC_CLOSEBRACE  {printf("\tstruct_or_union_specifier ->  struct_or_union PUNC_OPBRACE struct_declaration_list PUNC_CLOSEBRACE \n");}
| struct_or_union IDENTIFIER  {printf("\tstruct_or_union_specifier ->  struct_or_union IDENTIFIER \n");}
        ;

struct_or_union: KW_struct  {printf("\tstruct_or_union ->  KW_struct \n");}
| KW_union  {printf("\tstruct_or_union ->  KW_union \n");}
        ;

struct_declaration_list: struct_declaration  {printf("\tstruct_declaration_list ->  struct_declaration \n");}
| struct_declaration_list struct_declaration  {printf("\tstruct_declaration_list ->  struct_declaration_list struct_declaration \n");}
        ;

init_declarator_list: init_declarator  {printf("\tinit_declarator_list ->  init_declarator \n"); $$ = $1;}
| init_declarator_list OP_COMMA init_declarator  {
        printf("\tinit_declarator_list ->  init_declarator_list OP_COMMA init_declarator \n");
        $$ = $1;
}
        ;

init_declarator: declarator  {printf("\tinit_declarator ->  declarator \n"); $$ = $1;}
| declarator OP_ASSIGN initializer  {
        printf("\tinit_declarator ->  declarator OP_ASSIGN initializer \n");
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

struct_declaration: specifier_qualifier_list struct_declarator_list PUNC_SEMICOLON  {printf("\tstruct_declaration ->  specifier_qualifier_list struct_declarator_list PUNC_SEMICOLON \n");}
        ;

specifier_qualifier_list: type_specifier specifier_qualifier_list  {printf("\tspecifier_qualifier_list ->  type_specifier specifier_qualifier_list \n");}
| type_specifier  {printf("\tspecifier_qualifier_list ->  type_specifier \n");}
| type_qualifier specifier_qualifier_list  {printf("\tspecifier_qualifier_list ->  type_qualifier specifier_qualifier_list \n");}
| type_qualifier  {printf("\tspecifier_qualifier_list ->  type_qualifier \n");}
        ;

struct_declarator_list: struct_declarator  {printf("\tstruct_declarator_list ->  struct_declarator \n");}
| struct_declarator_list OP_COMMA struct_declarator  {printf("\tstruct_declarator_list ->  struct_declarator_list OP_COMMA struct_declarator \n");}
        ;

struct_declarator: declarator  {printf("\tstruct_declarator ->  declarator \n");}
| declarator PUNC_COLON constant_expression  {printf("\tstruct_declarator ->  declarator PUNC_COLON constant_expression \n");}
| PUNC_COLON constant_expression  {printf("\tstruct_declarator ->  PUNC_COLON constant_expression \n");}
        ;

enum_specifier: KW_enum IDENTIFIER PUNC_OPBRACE enumerator_list PUNC_CLOSEBRACE  {printf("\tenum_specifier ->  KW_enum IDENTIFIER PUNC_OPBRACE enumerator_list PUNC_CLOSEBRACE \n");}
| KW_enum PUNC_OPBRACE enumerator_list PUNC_CLOSEBRACE  {printf("\tenum_specifier ->  KW_enum PUNC_OPBRACE enumerator_list PUNC_CLOSEBRACE \n");}
| KW_enum IDENTIFIER  {printf("\tenum_specifier ->  KW_enum IDENTIFIER \n");}
        ;

enumerator_list: enumerator  {printf("\tenumerator_list ->  enumerator \n");}
| enumerator_list OP_COMMA enumerator  {printf("\tenumerator_list ->  enumerator_list OP_COMMA enumerator \n");}
        ;

enumerator: IDENTIFIER  {printf("\tenumerator ->  IDENTIFIER \n");}
| IDENTIFIER OP_ASSIGN constant_expression  {printf("\tenumerator ->  IDENTIFIER OP_ASSIGN constant_expression \n");}
        ;

declarator: pointer direct_declarator  {printf("\tdeclarator ->  pointer direct_declarator \n");}
| direct_declarator  {printf("\tdeclarator ->  direct_declarator \n"); $$ = $1;}
        ;

direct_declarator: IDENTIFIER  {
        symItem *prev = findSymItem($<strVal>1);
        printf("\tdirect_declarator ->  IDENTIFIER \n");
        if(prev == NULL){
                $$ = addSymItem($<strVal>1);
        }else {
                yyerror();
				printf("Redeclaration of variable %s, previously declared at line %d\n", prev->name, prev->line_no);
				exit(-1);
        }
}
| PUNC_OPBKT declarator PUNC_CLOSEBKT  {printf("\tdirect_declarator ->  PUNC_OPBKT declarator PUNC_CLOSEBKT \n");}
| direct_declarator PUNC_OPSQRBKT constant_expression PUNC_CLOSESQRBKT  {
        printf("\tdirect_declarator ->  direct_declarator PUNC_OPSQRBKT constant_expression PUNC_CLOSESQRBKT \n");
        $$ = $1;
        $$->arr_dim++;
        if(($3->type & INT) || ($3->type & CHAR)){
			int size = *(int*)$3->value;
			if($$->arr_dim == 1){
				$$->size = size;
				$$->dimsHead = $$->dimsTail = malloc(sizeof(LL*));
			}else{
				$$->dimsTail->next = malloc(sizeof(LL*));
				$$->dimsTail = $$->dimsTail->next; $$->dimsTail->next = 0;
			}
			$$->dimsTail->val = size;
		}else{
			yyerror();
			printf("Only Integer values allowed as array index\n");
			exit(-1);
			YYERROR;
		}
}
| direct_declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT  {
        printf("\tdirect_declarator ->  direct_declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT \n");
        $$ = $1;
        $$->arr_dim++;
        $$->size = -2;  // Variable;
}
| direct_declarator PUNC_OPBKT parameter_type_list PUNC_CLOSEBKT  {printf("\tdirect_declarator ->  direct_declarator PUNC_OPBKT parameter_type_list PUNC_CLOSEBKT \n");}
| direct_declarator PUNC_OPBKT identifier_list PUNC_CLOSEBKT  {printf("\tdirect_declarator ->  direct_declarator PUNC_OPBKT identifier_list PUNC_CLOSEBKT \n");}
| direct_declarator PUNC_OPBKT PUNC_CLOSEBKT  {printf("\tdirect_declarator ->  direct_declarator PUNC_OPBKT PUNC_CLOSEBKT \n");}
        ;

pointer: OP_STAR type_qualifier_list  {printf("\tpointer ->  OP_STAR type_qualifier_list \n");}
| OP_STAR  {printf("\tpointer ->  OP_STAR \n");}
| OP_STAR type_qualifier_list pointer  {printf("\tpointer ->  OP_STAR type_qualifier_list pointer \n");}
| OP_STAR pointer  {printf("\tpointer ->  OP_STAR pointer \n");}
        ;

type_qualifier_list: type_qualifier  {printf("\ttype_qualifier_list ->  type_qualifier \n");}
| type_qualifier_list type_qualifier  {printf("\ttype_qualifier_list ->  type_qualifier_list type_qualifier \n");}
        ;

parameter_type_list: parameter_list  {printf("\tparameter_type_list ->  parameter_list \n");}
| parameter_list OP_COMMA OP_ELLIPSIS  {printf("\tparameter_type_list ->  parameter_list OP_COMMA OP_ELLIPSIS \n");}
        ;

parameter_list: parameter_declaration  {printf("\tparameter_list ->  parameter_declaration \n");}
| parameter_list OP_COMMA parameter_declaration  {printf("\tparameter_list ->  parameter_list OP_COMMA parameter_declaration \n");}
        ;

parameter_declaration: declaration_specifiers declarator  {printf("\tparameter_declaration ->  declaration_specifiers declarator \n");}
| declaration_specifiers abstract_declarator  {printf("\tparameter_declaration ->  declaration_specifiers abstract_declarator \n");}
| declaration_specifiers  {printf("\tparameter_declaration ->  declaration_specifiers \n");}
        ;

identifier_list: IDENTIFIER  {printf("\tidentifier_list ->  IDENTIFIER \n");}
| identifier_list OP_COMMA IDENTIFIER  {printf("\tidentifier_list ->  identifier_list OP_COMMA IDENTIFIER \n");}
        ;

initializer: assignment_expression  {printf("\tinitializer ->  assignment_expression \n"); $$ = $1;}
| PUNC_OPBRACE initializer_list PUNC_CLOSEBRACE  {
        printf("\tinitializer ->  PUNC_OPBRACE initializer_list PUNC_CLOSEBRACE \n");
        $$ = $2->head;
}
| PUNC_OPBRACE initializer_list OP_COMMA PUNC_CLOSEBRACE  {printf("\tinitializer ->  PUNC_OPBRACE initializer_list OP_COMMA PUNC_CLOSEBRACE \n");}
        ;

initializer_list: initializer  {
        printf("\tinitializer_list ->  initializer \n");
        $$ = newConstValList();
        $$->size = 1;
        $$->head = $$->tail = $1;
        $1->parentLL = $$;
}
| initializer_list OP_COMMA initializer  {
        printf("\tinitializer_list ->  initializer_list OP_COMMA initializer \n");
        $$ = $1;
        $$->size++;
        $$->tail->next = $3;
        $$->tail = $3;
        $3->parentLL = $$;
}
        ;

type_name: specifier_qualifier_list abstract_declarator  {printf("\ttype_name ->  specifier_qualifier_list abstract_declarator \n");}
| specifier_qualifier_list  {printf("\ttype_name ->  specifier_qualifier_list \n");}
        ;

abstract_declarator: pointer  {printf("\tabstract_declarator ->  pointer \n");}
| pointer direct_abstract_declarator  {printf("\tabstract_declarator ->  pointer direct_abstract_declarator \n");}
| direct_abstract_declarator  {printf("\tabstract_declarator ->  direct_abstract_declarator \n");}
        ;

direct_abstract_declarator: PUNC_OPBKT abstract_declarator PUNC_CLOSEBKT  {printf("\tdirect_abstract_declarator ->  PUNC_OPBKT abstract_declarator PUNC_CLOSEBKT \n");}
| direct_abstract_declarator PUNC_OPSQRBKT constant_expression PUNC_CLOSESQRBKT  {printf("\tdirect_abstract_declarator ->  direct_abstract_declarator PUNC_OPSQRBKT constant_expression PUNC_CLOSESQRBKT \n");}
| direct_abstract_declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT  {printf("\tdirect_abstract_declarator ->  direct_abstract_declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT \n");}
| PUNC_OPSQRBKT constant_expression PUNC_CLOSESQRBKT  {printf("\tdirect_abstract_declarator ->  PUNC_OPSQRBKT constant_expression PUNC_CLOSESQRBKT \n");}
| PUNC_OPSQRBKT PUNC_CLOSESQRBKT  {printf("\tdirect_abstract_declarator ->  PUNC_OPSQRBKT PUNC_CLOSESQRBKT \n");}
| direct_abstract_declarator PUNC_OPBKT parameter_type_list PUNC_CLOSEBKT  {printf("\tdirect_abstract_declarator ->  direct_abstract_declarator PUNC_OPBKT parameter_type_list PUNC_CLOSEBKT \n");}
| direct_abstract_declarator PUNC_OPBKT PUNC_CLOSEBKT  {printf("\tdirect_abstract_declarator ->  direct_abstract_declarator PUNC_OPBKT PUNC_CLOSEBKT \n");}
| PUNC_OPBKT parameter_type_list PUNC_CLOSEBKT  {printf("\tdirect_abstract_declarator ->  PUNC_OPBKT parameter_type_list PUNC_CLOSEBKT \n");}
| PUNC_OPBKT PUNC_CLOSEBKT  {printf("\tdirect_abstract_declarator ->  PUNC_OPBKT PUNC_CLOSEBKT \n");}
        ;


statement: labeled_statement  {printf("\tstatement ->  labeled_statement \n");}
| expression_statement  {printf("\tstatement ->  expression_statement \n");}
| compound_statement  {printf("\tstatement ->  compound_statement \n");}
| selection_statement  {printf("\tstatement ->  selection_statement \n");}
| iteration_statement  {printf("\tstatement ->  iteration_statement \n");}
| jump_statement  {printf("\tstatement ->  jump_statement \n");}
        ;

labeled_statement: IDENTIFIER PUNC_COLON statement  {printf("\tlabeled_statement ->  IDENTIFIER PUNC_COLON statement \n");}
| KW_case constant_expression PUNC_COLON statement  {printf("\tlabeled_statement ->  KW_case constant_expression PUNC_COLON statement \n");}
| KW_default PUNC_COLON statement  {printf("\tlabeled_statement ->  KW_default PUNC_COLON statement \n");}
        ;

expression_statement: expression PUNC_SEMICOLON  {printf("\texpression_statement ->  expression PUNC_SEMICOLON \n");}
| PUNC_SEMICOLON  {printf("\texpression_statement ->  PUNC_SEMICOLON \n");}
        ;

compound_statement: PUNC_OPBRACE declaration_list statement_list PUNC_CLOSEBRACE  {printf("\tcompound_statement ->  PUNC_OPBRACE declaration_list statement_list PUNC_CLOSEBRACE \n");}
| PUNC_OPBRACE statement_list PUNC_CLOSEBRACE  {printf("\tcompound_statement ->  PUNC_OPBRACE statement_list PUNC_CLOSEBRACE \n");}
| PUNC_OPBRACE declaration_list PUNC_CLOSEBRACE  {printf("\tcompound_statement ->  PUNC_OPBRACE declaration_list PUNC_CLOSEBRACE \n");}
| PUNC_OPBRACE PUNC_CLOSEBRACE  {printf("\tcompound_statement ->  PUNC_OPBRACE PUNC_CLOSEBRACE \n");}
        ;

statement_list: statement  {printf("\tstatement_list ->  statement \n");}
| statement_list statement  {printf("\tstatement_list ->  statement_list statement \n");}
        ;

if_start: KW_if PUNC_OPBKT expression PUNC_CLOSEBKT 
{
	genLabel();
	fprintf(interout, "IF FALSE %s, GOTO %s\n", $3->inter, top()->str);
	addQuadItem('I', $3->inter, top()->str, 0);
}
		;
		
selection_statement: if_start statement  {
	printf("\tselection_statement ->  KW_if PUNC_OPBKT expression PUNC_CLOSEBKT statement \n");
	fprintf(interout, "%s:\n", top()->str);
	addQuadItem('L', top()->str, 0, 0);
	pop();
}
| if_start statement KW_else
{
	char prev[20];
	strcpy(prev, top()->str);
	pop();
	genLabel();
	fprintf(interout, "GOTO %s\n", top()->str);
	addQuadItem('G', top()->str, 0, 0);
	fprintf(interout, "%s:\n", prev);
	addQuadItem('L', prev, 0, 0);
} statement  {
	printf("\tselection_statement ->  KW_if PUNC_OPBKT expression PUNC_CLOSEBKT statement KW_else statement \n");
	fprintf(interout, "%s:\n", top()->str);
	addQuadItem('L', top()->str, 0, 0);
	pop();
}
| KW_switch PUNC_OPBKT expression PUNC_CLOSEBKT statement  {printf("\tselection_statement ->  KW_switch PUNC_OPBKT expression PUNC_CLOSEBKT statement \n");}
        ;

iteration_statement: KW_while
{
	genLabel();
	fprintf(interout, "%s:\n", top()->str);
	addQuadItem('L', top()->str, 0, 0);
} PUNC_OPBKT expression PUNC_CLOSEBKT
{
	genLabel();
	fprintf(interout, "IF FALSE %s, GOTO %s\n", $4->inter, top()->str);
	addQuadItem('I', $4->inter, top()->str, 0);
} statement  {
	printf("\titeration_statement ->  KW_while PUNC_OPBKT expression PUNC_CLOSEBKT statement \n");
	fprintf(interout, "GOTO %s\n", top()->next->str);addQuadItem('G', top()->next->str, 0, 0);
	fprintf(interout, "%s:\n", top()->str);addQuadItem('L', top()->str, 0, 0);
	pop();
	pop();
}
| KW_do statement KW_while PUNC_OPBKT expression PUNC_CLOSEBKT PUNC_SEMICOLON  {printf("\titeration_statement ->  KW_do statement KW_while PUNC_OPBKT expression PUNC_CLOSEBKT PUNC_SEMICOLON \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement  {printf("\titeration_statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement  {printf("\titeration_statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement  {printf("\titeration_statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement  {printf("\titeration_statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement  {printf("\titeration_statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement  {printf("\titeration_statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement  {printf("\titeration_statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
| KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement  {printf("\titeration_statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
        ;

jump_statement: KW_goto IDENTIFIER PUNC_SEMICOLON  {printf("\tjump_statement ->  KW_goto IDENTIFIER PUNC_SEMICOLON \n");}
| KW_continue PUNC_SEMICOLON  {printf("\tjump_statement ->  KW_continue PUNC_SEMICOLON \n");}
| KW_break PUNC_SEMICOLON  {printf("\tjump_statement ->  KW_break PUNC_SEMICOLON \n");}
| KW_return expression PUNC_SEMICOLON  {printf("\tjump_statement ->  KW_return expression PUNC_SEMICOLON \n");}
| KW_return PUNC_SEMICOLON  {printf("\tjump_statement ->  KW_return PUNC_SEMICOLON \n");}
        ;

expression: assignment_expression  {printf("\texpression ->  assignment_expression \n");$$=$1;}
| expression OP_COMMA assignment_expression  {printf("\texpression ->  expression OP_COMMA assignment_expression \n");}
        ;

assignment_expression: conditional_expression  {printf("\tassignment_expression ->  conditional_expression \n"); $$ = $1;}
| unary_expression assignment_operator assignment_expression  {
	char *inter2;
	printf("\tassignment_expression ->  unary_expression assignment_operator assignment_expression \n");
	if((inter2 = findMap($1->inter)) != NULL){
		$1->inter = inter2;
	}
    switch($<intVal>2){
        case OP_ASSIGN:
        fprintf(interout, "%s = %s\n", $1->inter, $3->inter);addQuadItem('=', $1->inter, $3->inter, 0);
        break;
        case OP_PLUSEQ:
        fprintf(interout, "%s = %s + %s\n", $1->inter, $1->inter, $3->inter);addQuadItem('+', $1->inter, $1->inter, $3->inter);
        break;
        case OP_MINUSEQ:
        fprintf(interout, "%s = %s - %s\n", $1->inter, $1->inter, $3->inter);addQuadItem('-', $1->inter, $1->inter, $3->inter);
        break;
        case OP_MULEQ:
        fprintf(interout, "%s = %s * %s\n", $1->inter, $1->inter, $3->inter);addQuadItem('*', $1->inter, $1->inter, $3->inter);
        break;
        case OP_DIVEQ:
        fprintf(interout, "%s = %s / %s\n", $1->inter, $1->inter, $3->inter);addQuadItem('/', $1->inter, $1->inter, $3->inter);
        break;
    }
    $$ = $1;
}
        ;

assignment_operator: OP_ASSIGN  {printf("\tassignment_operator ->  OP_ASSIGN \n");$<intVal>$ = OP_ASSIGN;}
| OP_MULEQ  {printf("\tassignment_operator ->  OP_MULEQ \n");$<intVal>$ = OP_MULEQ;}
| OP_DIVEQ  {printf("\tassignment_operator ->  OP_DIVEQ \n");$<intVal>$ = OP_DIVEQ;}
| OP_MODEQ  {printf("\tassignment_operator ->  OP_MODEQ \n");$<intVal>$ = OP_MODEQ;}
| OP_PLUSEQ  {printf("\tassignment_operator ->  OP_PLUSEQ \n");$<intVal>$ = OP_PLUSEQ;}
| OP_MINUSEQ  {printf("\tassignment_operator ->  OP_MINUSEQ \n");$<intVal>$ = OP_MINUSEQ;}
| OP_LSHIFTEQ  {printf("\tassignment_operator ->  OP_LSHIFTEQ \n");$<intVal>$ = OP_LSHIFTEQ;}
| OP_RSHIFTEQ  {printf("\tassignment_operator ->  OP_RSHIFTEQ \n");$<intVal>$ = OP_RSHIFTEQ;}
| OP_ANDEQ  {printf("\tassignment_operator ->  OP_ANDEQ \n");$<intVal>$ = OP_ANDEQ;}
| OP_XOREQ  {printf("\tassignment_operator ->  OP_XOREQ \n");$<intVal>$ = OP_XOREQ;}
| OP_OREQ  {printf("\tassignment_operator ->  OP_OREQ \n");$<intVal>$ = OP_OREQ;}
        ;

conditional_expression: logical_OR_expression  {printf("\tconditional_expression ->  logical_OR_expression \n"); $$ = $1;}
| logical_OR_expression OP_QUES expression PUNC_COLON conditional_expression  {printf("\tconditional_expression ->  logical_OR_expression OP_QUES expression PUNC_COLON conditional_expression \n");}
        ;

constant_expression: conditional_expression  {printf("\tconstant_expression ->  conditional_expression \n"); $$ = $1;}
        ;

logical_OR_expression: logical_AND_expression  {printf("\tlogical_OR_expression ->  logical_AND_expression \n"); $$ = $1;}
| logical_OR_expression OP_LOGOR logical_AND_expression  {
	printf("\tlogical_OR_expression ->  logical_OR_expression OP_LOGOR logical_AND_expression \n");
	char *tmp = getVar();
    fprintf(interout, "%s = %s OR %s\n", tmp, $1->inter, $3->inter);addQuadItem('o', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
}
        ;

logical_AND_expression: inclusive_OR_expression  {printf("\tlogical_AND_expression ->  inclusive_OR_expression \n"); $$ = $1;}
| logical_AND_expression OP_LOGAND inclusive_OR_expression  {
	printf("\tlogical_AND_expression ->  logical_AND_expression OP_LOGAND inclusive_OR_expression \n");
	char *tmp = getVar();
    fprintf(interout, "%s = %s AND %s\n", tmp, $1->inter, $3->inter);addQuadItem('a', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
}
        ;

inclusive_OR_expression: exclusive_OR_expression  {printf("\tinclusive_OR_expression ->  exclusive_OR_expression \n"); $$ = $1;}
| inclusive_OR_expression OP_BITOR exclusive_OR_expression  {printf("\tinclusive_OR_expression ->  inclusive_OR_expression OP_BITOR exclusive_OR_expression \n");}

exclusive_OR_expression: AND_expression  {printf("\texclusive_OR_expression ->  AND_expression \n"); $$ = $1;}
| exclusive_OR_expression OP_BITXOR AND_expression  {printf("\texclusive_OR_expression ->  exclusive_OR_expression OP_BITXOR AND_expression \n");}
        ;

AND_expression: equality_expression  {printf("\tAND_expression ->  equality_expression \n"); $$ = $1;}
| AND_expression OP_AMP equality_expression  {printf("\tAND_expression ->  AND_expression OP_AMP equality_expression \n");}
        ;

equality_expression: relational_expression  {printf("\tequality_expression ->  relational_expression \n"); $$ = $1;}
| equality_expression OP_EQ relational_expression  {
	printf("\tequality_expression ->  equality_expression OP_EQ relational_expression \n");
	char *tmp = getVar();
    fprintf(interout, "%s = %s EQ %s\n", tmp, $1->inter, $3->inter);addQuadItem('e', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
}
| equality_expression OP_NEQ relational_expression  {
	printf("\tequality_expression ->  equality_expression OP_NEQ relational_expression \n");
	char *tmp = getVar();
    fprintf(interout, "%s = %s NEQ %s\n", tmp, $1->inter, $3->inter);addQuadItem('n', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
}
        ;

relational_expression: shift_expression  {printf("\trelational_expression ->  shift_expression \n"); $$ = $1;}
| relational_expression OP_LT shift_expression  {
	printf("\trelational_expression ->  relational_expression OP_LT shift_expression \n");
	char *tmp = getVar();
    fprintf(interout, "%s = %s LT %s\n", tmp, $1->inter, $3->inter);addQuadItem('<', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
}
| relational_expression OP_GT shift_expression  {
	printf("\trelational_expression ->  relational_expression OP_GT shift_expression \n");
	char *tmp = getVar();
    fprintf(interout, "%s = %s GT %s\n", tmp, $1->inter, $3->inter);addQuadItem('>', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
}
| relational_expression OP_LTE shift_expression  {
	printf("\trelational_expression ->  relational_expression OP_LTE shift_expression \n");
	char *tmp = getVar();
    fprintf(interout, "%s = %s LTE %s\n", tmp, $1->inter, $3->inter);addQuadItem('l', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
}
| relational_expression OP_GTE shift_expression  {
	printf("\trelational_expression ->  relational_expression OP_GTE shift_expression \n");
	char *tmp = getVar();
    fprintf(interout, "%s = %s GTE %s\n", tmp, $1->inter, $3->inter);addQuadItem('g', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
}
        ;

shift_expression: additive_expression  {printf("\tshift_expression ->  additive_expression \n"); $$ = $1;}
| shift_expression OP_LSHIFT additive_expression  {printf("\tshift_expression ->  shift_expression OP_LSHIFT additive_expression \n");}
| shift_expression OP_RSHIFT additive_expression  {printf("\tshift_expression ->  shift_expression OP_RSHIFT additive_expression \n");}
        ;

additive_expression: multiplicative_expression  {printf("\tadditive_expression ->  multiplicative_expression \n"); $$ = $1;}
| additive_expression OP_PLUS multiplicative_expression  {
    char *tmp = getVar();
    fprintf(interout, "%s = %s + %s\n", tmp, $1->inter, $3->inter);addQuadItem('+', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
    printf("\tadditive_expression ->  additive_expression OP_PLUS multiplicative_expression \n");
}
| additive_expression OP_MINUS multiplicative_expression  {
    char *tmp = getVar();
    fprintf(interout, "%s = %s - %s\n", tmp, $1->inter, $3->inter);addQuadItem('-', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
    printf("\tadditive_expression ->  additive_expression OP_MINUS multiplicative_expression \n");
}
        ;

multiplicative_expression: cast_expression  {printf("\tmultiplicative_expression ->  cast_expression \n"); $$ = $1;}
| multiplicative_expression OP_STAR cast_expression  {
    char *tmp = getVar();
    printf("\tmultiplicative_expression ->  multiplicative_expression OP_STAR cast_expression \n");
    $$ = $1;
    fprintf(interout, "%s = %s * %s\n", tmp, $1->inter, $3->inter);addQuadItem('*', tmp, $1->inter, $3->inter);
    $$->inter = tmp;
}
| multiplicative_expression OP_DIV cast_expression  {
    char *tmp = getVar();
    fprintf(interout, "%s = %s / %s\n", tmp, $1->inter, $3->inter);addQuadItem('/', tmp, $1->inter, $3->inter);
    $$ = $1;
    $$->inter = tmp;
    printf("\tmultiplicative_expression ->  multiplicative_expression OP_DIV cast_expression \n");
}
| multiplicative_expression OP_MOD cast_expression  {printf("\tmultiplicative_expression ->  multiplicative_expression OP_MOD cast_expression \n");}
        ;

cast_expression: unary_expression  {printf("\tcast_expression ->  unary_expression \n"); $$ = $1;}
| PUNC_OPBKT type_name PUNC_CLOSEBKT cast_expression  {printf("\tcast_expression ->  PUNC_OPBKT type_name PUNC_CLOSEBKT cast_expression \n");}
        ;

unary_expression: postfix_expression  {
	printf("\tunary_expression ->  postfix_expression \n"); $$ = $1;
	if($$->parentLL != NULL){
		yyerror();
		printf("Array Dimension mismatch!\n");
		exit(-1);
		YYERROR;
	}
}
| OP_INCR unary_expression  {
    char *tmp = getVar();
    fprintf(interout, "%s = %s + 1\n", $2->inter, $2->inter);addQuadItem('+', $2->inter, $2->inter, "1");
    $$ = $2;
    printf("\tunary_expression ->  OP_INCR unary_expression \n");
}
| OP_DECR unary_expression  {
    char *tmp = getVar();
    fprintf(interout, "%s = %s - 1\n", $2->inter, $2->inter);addQuadItem('-', $2->inter, $2->inter, "1");
    $$ = $2;
    printf("\tunary_expression ->  OP_DECR unary_expression \n");
}
| unary_operator cast_expression  {
    if($<intVal>1 == 1){
        char *tmp = getVar();
        fprintf(interout, "%s = -%s\n", tmp, $2->inter);addQuadItem('m', tmp, $2->inter, 0);
        $$ = $2;
        $$->inter = tmp;
    }else
        $$ = $2;
    printf("\tunary_expression ->  unary_operator cast_expression \n");
}
| KW_sizeof unary_expression  {printf("\tunary_expression ->  KW_sizeof unary_expression \n");}
| KW_sizeof PUNC_OPBKT type_name PUNC_CLOSEBKT  {printf("\tunary_expression ->  KW_sizeof PUNC_OPBKT type_name PUNC_CLOSEBKT \n");}
        ;

unary_operator: OP_AMP  {printf("\tunary_operator ->  OP_AMP \n");$<intVal>$ = -1;}
| OP_STAR  {printf("\tunary_operator ->  OP_STAR \n");$<intVal>$ = -1;}
| OP_PLUS  {printf("\tunary_operator ->  OP_PLUS \n");$<intVal>$ = -1;}
| OP_MINUS  {printf("\tunary_operator ->  OP_MINUS \n");$<intVal>$ = 1;}
| OP_COMP  {printf("\tunary_operator ->  OP_COMP \n");$<intVal>$ = -1;}
| OP_NEGATE  {printf("\tunary_operator ->  OP_NEGATE \n");$<intVal>$ = -1;}
        ;

postfix_expression: primary_expression  {printf("\tpostfix_expression ->  primary_expression \n");$$ = $1;}
| postfix_expression PUNC_OPSQRBKT expression PUNC_CLOSESQRBKT  {
	symItem *arr_ref = findSymItem($1->inter);
	if(arr_ref == NULL){
		if(findMap($1->inter) != NULL){
			yyerror();
			printf("Array Dimension mismatch!\n");
			exit(-1);
		}
	}
	printf("\tpostfix_expression ->  postfix_expression PUNC_OPSQRBKT expression PUNC_CLOSESQRBKT \n");
	appendConstValList($1->parentLL, $3);
	$$ = $1;
	//fprintf(stderr, "%s %s %d %d\n", $1->inter, $3->inter, arr_ref->arr_dim, $$->parentLL->size);
	if($$->parentLL->size == arr_ref->arr_dim){
		$$->inter = resolveND($1->inter, $$->parentLL);
		$$->parentLL = NULL;
	}
}
| postfix_expression PUNC_OPBKT argument_expression_list PUNC_CLOSEBKT  {printf("\tpostfix_expression ->  postfix_expression PUNC_OPBKT argument_expression_list PUNC_CLOSEBKT \n");}
| postfix_expression PUNC_OPBKT PUNC_CLOSEBKT  {printf("\tpostfix_expression ->  postfix_expression PUNC_OPBKT PUNC_CLOSEBKT \n");}
| postfix_expression OP_DOT IDENTIFIER  {printf("\tpostfix_expression ->  postfix_expression OP_DOT IDENTIFIER \n");}
| postfix_expression OP_DEREF IDENTIFIER  {printf("\tpostfix_expression ->  postfix_expression OP_DEREF IDENTIFIER \n");}
| postfix_expression OP_INCR  {
    char *tmp = getVar();
    fprintf(interout, "%s = %s\n", tmp, $1->inter);addQuadItem('=', tmp, $1->inter, 0);
    fprintf(interout, "%s = %s + 1\n", $1->inter, $1->inter);addQuadItem('+', $1->inter, $1->inter, "1");
    $$ = $1;
    $$->inter = tmp;
    printf("\tpostfix_expression ->  postfix_expression OP_INCR \n");
}
| postfix_expression OP_DECR  {
    char *tmp = getVar();
    fprintf(interout, "%s = %s\n", tmp, $1->inter);addQuadItem('=', tmp, $1->inter, 0);
    fprintf(interout, "%s = %s - 1\n", $1->inter, $1->inter);addQuadItem('-', $1->inter, $1->inter, "1");
    $$ = $1;
    $$->inter = tmp;
    printf("\tpostfix_expression ->  postfix_expression OP_DECR \n");
}
        ;

primary_expression: IDENTIFIER  {
		symItem *ref;
        printf("\tprimary_expression ->  IDENTIFIER \n");
        if((ref = findSymItem($<strVal>1)) == NULL){
                yyerror();
                printf("%s not declared\n", $<strVal>1);
                exit(-1);
                YYERROR;
        }
        $$ = malloc(sizeof(constVal));
        $$->parentLL == NULL;
        $$->inter = malloc(20);
        strcpy($$->inter, $<strVal>1);
        if(ref->arr_dim != 0){	// arr name ref
			$$->parentLL = newConstValList();
		}
}
| constant  {printf("\tprimary_expression ->  constant \n");$$ = $1;}
| STRING_CONSTANT  {printf("\tprimary_expression ->  STRING_CONSTANT \n");}
| PUNC_OPBKT expression PUNC_CLOSEBKT  {
    $$ = $2;
    printf("\tprimary_expression ->  PUNC_OPBKT expression PUNC_CLOSEBKT \n");
}
        ;

argument_expression_list: assignment_expression  {printf("\targument_expression_list ->  assignment_expression \n");}
| argument_expression_list OP_COMMA assignment_expression  {printf("\targument_expression_list ->  argument_expression_list OP_COMMA assignment_expression \n");}
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
        $$->inter = malloc(20);
        $$->parentLL == NULL;
        sprintf($$->inter, "%lld", $$->intVal);
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
        $$->inter = malloc(20);
        $$->inter[0] = $$->intVal;
        $$->inter[1] = 0;
        $$->parentLL == NULL;
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
        $$->inter = malloc(20);
        $$->parentLL == NULL;
        sprintf($$->inter, "%lf", $$->doubleVal);
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
        $$->inter = malloc(20);
        sprintf($$->inter, "%lf", $$->doubleVal);
}
        ;


%%
#include "lex.yy.c"

int yyerror()
{
        printf("Error at line %d\n", line_no);
}
char *getans(int maxdims[], char *dim[], int dims, int idx, int maxdimSize){
	int max_col=1;
	int i;
	char *ret = getVar();
	char *nxt;
	fprintf(interout, "%s = 1\n", ret);addQuadItem('=', ret, "1", 0);
	
	//if(idx >= dims)return 0;
	for(i=idx+1;i<maxdimSize;i++){
		max_col *= maxdims[i];
		fprintf(interout, "%s = %s * %d\n", ret, ret, maxdims[i]);addQuadItem('*', ret, ret, toStr(maxdims[i]));
	}
	fprintf(interout, "%s = %s * %s\n", ret, dim[idx], ret);addQuadItem('*', ret, dim[idx], ret);
	if(idx ==dims-1){
		//return dim[idx]*max_col;
		return ret;
	}
	//printf("%d %d\n", idx, max_col);
	nxt = getans(maxdims, dim, dims, idx+1, maxdimSize);
	fprintf(interout, "%s = %s + %s\n", ret, ret, nxt);addQuadItem('+', ret, ret, nxt);
	return ret;
	//return max_col*dim[idx]+getans(maxdims, dim, dims, idx+1, maxdimSize);
}
char *post(char *arrname, constValList *ll){
	int dims;int i;
	char *dim[50];int max_dims[50];
	char *res;
	LL *sizes;
	symItem *it;
	constVal *tmp;
	char *ret;
	it=findSymItem(arrname);
	//if(!(it=findSymItem(arrname))){
	//	printf("Cannot find arrname\n");
	//	return;
	//}
	sizes = it->dimsHead;
	for(i=0;sizes;i++, sizes=sizes->next){
		max_dims[i] = sizes->val;
	}
	for(i=0,tmp=ll->head;i<ll->size;i++, tmp=tmp->next){
		dim[i] = tmp->inter;
	}
	dims = it->arr_dim;
	//printf("No. of dim: ");scanf("%d", &dims);
	//if(dims!=it->arr_dim){
	//	printf("Dimension doesn't match\n");
	//	return;
	//}
	//printf("elts : ");
	//for(i = 0;i<dims;i++){
	//	scanf("%d", &dim[i]);
	//}
	res = getans(max_dims, dim, dims, 0, it->arr_dim);
	switch(it->type){
		case INT:
			ret = getVar();
			fprintf(interout, "%s = %s * 4\n", ret, res);addQuadItem('*', ret, res, "4");
		break;
		case DOUBLE:
			ret = getVar();
			fprintf(interout, "%s = %s * 8\n", ret, res);addQuadItem('*', ret, res, "8");
		break;
		case FLOAT:
			ret = getVar();
			fprintf(interout, "%s = %s * 4\n", ret, res);addQuadItem('*', ret, res, "4");
		break;
		case CHAR:
			ret = getVar();
			fprintf(interout, "%s = %s\n", ret, res);addQuadItem('=', ret, res, 0);
		break;
	}
	//printf("%d\n", res);
	return ret;
}
char *resolveND(char *arr, constValList *ll){
	constVal *tmp = ll->head;
	char *ret = malloc(20), *idx, arrSub[20];
	int i;
	//fprintf(stderr, "%s ", arr);
	//while(tmp){
	//	fprintf(stderr, "%s ", tmp->inter);
	//	tmp = tmp->next;
	//}
	//fprintf(stderr, "\n");
	ret = getVar();
	idx = post(arr, ll);
	fprintf(interout, "%s = %s[%s]\n", ret, arr, idx); addQuadItem('[', ret, arr, idx);
	sprintf(arrSub, "%s[%s]", arr, idx);
	appendMap(ret, arrSub);
	return ret;
}
int main(int argc, char *argv[])
{
        if (argc != 4)
        {
                printf("./a.out inp.c out.i out.s\n");
                return -1;
        }
        yyin = fopen(argv[1], "r");
        interout = fopen(argv[2], "w");
        asmout = fopen(argv[3], "w");
        yyparse();
        printSymTable();
        generate_code();
        return 0;
}
