#include <stdio.h>
int main(){
	int x;
	printf("辺の長さ: ");
	scanf("%d",&x);

	for(int i=0; i<x; i++){
		for(int n=x; n>=x-i; n--){
			if(n==x)continue;
			putchar(' ');
		}
		for(int n=0; n<x-i; n++){
			putchar('*');
		}
		putchar('\n');
	}

	return 0;
}
