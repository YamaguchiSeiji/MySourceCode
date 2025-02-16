#include <stdio.h>
int main(){
	int num;
	scanf("%d",&num);
	while(num!=1){
		if(num%2==0){
			num/=2;
		} else {
			num=num*3+1;
		}
		printf("%d\n",num);
	}
	return 0;
}

