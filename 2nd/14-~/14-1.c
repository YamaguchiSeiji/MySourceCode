#include <stdio.h>
struct student{
	char dept[64];
	int grade;
	int number;
	char name[64];
};

int main(){
	struct student s1={"HI",2,12,"Taro"};
	struct student s2={"TE",4,25,"Jiro"};

	printf("%s-%d No.%d %s\n",s1.dept,s1.grade,s1.number,s1.name);
	printf("%s-%d No.%d %s\n",s2.dept,s2.grade,s2.number,s2.name);

	return 0;
}
