#include<stdio.h>
#include<string.h>
#include<malloc.h>
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
	char *inter;
}constVal;

typedef struct LL{
	int val;
	struct LL *next;
}LL;

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
void appendConstValList(constValList *ll, constVal *item){
	if(ll->head == NULL){
		ll->head = ll->tail = item;
		ll->size = 1;
	}else{
		ll->tail->next = item;
		ll->tail = item;
		ll->size++;
	}
	item->next = NULL;
	item->parentLL = ll;
}

typedef struct symItem {
	char *name;
	int type, line_no, size, init;
	int arr_dim;
	int newDec;
	LL *dimsHead, *dimsTail;
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
	ret->dimsHead = NULL;
	ret->dimsTail = NULL;
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
	LL *tmp;int tmpint;
	printf("\n***Symbol Table***\n");
	printf("Size: %d\n", symTableSize);
	printf("Line\tID\ttype\tis_array\t(size)\t\tinit_value(s)\n");
	while(curr){
		printf("%d\t%s\t%d\t%d\t\t", curr->line_no, curr->name, curr->type, (curr->arr_dim > 0));
		tmp = curr->dimsHead;
		if(!tmp && curr->arr_dim)printf("%d ", curr->size);
		else if(!tmp)
			printf("0 ");
		for(tmpint=1;tmp;tmp=tmp->next,tmpint=0){
			if(!tmp->val && tmpint)	// hacky
				tmp->val = curr->size;
			printf("%d ", tmp->val);
		}
		printf("\t\t");
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

typedef struct charLL{
	char str1[20], str2[20];
	struct charLL *next;
}charLL;
charLL *maphead, *maptail;
void appendMap(char *str1, char *str2){
	charLL *item = malloc(sizeof(charLL));
	strcpy(item->str1, str1);
	strcpy(item->str2, str2);
	if(maphead == NULL){
		maphead = maptail = item;
	}else{
		maptail->next = item;
		maptail = item;
	}
	item->next = NULL;
}

char *findMap(char *key){
	charLL *tmp = maphead;
	while(tmp){
		if(strcmp(tmp->str1, key) == 0){
			return tmp->str2;
		}
		tmp = tmp->next;
	}
	return NULL;
}
typedef struct label{
	char str[20];
	struct label *next;
}label;
label *labelStackTop = NULL;
int labelCnt = 1;
label *top(){
	return labelStackTop;
}
void pop(){
	label *tmp = labelStackTop;
	if(tmp == NULL)return;
	labelStackTop = tmp->next;
	free(tmp);
}
char *genLabel(){
	label *new = malloc(sizeof(label));
	sprintf(new->str, "L_%d", labelCnt++);
	new->next = labelStackTop;
	labelStackTop = new;
	return new->str;
}

typedef struct quadItem{
	int op;
	/*
->	 * IF FALSE x, GOTO y	'I' | x | y
->	 * X:	'L' | X
->	 * GOTO y	'G' | y
->	 * x = y	'=' | x | y
	 * x = y op z	op | x | y | z
->	 * 		+, -, *, /, <, >
->	 * op(OR) = 'o'
->	 * op(AND) = 'a'
->	 * op(EQ) = 'e'
->	 * op(NEQ) = 'n'
->	 * op(LTE) = 'l'
->	 * op(GTE) = 'g'
->	 * x = - y	'm' | x | y
	 * x = y[z]	'[' | x | y | z
	 * x[y] = z		']' | x | y | z
	 */
	char args[3][20];
}quadItem;


/* Code Generation */
quadItem *quadTable[10000];
FILE *asmout;
int quadTableSize = 0;
void addQuadItem(int op, char *arg1, char *arg2, char *arg3){
	quadItem *newItem = (quadTable[quadTableSize++] = (quadItem *)malloc(sizeof(quadItem)));
	newItem->op = op;
	//fprintf(stderr, "%c ", op);
	if(arg1)
		strcpy(newItem->args[0], arg1)/*, fprintf(stderr, "| %s", arg1)*/;
	if(arg2)
		strcpy(newItem->args[1], arg2)/*, fprintf(stderr, "| %s", arg2)*/;
	if(arg3)
		strcpy(newItem->args[2], arg3)/*, fprintf(stderr, "| %s", arg3)*/;
	
	if(op == '='){
		int i;
		for(i = 0;newItem->args[0][i];i++){
			if(newItem->args[0][i] == '['){
				newItem->op = ']';
				newItem->args[0][i++] = 0;
				strcpy(newItem->args[2], newItem->args[1]);
				strcpy(newItem->args[1], newItem->args[0]+i);
				while(newItem->args[0][i]!=']')i++;
				newItem->args[0][i] = 0;
				newItem->args[1][strlen(newItem->args[1])-1] = 0;
				//fprintf(stderr, "%c | %s | %s | %s\n", newItem->op, newItem->args[0], newItem->args[1], newItem->args[2]);
				break;
			}
		}
	}
	//fprintf(stderr, "\n");
}

char *toStr(int x){
	char *ret = malloc(20);
	int sz = 0, flag = 0, i;
	if(x<0)x=-x, flag = 1;
	while(x){
		ret[sz++] = '0'+(x%10);
		x/=10;
	}
	if(flag)ret[sz++] = '-';
	ret[sz] = 0;
	for(i = 0;i<=sz/2;i++)
	{
		char tmp = ret[sz-i];
		ret[sz-i] = ret[i];
		ret[i] = tmp;
	}
	return ret;
}
extern int tmpCnt;
void asmSymItems(){
	symItem *curr = symTable;
	LL *tmp;int tmpint;
	//printf("Line\tID\ttype\tis_array\t(size)\t\tinit_value(s)\n");
	while(curr){
		if(curr->type == 0){
			curr = curr->next;
			continue;
		}
		fprintf(asmout, "%s: ", curr->name);
		switch(curr->type){
			case INT: fprintf(asmout, "dd ");
			break;
			case DOUBLE: fprintf(asmout, "dq ");
			break;
			case FLOAT: fprintf(asmout, "dd ");
			break;
			case CHAR: fprintf(asmout, "db ");
			break;
		}
		tmp = curr->dimsHead;
		tmpint = 1;
		if(!tmp && curr->arr_dim)tmpint=curr->size;
		else if(!tmp)tmpint = 1;
		for(;tmp;tmp=tmp->next){
			tmpint *= tmp->val;
		}
		if(curr->init && curr->value){
			if(curr->arr_dim == 0){
				tmpint--;
				switch(curr->type){
					case INT: fprintf(asmout, (tmpint?"%d,":"%d"), curr->val.intVal);
					break;
					case DOUBLE: fprintf(asmout, (tmpint?"%lf,":"%lf"), curr->val.doubleVal);
					break;
					case FLOAT: fprintf(asmout, (tmpint?"%f,":"%f"), curr->val.floatVal);
					break;
					case CHAR: fprintf(asmout, (tmpint?"'%c',":"'%c'"), curr->val.charVal);
					break;
				}
			}else{
				constVal *tmp = curr->value->parentLL->head;
				while(tmp){
					tmpint--;
					switch(curr->type){
						case INT: fprintf(asmout, (tmpint?"%d,":"%d"), tmp->intVal);
						break;
						case DOUBLE: fprintf(asmout, (tmpint?"%f,":"%f"), tmp->doubleVal);
						break;
						case FLOAT: fprintf(asmout, (tmpint?"%f,":"%f"), tmp->doubleVal);
						break;
						case CHAR: fprintf(asmout, (tmpint?"'%c',":"'%c'"), tmp->intVal);
						break;
					}
					tmp = tmp->next;
				}
			}
		}
		while(tmpint){
			tmpint--;
			fprintf(asmout, (tmpint?"0,":"0"));
		}
		fprintf(asmout, "\n");
		curr = curr->next;
	}
}
int isVar(const char *x){
	return ((x[0]>='a' && x[1]<='z') || (x[0]>='A' && x[1]<='Z') || (x[0] == '_'));
}
void asmQuad(){
	int i = 0;
	for(i = 0;i<quadTableSize;i++){
		switch(quadTable[i]->op){
			char *tmpLabel, *tmpLabel2;
			case '=':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case '+':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  add eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  add eax, %s\n", quadTable[i]->args[2]);
			
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case '-':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  sub eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  sub eax, %s\n", quadTable[i]->args[2]);
			
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case '*':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  mov ebx, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  mov ebx, %s\n", quadTable[i]->args[2]);
			fprintf(asmout, "  mul ebx\n");
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case '/':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  mov ebx, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  mov ebx, %s\n", quadTable[i]->args[2]);
			fprintf(asmout, "  div ebx\n");
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case 'a':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  and eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  and eax, %s\n", quadTable[i]->args[2]);
			
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case 'o':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  or eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  or eax, %s\n", quadTable[i]->args[2]);
			
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case 'e':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  cmp eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  cmp eax, %s\n", quadTable[i]->args[2]);
			tmpLabel = genLabel();
			tmpLabel2 = genLabel();
			fprintf(asmout, "  jz %s\n", tmpLabel);
			fprintf(asmout, "  mov eax, 0\n");
			fprintf(asmout, "  jmp %s\n", tmpLabel2);
			fprintf(asmout, "%s:\n  mov eax, 1\n", tmpLabel);
			fprintf(asmout, "%s:\n", tmpLabel2);
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case 'n':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  cmp eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  cmp eax, %s\n", quadTable[i]->args[2]);
			tmpLabel = genLabel();
			tmpLabel2 = genLabel();
			fprintf(asmout, "  jnz %s\n", tmpLabel);
			fprintf(asmout, "  mov eax, 0\n");
			fprintf(asmout, "  jmp %s\n", tmpLabel2);
			fprintf(asmout, "%s:\n  mov eax, 1\n", tmpLabel);
			fprintf(asmout, "%s:\n", tmpLabel2);
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case '<':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  cmp eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  cmp eax, %s\n", quadTable[i]->args[2]);
			tmpLabel = genLabel();
			tmpLabel2 = genLabel();
			fprintf(asmout, "  jl %s\n", tmpLabel);
			fprintf(asmout, "  mov eax, 0\n");
			fprintf(asmout, "  jmp %s\n", tmpLabel2);
			fprintf(asmout, "%s:\n  mov eax, 1\n", tmpLabel);
			fprintf(asmout, "%s:\n", tmpLabel2);
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case '>':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  cmp eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  cmp eax, %s\n", quadTable[i]->args[2]);
			tmpLabel = genLabel();
			tmpLabel2 = genLabel();
			fprintf(asmout, "  jg %s\n", tmpLabel);
			fprintf(asmout, "  mov eax, 0\n");
			fprintf(asmout, "  jmp %s\n", tmpLabel2);
			fprintf(asmout, "%s:\n  mov eax, 1\n", tmpLabel);
			fprintf(asmout, "%s:\n", tmpLabel2);
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case 'l':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  cmp eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  cmp eax, %s\n", quadTable[i]->args[2]);
			tmpLabel = genLabel();
			tmpLabel2 = genLabel();
			fprintf(asmout, "  jle %s\n", tmpLabel);
			fprintf(asmout, "  mov eax, 0\n");
			fprintf(asmout, "  jmp %s\n", tmpLabel2);
			fprintf(asmout, "%s:\n  mov eax, 1\n", tmpLabel);
			fprintf(asmout, "%s:\n", tmpLabel2);
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case 'g':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  cmp eax, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  cmp eax, %s\n", quadTable[i]->args[2]);
			tmpLabel = genLabel();
			tmpLabel2 = genLabel();
			fprintf(asmout, "  jge %s\n", tmpLabel);
			fprintf(asmout, "  mov eax, 0\n");
			fprintf(asmout, "  jmp %s\n", tmpLabel2);
			fprintf(asmout, "%s:\n  mov eax, 1\n", tmpLabel);
			fprintf(asmout, "%s:\n", tmpLabel2);
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case 'm':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			fprintf(asmout, "  neg eax\n");
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case 'L':
			fprintf(asmout, "%s:", quadTable[i]->args[0]);
			break;
			
			case 'G':
			fprintf(asmout, "  jmp %s\n", quadTable[i]->args[0]);
			break;
			
			case 'I':
			if(isVar(quadTable[i]->args[0]))
				fprintf(asmout, "  mov eax, [%s]\n", quadTable[i]->args[0]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[0]);
			fprintf(asmout, "  cmp eax, 0\n");
			fprintf(asmout, "  jz %s\n", quadTable[i]->args[1]);
			break;
			
			case '[':
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  mov ebx, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  mov ebx, %s\n", quadTable[i]->args[2]);
			
			fprintf(asmout, "  mov eax, [eax+ebx]\n");
			fprintf(asmout, "  mov [%s], eax\n", quadTable[i]->args[0]);
			break;
			
			case ']':
			if(isVar(quadTable[i]->args[0]))
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[0]);
			else
				fprintf(asmout, "  mov eax, %s\n", quadTable[i]->args[0]);
			
			if(isVar(quadTable[i]->args[1]))
				fprintf(asmout, "  mov ebx, [%s]\n", quadTable[i]->args[1]);
			else
				fprintf(asmout, "  mov ebx, %s\n", quadTable[i]->args[1]);
			
			if(isVar(quadTable[i]->args[2]))
				fprintf(asmout, "  mov ecx, [%s]\n", quadTable[i]->args[2]);
			else
				fprintf(asmout, "  mov ecx, %s\n", quadTable[i]->args[2]);
			
			fprintf(asmout, "  mov [eax+ebx], ecx\n");
			break;
		}
	}
}
void generate_code(){
	int indent = 2, i;
	//header
	fprintf(asmout, "extern printf\n"
					"SECTION .text\n"
					"global main\n"
					"main:\n"
					"  push ebp\n"
					"  mov ebp, esp\n"
					"  and	esp, -16\n\n");
	
	//Quad
	asmQuad();
	//Res
	fprintf(asmout, "\n  mov eax, [result]\n"
					"  mov [4+esp], eax\n"
					"  mov eax, printtext1\n"
					"  mov [esp], eax\n"
					"  call printf\n\n"
					"  mov eax, [size]\n"
					"  mov [4+esp], eax\n"
					"  mov 	eax, printtext2\n"
					"  mov 	[esp], eax\n"
					"  call printf\n\n"
					"  mov 	eax, printtext3\n"
					"  mov 	[esp], eax\n"
					"  mov	ecx, 0\n"
					"print_a:\n"
					"  cmp	ecx, [size]\n"
					"  jz	exit\n"
					"  mov	eax, [ecx*4 + a]\n"
					"  mov	[4+esp], eax\n"
					"  mov	[temp_count], ecx\n"
					"  call  printf\n"
					"  mov 	ecx, [temp_count]\n"
					"  add	ecx, 1\n"
					"  jmp	print_a\n"
					"exit:\n");
	//Footer
	fprintf(asmout, "  mov esp, ebp\n"
					"  pop ebp\n"
					"  mov eax, 0\n"
					"  ret\n");
	//Symtab
	fprintf(asmout, "\nSECTION .data\n"
					"printtext1: db \"result = %%d\", 10, 0\n"
					"printtext2: db \"size = %%d\", 10, 0\n"
					"printtext3: db \"%%d, \", 0\n"
					"temp_count: dd 0\n\n");
	for(i = 0;i<tmpCnt;i++){
		fprintf(asmout, "t_%d: dd 0\n", i);
	}
	asmSymItems();
}
