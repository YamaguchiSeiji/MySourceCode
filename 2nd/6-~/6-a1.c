#include <stdio.h>
int main(){
	int num;
	printf("人数を入力してください。: ");
	scanf("%d",&num);

	int score[num-1];
	int yu=0,ryo=0,ka=0,fuka=0;
	printf("%d人の点数を入力してください。\n",num);
	for(int i=0; i<num ; i++){
		printf("No.%d: ",i+1);
		scanf("%d",&score[i]);

		if(score[i]>=80){
			yu++;
		} else if(score[i]>=70){
			ryo++;
		} else if(score[i]>=60){
			ka++;
		} else {
			fuka++;
		}
	}
	puts("-- 成績分布 --");
	printf("優　: %d人\n",yu);
	printf("良　: %d人\n",ryo);
	printf("可　: %d人\n",ka);
	printf("不可: %d人\n",fuka);
	return 0;
}
