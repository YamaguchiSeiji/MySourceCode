#include <stdio.h>
int main(){
	int a[5]={5,10,3,1,8};
	int sum=0,average=0;

	for(int i=0; i<5; i++){
		sum+=a[i];
	}
	printf("sum: %d \n",sum);
	printf("average: %.1f \n",sum/5.0);
	
	return 0;
}
