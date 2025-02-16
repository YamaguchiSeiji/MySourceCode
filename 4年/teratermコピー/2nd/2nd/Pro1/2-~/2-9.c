#include <stdio.h>
int main(){
	int month;
	scanf("%d",&month);
	if(month>=1&&month<=12){
		if(month==2){
			printf("28\n");
		} else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
			printf("31\n");
		} else {
			printf("30\n");
		}

	} else {
		printf("0\n");
	}
	return 0;
}
