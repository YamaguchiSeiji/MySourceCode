#include <stdio.h>
int main(){
	int i,n;
	int num,line;
	printf("何個出力しますか？： "); scanf("%d",&num);
	printf("何個ごとに改行しますか？： "); scanf("%d",&line);

	for(i=0; i<num/line; i++){
		for(n=0; n<line; n++){
			printf("#");
		}
		puts(" ");
	}
	for(n=0; n<num%line; n++){
		printf("#");
	}
	puts(" ");

	return 0;
}
