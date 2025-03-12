#include <stdio.h>
int fact(int n){
	int num=1;
	for(int i=1; i<=n; i++){
		num*=i;
	}
	return num;
}

int main(){
	puts("----- n! -----");
	int n;
	while(1){
		puts("0～12の数字を入力してください。");
		printf("input n: ");
		scanf("%d",&n);
		if(n>=0 && n<=12){
			break;
		}
	}
	printf("n! = %15d\n",fact(n));
	return 0;
}
