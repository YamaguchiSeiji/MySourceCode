#include <stdio.h>
float power(float x,int n){
	float num=1;
	for(int i=0; i<n; i++){
		num*=x;
	}
	return num;
}
int main(){
	float x;
	int n;
	printf("実数xと整数nを入力してください。\n");
	printf("実数x：");
	scanf("%f",&x);
	printf("実数n：");
	scanf("%d",&n);

	printf("%f\n",power(x,n));
	return 0;
}
