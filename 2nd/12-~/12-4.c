#include <stdio.h>
void convtime(int m, int *hour, int *min){
	*hour=m / 60;
	*min=m%60;
}
int main(){
	int m,hour,min;
	printf("分を入力してください: ");
	scanf("%d",&m);
	convtime(m,&hour,&min);
	printf("%d分は%d時間%d分です。\n",m,hour,min);
	return 0;
}


