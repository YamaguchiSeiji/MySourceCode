#include <stdio.h>
int main(){
	int score[4][3];
	float ave[6];

	for(int i=0; i<4; i++){
		printf("No.%dの国語の点数は: ",i+1);
		scanf("%d",&score[i][0]);
		printf("No.%dの数学の点数は: ",i+1);
		scanf("%d",&score[i][1]);

		score[i][2]=score[i][0]+score[i][1];
		ave[i]=score[i][2]/2.0;
		ave[4]+=score[i][0];
		ave[5]+=score[i][1];
	}

	puts(" ");
	puts("     国語 数学 合計 平均");
	for(int i=0; i<4; i++){
		printf("No.%d ",i+1);
		for(int j=0; j<3; j++){
			printf("%4d ",score[i][j]);
		}
		printf("%4.1f",ave[i]);
		puts(" ");
	}
	
	printf("平均 %4.1f %4.1f\n",ave[4]/4.0,ave[5]/4.0);


	return 0;
}
