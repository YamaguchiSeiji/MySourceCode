#include <stdio.h>
int calc(int carrot,int onion){
	if(carrot+onion>=5){
		return (carrot*50+onion*100)*0.9;
	} else {
		return carrot*50+onion*100;
	}
}

int main(){
	int carrot,onion;
	scanf("%d %d",&carrot,&onion);
	printf("%d\n",calc(carrot,onion));
	return 0;
}
