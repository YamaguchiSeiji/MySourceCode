#include <stdio.h>
#define SIZE 5

int getmax(const int z[],int len){
	int max=z[0];
	for(int i=0; i<len; i++){
		if(z[i]>=max){
			max=z[i];
		}
	}
	return max;
}

void twicemax(int v[],int len){
	int max=getmax(v,len);
	for(int i=0; i<len; i++){
		if(v[i]==max){
			v[i]*=2;
		}
	}
}

int main(){
	int a[SIZE]={1,4,10,-9,10};

	twicemax(a,SIZE);
	for(int i=0; i<SIZE; i++){
		printf("%3d",a[i]);
	}
	putchar('\n');
	return 0;
}
