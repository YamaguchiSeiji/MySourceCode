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
	FILE *fp;
	int i=0;

	if((fp = fopen("catcher.txt", "r")) == NULL){
		puts("file open error");
		exit(1);
	} else {
		fscanf("%d %s", &no, name);
		insert_head(no, name);
		for(Person *p = root; p!=NULL; p = p->next){
			i=0;
			fscanf("%d %s", &no, name);
			while(1){
				if(p->name[i] < name[i]){
					append_tail(no, name);
					break;
				} else if(p->name[i] > name[i]){
					insert_tail(no, name);
					break;
				} else {
					i++;
				}
			}
		}
	}
	

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

void insert_by_no(int no, char name[]){
	Person *ptr;

	ptr

}
