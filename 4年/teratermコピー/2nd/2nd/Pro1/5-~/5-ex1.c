#include <stdio.h>
int main(){
	int length;
	while(1){
		printf("大きさを入力してください(奇数のみ): ");
		scanf("%d",&length);
		if(length%2==0){
			puts("値が正しくありません。");
		} else {
			break;
		}
	}

	for(int i=1; i<=length; i++){
		if(i<length/2+1){
			for(int n=1; n<=i; n++)putchar('*');
			for(int n=1; n<=length-2*i; n++)putchar(' ');
			for(int n=1; n<=i; n++)putchar('*');
			putchar('\n');
		}
		if(i==length/2){
			for(int n=0; n<length; n++)putchar('*');
			putchar('\n');
		}
		if(i>length/2){
			for(int n=length; n>i; n--)putchar('*');
			for(int n=0; n<i*2-length; n++)putchar(' ');
			for(int n=length; n>i; n--)putchar('*');
			putchar('\n');
		}
	}
	return 0;

}
