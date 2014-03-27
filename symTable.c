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
	LL *tmp;
	printf("\n***Symbol Table***\n");
	printf("Size: %d\n", symTableSize);
	printf("Line\tID\ttype\tis_array\t(size)\t\tinit_value(s)\n");
	while(curr){
		printf("%d\t%s\t%d\t%d\t\t", curr->line_no, curr->name, curr->type, (curr->arr_dim > 0));
		tmp = curr->dimsHead;
		if(!tmp)printf("0 ");
		for(;tmp;tmp=tmp->next){
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
