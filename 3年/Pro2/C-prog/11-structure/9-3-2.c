#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 20

typedef struct person {
	int no;			
	char name[N];	
	struct person *next;	
} Person;

Person *new_node(int no, char name[]);
void print_list(void);
void insert_head(int no, char name[]);
void append_tail(int no, char name[]);
void insert_by_name(int no, char name[]);

Person *root = NULL;

int main(void) {
	Person *ptr;
	int no;
	char name[N];
	FILE *fp;

	fp = fopen("catcher.txt", "r");

	if(fp == NULL){
		puts("file cannot open");
		exit(1);
	} else {
		while(fscanf(fp, "%d %s", &no, name) != EOF){
			insert_by_name(no, name);
		}
	}

	print_list();

	return 0;
}

void print_list(void){

	printf("----------------\n");
	for (Person *p = root; p!=NULL; p= p->next){
		printf("%2d %-25s\n", p->no, p->name);
	}
	printf("----------------\n");
}

void insert_head(int no, char name[]){
	Person *ptr;

	ptr = new_node(no, name);

	ptr->next = root;
	root =ptr;
}

Person *new_node(int no, char name[]) {
	Person *ptr;

	ptr =(Person *) malloc( sizeof(Person));
	ptr->no = no;
	strcpy(ptr->name, name);
	ptr->next = NULL;

	return ptr;
}

void append_tail(int no, char name[]){
	Person *ptr, *p;

	ptr = new_node(no, name);

	if (root == NULL) {	
		root = ptr;
	}
	else {
		p = root;

		while(p->next != NULL){
			p = p->next;
		}
		p->next = ptr;
	}
}

void insert_by_name(int no, char name[]){
	Person *ptr, *p;
	int i = 0;;
	ptr = new_node(no, name);
	while(1){
		if (root == NULL) {	
			root = ptr; 
			break;
		}
		else if (ptr->name[i] < root->name[i]) { 
			ptr->next = root;
			root = ptr; 
			break;
		}
		else {
			for (p=root; p->next != NULL; p=p->next) {
				if (ptr->name[i] < p->next->name[i]) {
					break;	
				}
			}
			ptr->next = p->next; 
			p->next = ptr;
			break;
		}
		i++;
	}
}
