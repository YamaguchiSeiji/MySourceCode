#include <stdio.h>
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	for(int i=x; i<=y; i++){
		printf("%d",i);
		if(i==y)break;
		putchar('-');
	}
	puts("");
	return 0;
}
