#include <stdio.h>
void printline(char c1,char c2, int len){
	for(int i=0; i<len; i++){
		if(i%2==0){
			printf("%c",c1);
		} else {
			printf("%c",c2);
		}
	}
	puts("");
}
int main(){
	char c1,c2;
	int len;
	scanf("%c %c %d",&c1,&c2,&len);
	printline(c1,c2,len);
	return 0;
}
