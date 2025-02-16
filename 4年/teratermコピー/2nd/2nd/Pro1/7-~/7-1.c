#include <stdio.h>
#define SIZE 9
int main(){
	int a[SIZE];
	for(int i=0; i<SIZE; i++){
		a[i]=i+1;
	}

	for(int i=0; i<SIZE; i++){
		printf("%3d",a[i]);
	}
	puts("");
	return 0;
}
