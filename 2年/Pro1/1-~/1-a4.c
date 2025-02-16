#include <stdio.h>
int main(){
	float t;
	printf("身長を入力してください："); scanf("%f",&t);

	printf("標準体重は%.1fkgです。\n",t*t*22*0.0001);

	return 0;
}
