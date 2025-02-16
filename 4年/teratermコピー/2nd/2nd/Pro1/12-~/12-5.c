#include <stdio.h>
int main(){
	int x[]={1,3,0,10,50,100,-1};
	int *p;
	int sum=0;
	p=x;
	while(*p>=0){
		sum += *p;
		p++;
	}
	printf("合計: %d\n",sum);
	return 0;
}
