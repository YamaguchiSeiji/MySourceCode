#include <stdio.h>
void hidechars(char *s,int step){
	int i=0;
	while(*s){
		if((i+1)%step==0){
			*s='_';
		}
		s++;
		i++;
	}
}
int main(){
	char s[80];
	int step;
	printf("単語と数字を入力してください: ");
	scanf("%s %d",s,&step);
	hidechars(s,step);
	printf("hidechars実行後:%s\n",s);
	return 0;
}
