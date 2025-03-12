#include <stdio.h>
int main(){
	int day,offset,week=1;
	int j=1;
	int offset2;
	while(1){
		printf("Input day and offset:");
		scanf("%d %d",&day,&offset);
		if(day>=28&&day<=31&&offset>=0&&offset<=6)break;
		puts("This day can't be used");
	}
	offset2=offset;
	puts("   | Sun Mon Tue Wed Thu Fri Sat");
	puts("---+----------------------------");
	for(int i=1; i<=day+offset2; i+=7){
		printf(" %d |",week++);
		for(int m=0; m<offset; m++){
			printf("    ");
		}
		for(int n=1; n<=7-offset; n++){
			if(j>=day+1)break;
			printf("%4d",j);
			j++;
		}
		printf("\n");
		offset=0;
	}
	return 0;
}
