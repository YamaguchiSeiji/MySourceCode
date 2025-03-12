#include <stdio.h>
int getmax(int *v,int n){
	int max=*v;
	for(int i=0; i<n; i++){
		if(*v>max){
			max=*v;
		}
		v++;
	}
	return max;
}
int main(){
	int v[]={-2,-5,-11,-1};
	printf("%d\n",getmax(v,4));
	printf("%d\n",getmax(v,2));
	return 0;
}
