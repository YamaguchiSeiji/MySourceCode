#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int tenpower(int n){
	int num=10;
	for(int i=0; i<n-1; i++){
		num*=10;
	}
	return num;
}
void myrand(int num){
	int n,r[10];
	num-=10;
	srand((unsigned)time(NULL));
	for(int i=0; i<10; i++){
		r[i]=rand()%num+10;
		printf("%d ",r[i]);
	}
}

int main(){
	int n;
	printf("Input n: ");
	scanf("%d",&n);
	myrand(tenpower(n));
	puts("");
	return 0;
}
