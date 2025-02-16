#include <stdio.h>
long long int binary(int num){
	long long int bin=0;
	for(long long int i=1; num>0; i*=10){
		if(num%2==1){
			bin+=i;
		}
		num/=2;
	}
	return bin;
}
int main(){
	int num;
	while(1){
		printf("10進数の整数を入力してください:");
		scanf("%d",&num);
		if(num>=0&&num<=65535)
			break;
		puts("0から65535までの値のみ受け付けます。");
	}
	printf("%lld\n",binary(num));
	return 0;
}
