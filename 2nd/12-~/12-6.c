#include <stdio.h>
double calcavg(int *v, int n){
	double ave=0;
	for(int i=0; i<n; i++){
		ave+= *v;
		v++;
	}
	return ave/n;
}
int main(){
	int x[]={10,8,11,20};
	printf("%.2f\n",calcavg(x,4));
	printf("%.2f\n",calcavg(x,2));
	return 0;
}
