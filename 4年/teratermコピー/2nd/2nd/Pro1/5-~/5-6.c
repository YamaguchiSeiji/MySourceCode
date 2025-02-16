#include <stdio.h>
int main(){
	int num1,num2,i;
	printf("値を入力してください: ");
	scanf("%d",&num1);

	for(int n=1; n<=num1; n++){

		for(i=n; i>0 ;i/=10){
			num2=i;
			while(num2>=10){
				num2-=10;
			}
			if(num2==3)break;
		}

		if(num2==3||n%3==0){
			printf("%d! ",n);
		} else {
			printf("%d ",n);
		}
	}

	putchar('\n');
	return 0;
}

