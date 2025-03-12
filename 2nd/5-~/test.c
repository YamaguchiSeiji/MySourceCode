#include <stdio.h>
int main(){
	int size,num;
	scanf("%d %d",&size,&num);
	for(int i=1; i<=size*num; i++){
		if(i>size+1&&i<size){
			putchar(' ');
		} else {
			putchar('*');
		}
		if(i%size==0){
			putchar(' ');
		}
	}
	return 0;
}
