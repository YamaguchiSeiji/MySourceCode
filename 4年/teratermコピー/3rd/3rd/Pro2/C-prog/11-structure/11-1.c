#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef struct person{
	int no;
	char name[N];
	struct person *next;
} Person;

void print_list();
void insert_head(int, char[]);
void append_tail(int, char[]);
Person *new_node(int no, char name[]);

Person *root = NULL;

int main(){
	Person *ptr;
	int no;
	char name[N];
//	printf("sizeof(Person) = %ld byte\n", sizeof(Person));
/*
	for(int i=0; i<3; i++){
		printf("number :"); scanf("%d", &no);
		printf("name :"); scanf("%s", name);

		insert_head(no, name);
		print_list();
	}
*/
/*
	insert_head(21, "WADA");
	print_list();
	
	insert_head(19, "KAI");
	print_list();

	insert_head(5, "MATSUDA");	
	print_list();
*/
	print_list();

	append_tail(21, "WADA");
	print_list();
	
	append_tail(19, "KAI");
	print_list();

	append_tail(5, "MATSUDA");	
	print_list();
	return 0;
}

void print_list(void){
	for(Person *p=root; p != NULL; p = p->next){
		printf("%2d %-25s\n", p->no, p->name);
	}
	printf("----------------------\n");
}

void insert_head(int no, char name[]){
	Person *ptr;

	ptr = new_node(no, name);

	ptr->next = root;
	root = ptr;
}

void append_tail(int no, char name[]){
	Person *ptr, *p;

	ptr = new_node(no, name);

	if(root == NULL){
		root = ptr;
	} else{
		p = root;

		while(p->next != NULL){
			p = p->next;
		}
		p->next = ptr;
	}
}

Person *new_node(int no, char name[]){
	Person *ptr;
	
	ptr = (Person *) malloc(sizeof(Person));
	ptr->no = no;
	strcpy(ptr->name, name);
	ptr->next = NULL;

	return ptr;
}
