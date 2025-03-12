#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 9

int main(){
	int num[SIZE+1];
	int ans;
	for(int i=0; i<SIZE; i++)
		num[i]=i+1;
	
	int a=0,r;
	srand((unsigned)time(NULL));
	
	for(int i=SIZE-1; i>=0; i--){
		r=rand()%8+1;
		num[SIZE]=num[i];
		num[i]=num[r];
		num[r]=num[SIZE];
	}
	
	for(int i=1; i<SIZE; i++){
		printf("%3d",num[i]);
	}
	puts("");
	
	puts("欠けている数字はどれ？:");
	scanf("%d",&ans);
	if(ans==num[0])
		puts("正解！");
	else 
		puts("不正解");
	
	return 0;
	
	
}
