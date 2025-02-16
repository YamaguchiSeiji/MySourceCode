#include <stdio.h>
#define NUM 3
struct seiseki{
	char name[64];
	int math;
	int eng;
};

int main(){
	struct seiseki stu[NUM];
	int math_pt=0,eng_pt=0;
	puts("「名前 数学の点数 英語の点数」の形式で3個のデータを入力してください。");
	for(int i=0; i<NUM; i++){
		scanf("%s %d %d",stu[i].name, &stu[i].math, &stu[i].eng);
		if(stu[i].math>=math_pt){
			math_pt=stu[i].math;
		}
		if(stu[i].eng>=eng_pt){
			eng_pt=stu[i].eng;
		}
	}

	printf("数学の最高点: %d\n",math_pt);
	printf("最高点を取った学生: ");
	for(int i=0; i<NUM; i++){
		if(stu[i].math==math_pt){
			printf("%s ",stu[i].name);
		}
	}
	puts("");
	printf("英語の最高点: %d\n",eng_pt);
	printf("最高点を取った学生: ");
	for(int i=0; i<NUM; i++){
		if(stu[i].eng==eng_pt){
			printf("%s ",stu[i].name);
		}
	}
	puts("");
	return 0;
}
