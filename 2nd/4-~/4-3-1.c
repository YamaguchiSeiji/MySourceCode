#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){
	int i,r,sum,ans;
	int q_num,q_dig;
	float time_inter;
	int dig=1;
	char Cal;
	srand((unsigned)time(NULL));

	system("clear");

	while(1){
		printf("計算方法を入力してください（+ or *)：");
		scanf("%c",&Cal);
		if(Cal=='+'||Cal=='*')break;
		puts("無効な値です。");	
	}

	while(1){
		printf("問題の最大桁数を入力してください。：");
		scanf("%d",&q_dig);
		if(q_dig>=1&&q_dig<=5)break;
		puts("無効な値です。");
	}
	for(int n=0;n<q_dig;n++){
		dig*=10;
	}

	while(1){
		printf("問題数を入力してください：");
		scanf("%d",&q_num);
		if(q_num>=1)break;
		puts("無効な値です。");
	}
		
	while(1){
		printf("問題の出題間隔を入力してください（秒）：");
		scanf("%f",&time_inter);
		if(time_inter>0)break;
		puts("無効な値です。");
	}

	system("clear");
	printf("Ready?\n");
	usleep(1000000);
	system("clear");
	i=3;
	while(i>0){
		printf("開始まで%d\n",i);
		usleep(1000000);
		system("clear");
		i--;
	}
	system("clear");

	if(Cal=='+')sum=0;
	if(Cal=='*')sum=1;
	
	i=0;
	while(i<q_num){
		r=rand()%dig+1;
		printf("%d\n",r);
		usleep(time_inter*1000000);
		i++;

		if(Cal=='+')sum+=r;
		if(Cal=='*')sum*=r;

		system("clear");
		usleep(300000);
	}
	printf("Answer: ");
	scanf("%d",&ans);
	if(ans==sum){
		printf("Correct!\n");
	} else {
		printf("Wrong..\n");
		printf("The answer is %d.\n",sum);
	}
	
	return 0;
}
