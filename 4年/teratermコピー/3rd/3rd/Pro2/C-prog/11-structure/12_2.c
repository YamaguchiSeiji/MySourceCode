#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 20

typedef struct person {
	int no;			// 4 byte
	char name[N];	// 1 byte x 20
	struct person *next;	// 8 byte	
} Person;

Person *new_node(int no, char name[]);
void print_list(void);
void insert_head(int no, char name[]);
void append_tail(int no, char name[]);
void insert_by_no(int no, char name[]);

Person *root = NULL;

int main(void) {
	Person *ptr;
	int no;
	char name[N];


	for (int i=0; i<3; i++) {
		printf("number :"); scanf("%d", &no);
		printf("name :"); scanf("%s", name);

		insert_by_no(no, name);
		print_list();
	}

	return 0;
}

void print_list(void){

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

	if (root == NULL) {	//初期状態(１個目のノードを追加)
		root = ptr;
	}
	else {	//既に１個以上のノードがある場合
		p = root;

		while(p->next != NULL){
			p = p->next;
		}
		p->next = ptr;
	}
}

void insert_by_no(int no, char name[]){
	Person *ptr, *p;

	ptr = new_node(no, name);
	if (root == NULL) {	//リストの先頭に追加
		root = ptr; // ####書きなさい####

	}
	else if (ptr->no < root->no) { //リストの先頭に挿入	
		ptr->next = root;// ####書きなさい####
		root = ptr; // ####書きなさい####
	}
	else {
		for (p=root; p->next != NULL; p=p->next) {
			if (ptr->no < p->next->no) {
				break;	//挿入位置を見つける
			}
		}

		//途中に挿入(または，最後に追加)
		ptr->next = p->next; // ####書きなさい####
		p->next = ptr;// ####書きなさい####
	}
}
