#include <stdio.h>
#define STU_NUM 50
struct student{
	char person;
	double height;
	double weight;
};

int main(){
	struct student stu[STU_NUM];
	double f_count=0,m_count=0;
	double f_sum_hei=0,m_sum_hei=0;
	double f_sum_wei=0,m_sum_wei=0;
	int stu_count;
	printf("クラス人数:");
	scanf("%d%*c",&stu_count);
	printf("%d\n",stu_count);
	puts("性別　身長　体重の順で入力");
	for(int i=0; i<stu_count; i++){
		scanf("%c%lf%lf%*c", &stu[i].person, &stu[i].height, &stu[i].weight);
		if(stu[i].person == 'F'){
			f_sum_hei += stu[i].height;
			f_sum_wei += stu[i].weight;
			f_count++;
		} else {
			m_sum_hei += stu[i].height;
			m_sum_wei += stu[i].weight;
			m_count++;
		}
	}
	puts("------------------------");
	puts("|性別|　身長　|　体重　|");
	puts("------------------------");
	for(int i=0; i<stu_count; i++){
		printf("|%3c |%7.2f |%7.2f |\n",stu[i].person, stu[i].height, stu[i].weight);
	}
	puts("------------------------");
	puts("");
	puts("平均身長と平均体重");
	puts("------------------------");
	puts("|性別|　身長　|　体重　|");
	puts("------------------------");
	printf("|男性|%7.2f |%7.2f |\n",m_sum_hei / m_count, m_sum_wei / m_count);
	printf("|女性|%7.2f |%7.2f |\n",f_sum_hei / f_count, f_sum_wei / f_count);
	puts("------------------------");
	return 0;
}
