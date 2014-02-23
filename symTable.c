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
