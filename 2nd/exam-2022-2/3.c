#include <stdio.h>
#define NUMBER 4
int main(){
	int per[NUMBER]={};
	int vote;
	while(1){
		scanf("%d",&vote);
		if(vote<0){
			break;
		} else if(vote>=NUMBER){
			puts("ERROR");
		} else {
			per[vote]++;
		}
	}
	for(int i=0; i<NUMBER; i++){
		printf("No. %d: %d\n",i,per[i]);
	}
	return 0;
}
