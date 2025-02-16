#include <stdio.h>
int main(){
	
	int x;

	printf("整数を入力してください:");
	scanf("%d",&x);

	while(x>=10){
		x=x-10;
	}

	printf("***** \n*   * \n* %d * \n*   * \n*****\n",x);

	return 0;
}
