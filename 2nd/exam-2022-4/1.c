#include <stdio.h>
struct grade{
	int math;
	int eng;
	int prog;
};

int check(struct grade *s){
	int sum=0;
	sum=(*s).math + (*s).eng + (*s).prog;
	if((*s).math>=60 && (*s).eng>=60 && (*s).prog>=60 && sum>=200){
		return 1;
	} else {
		return 0;
	}
}
int main(){
	struct grade stu;
	scanf("%d %d %d",&stu.math,&stu.eng,&stu.prog);
	printf("%d\n",check(&stu));
	return 0;
}
