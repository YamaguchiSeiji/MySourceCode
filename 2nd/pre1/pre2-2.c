#include<stdio.h>
#define SIZE 3
int main(){
	int a[SIZE];
	for(int i=0; i<SIZE; i++){
		scanf("%d",&a[i]);
	}
	int max=a[0];
	for(int i=0; i<SIZE; i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	printf("%d\n",max);
	return 0;
}
