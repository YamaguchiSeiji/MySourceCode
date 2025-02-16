#include <stdio.h>
#define NUM 4

int check_asc(int val[]){
	int num=val[0]-1;
	for(int i=0; i<NUM; i++){
		if(num>=val[i]){
			return 0;
		}
		num=val[i];
	}
	return 1;
}

int main(){
	int val[NUM];
	int i=0;
	while(i<NUM){
		scanf("%d",&val[i]);
		i++;
	}
	printf("%d\n", check_asc(val));
	return 0;
}
