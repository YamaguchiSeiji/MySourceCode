#include <stdio.h>
int main(){
	int size,num;
	printf("大きさは？: "); scanf("%d",&size);
	printf("個数は？: "); scanf("%d",&num);
	
	for(int i=1; i<=size; i++){
		for(int n=1; n<=size*num; n++){
			if(i==1||i==size){
				putchar('*');
				if(n%size==0){
					putchar(' ');
				}
			} else {
			}
		}
		puts(" ");

	}

	return 0;
}
