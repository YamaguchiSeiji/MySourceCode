#include <stdio.h>
int main(){
	int len,direc;
	scanf("%d %d",&len,&direc);
	if(direc==0){
		for(int n=0; n<len; n++){
			putchar('*');
		}
		putchar('\n');
	} else {
		for(int n=0; n<len; n++){
			puts("*");
		}
	}
	return 0;
}
