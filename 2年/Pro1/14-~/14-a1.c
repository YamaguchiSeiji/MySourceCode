#include <stdio.h>
#include <time.h>

int main(){
	time_t csec =time(NULL);
	struct tm *timeinfo=localtime(&csec);
	int year,mon,day,hour,min,sec;
	year=timeinfo->tm_year+1900;
	mon=timeinfo->tm_mon+1;
	day=timeinfo->tm_mday;
	hour=timeinfo->tm_hour;
	min=timeinfo->tm_min;
	sec=timeinfo->tm_sec;
	printf("現在%d年%d月%d日の%d時%d分%d秒です。\n",year,mon,day,hour,min,sec);
	return 0;
}
