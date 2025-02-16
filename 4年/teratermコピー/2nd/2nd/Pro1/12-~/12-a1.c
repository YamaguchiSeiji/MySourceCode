#include <stdio.h>
int getnextday(int month, int day, int *nmonth, int *nday){
	int n=0;
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day==31){
				*nday=1;
				*nmonth+=1;
				if(*nmonth==13){
					*nmonth=1;
				}
			} else if(*nday>0&&*nday<32){
				*nday+=1;
			} else {
				n=-1;
			}
		break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(day==30){
				*nday=1;
				*nmonth+=1;
			} else if(*nday>0&&*nday<32){
				*nday+=1;
			} else {
				n=-1;
			}
		break;
		case 2:
			if(day==28){
				*nday=1;
				*nmonth+=1;
			} else if(*nday>0&&*nday<32){
				*nday+=1;
			} else {
				n=-1;
			}
		default:
			n=-1;
	}
	return n;
}

int main(){
	int num;
	int month,day;
	scanf("%d/%d",&month,&day);
	num=getnextday(month,day,&month,&day);
	if(num==-1){
		puts("Invalid date.");
	} else if(num==0){
		printf("%d/%d\n",month,day);
	}
	return 0;
}
