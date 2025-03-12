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
	int no,num;
	char name[N];
	while(1){
		puts("==========");
		puts("(1) Insert");
		puts("(2) Append");
		puts("(3) Print");
		puts("(4) Exit");
		puts("==========");
		printf("Select a number: "); scanf("%d",&num);
		switch(num){
			case 1:
				printf("Input No.  : "); scanf("%d",&no);
				printf("Input Name : "); scanf("%s", name);
				insert_head(no, name);
				break;
			case 2:
				printf("Input No.  : "); scanf("%d",&no);
				printf("Input Name : "); scanf("%s", name);
				append_tail(no, name);
				break;
			case 3:
				print_list();
				break;
			case 4:
				exit(1);
			default :
				break;
		}
	}
	return 0;
}

void print_list(void){
	printf("----------------------\n");
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

