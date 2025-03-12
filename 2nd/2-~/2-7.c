#include <stdio.h>
int main(){
	int month;
    printf("何月ですか？："); scanf("%d",&month);
 
	switch(month){
		case 3:
		case 4:
		case 5:printf("春ですね。\n");break;
		case 6:
		case 7:
		case 8:printf("夏ですね。\n");break;
		case 9:
		case 10:
		case 11:printf("秋ですね。\n");break;
		case 12:
		case 1:
		case 2:printf("冬ですね。\n");break;
	}

    return 0;
}
