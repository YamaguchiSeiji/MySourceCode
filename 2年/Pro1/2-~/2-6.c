#include <stdio.h>
int main(){
	int month;
	printf("何月ですか？："); scanf("%d",&month);

	if(month>=3&&month<=5)printf("春ですね。\n");else
	if(month>=6&&month<=8)printf("夏ですね。\n");else	
	if(month>=9&&month<=11)printf("秋ですね。\n");else
	if(month==12||month==1||month==2)printf("冬ですね。\n");
	
	return 0;
}
