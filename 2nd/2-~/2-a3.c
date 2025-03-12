#include <stdio.h>
#include <time.h>
int main(){
	time_t timer;
	struct tm*local;
	int cyear,cmonth,cday;

	timer=time(NULL);
	local=localtime(&timer);
	cyear=local->tm_year+1900;
	cmonth=local->tm_mon+1;
	cday=local->tm_mday;

	printf("今日は%d年%d月%d日です。\n",cyear,cmonth,cday);
	
	int byear,bmonth,bday;
	printf("あなたの誕生日を「年/月/日」の形式で入力してください：");
	scanf("%d/%d/%d",&byear,&bmonth,&bday);

	if(bmonth==cmonth&&bday==cday){
		printf("あなたは今日%d歳になりました。おめでとう！！\n",cyear-byear);
	} else if(byear>=cyear&&bmonth>=cmonth&&bday>=cday){
		printf("あなたは0歳です。\n");
	} else if(bmonth-cmonth<=0&&bday-cday<0){
		printf("あなたは%d歳です。\n",cyear-byear);
	} else {
		printf("あなたは%d歳です。\n",cyear-byear);
	}
	return 0;
}
