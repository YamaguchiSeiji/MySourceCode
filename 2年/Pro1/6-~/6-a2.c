#include <stdio.h>
int main(){
	int num;
	int max=0,ave=0; 
	printf("人数を入力してください: ");
	scanf("%d",&num);
	int score[num];
	int hyouka[num][4];
	for(int i=0; i<num; i++){
		for(int j=0; j<4; j++){
			hyouka[i][j]=0;
		}
	}
	printf("%d人の点数を入力してください。",num);
	for(int i=0; i<num; i++){
		printf("No.%d: ",i+1);
		scanf("%d",&score[i]);
		if(score[i]>=80){
			hyouka[i][0]=i+1;
		}else if(score[i]>=70){
			hyouka[i][1]=i+1;
		}else if(score[i]>=60){
			hyouka[i][2]=i+1;
		}else{
			hyouka[i][3]=i+1;
		}
		ave+=score[i];
		if(max<score[i]){
			max=score[i];
		}
	}

	puts("-- 成績分布 --");
	printf("優　: ");
	for(int i=0; i<num; i++){
		if(hyouka[i][0]!=0){
			printf("%d ",i+1);
		}
	}
	puts("");
	printf("良　: ");
	for(int i=0; i<num; i++){
		if(hyouka[i][1]!=0){
			printf("%d ",i+1);
		}
	}
	puts("");
	printf("可　: ");
	for(int i=0; i<num; i++){
		if(hyouka[i][2]!=0){
			printf("%d ",i+1);
		}
	}
	puts("");
	printf("不可: ");
	for(int i=0; i<num; i++){
		if(hyouka[i][3]!=0){
			printf("%d ",i+1);
		}
	}
	puts("");
	puts("-----");
	printf("最高点: %d点\n",max);
	printf("平均点: %.1f点\n",(double)ave/num);

	return 0;
}
