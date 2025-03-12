#include <stdio.h>
int main(){
	int day,month;
	scanf("%d/%d",&month,&day);
	if(month>=1&&month<=12){
		switch(month){
		case(1):if(day>=1&&day<=31)printf("OK\n"); else printf("NG\n"); break;
		case(2):if(day>=1&&day<=28)printf("OK\n"); else printf("NG\n"); break;
		case(3):if(day>=1&&day<=31)printf("OK\n"); else printf("NG\n"); break;
		case(4):if(day>=1&&day<=30)printf("OK\n"); else printf("NG\n"); break;
		case(5):if(day>=1&&day<=31)printf("OK\n"); else printf("NG\n"); break;
		case(6):if(day>=1&&day<=30)printf("OK\n"); else printf("NG\n"); break;
		case(7):if(day>=1&&day<=31)printf("OK\n"); else printf("NG\n"); break;
		case(8):if(day>=1&&day<=31)printf("OK\n"); else printf("NG\n"); break;
		case(9):if(day>=1&&day<=30)printf("OK\n"); else printf("NG\n"); break;
		case(10):if(day>=1&&day<=31)printf("OK\n"); else printf("NG\n"); break;
		case(11):if(day>=1&&day<=30)printf("OK\n"); else printf("NG\n"); break;
		case(12):if(day>=1&&day<=31)printf("OK\n"); else printf("NG\n"); break;
		}
	} else {
		printf("NG\n");
	}
	return 0;
}
