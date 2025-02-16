#include <stdio.h>
int main(){
	int day,week=1;
	int j=1;
	while(1){
		printf("How many days:");
		scanf("%d",&day);
		if(day>=1&&day<=31)break;
		puts("This day can't be used");
	}
	puts("   | Sun Mon Tue Wed Thu Fri Sat");
	puts("---+----------------------------");
	for(int i=1;i<=day;i+=7){
		printf(" %d |",week);
		for(int n=1;n<=7;n++){
			if(j>=day+1)break;
			printf("%4d",j);
			j++;
		}
		printf("\n");
		week++;
	}
	return 0;
}
