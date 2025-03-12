#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11

int main(){
	int num[];
	for(int i=0; i<SIZE; i++)
		num[i]=i+1;
	
	int a=0,r;
	srand((unsigned)time(NULL));
	
	for(int i=SIZE-1; i>=0; i--){
		r=rand()%SIZE+1;
		num[SIZE]=num[i];
		num[i]=num[r];
		num[r]=num[SIZE];
	}
	
	for(int i=0; i<SIZE; i++)
		printf("%3d",num[i]);

	puts("");
	return 0;
	
	
}
