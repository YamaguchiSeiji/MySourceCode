#include <stdio.h>
#define NUMBER 4
int main(){
	int per[NUMBER]={};
	int vote,maxvote=0;
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
		if(maxvote<per[i]){
			maxvote=per[i];
		}
	}

	for(int i=0; i<NUMBER; i++){
		printf("No. %d: ",i);
		for(int j=0; j<per[i]; j++){
			if(per[i]==maxvote){
				putchar('#');
			} else {
				putchar('+');
			}
		}
		puts("");
	}
	return 0;
}
