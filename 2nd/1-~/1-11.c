#include <stdio.h>
int main(){
	float x,y;

	printf("円柱の高さを入力してください："); scanf("%f",&x);
	printf("底面の半径を入力してください："); scanf("%f",&y);

	printf("円柱の体積は約%.2fです。",y*y*3.1415*x);

	return 0;
}
