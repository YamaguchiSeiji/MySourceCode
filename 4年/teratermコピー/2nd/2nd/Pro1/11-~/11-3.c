#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void showhint(const char target[], const char try[]){
	int i=0;
	char hint[4];
	while(target[i]){
		if(target[i]==try[i]){
			hint[i]=try[i];
		} else if(target[i]<try[i]){
			hint[i]='_';
		} else {
			hint[i]='^';
		}
		i++;
	}
	printf("%s\n",hint);
}

void game_start(int inp){
	int dig=4;
	system("clear");

	puts("<<<数字当てゲーム>>>");
	system("clear");
	char answer_num[12],num[dig];
	int r,i=0;
	srand((unsigned)time(NULL));
	while(answer_num[i]){
		answer_num[i]='0'+i;
		i++;
	}
	for(int i=10; i>=0; i--){
		r='0';
		r+=rand()%10;
		answer_num[11]=answer_num[i];
		answer_num[i]=answer_num[r];
		answer_num[r]=answer_num[11];
	}
	answer_num[dig]='\0';
	num[dig]='\0';
	puts("<<<数字当てゲーム>>>");
	printf("4桁の数字です。\n");
	for(int i=inp; i>0; i--){
		printf("< 残り%d回 >\n",i);
		puts("数字を入力してください。");
		printf("%s\n",answer_num);
		scanf("%s",num);
		puts("");
		showhint(answer_num,num);
		if(strcmp(answer_num,num)==0){
			puts("gameclear!!");
			break;
		} else if(i==1){
			puts("gameover");
			printf("正解は%sでした。\n",answer_num);
			break;
		}
	}
}

int main(){
	int select;
	menu:
	system("clear");
	puts("<<<数字当てゲーム>>>");
	puts("0:ノーマルモード");
	puts("1:ハードモード");
	puts("2:エキスパートモード");
	puts("3:ギャンブルモード");
	scanf("%d",&select);
	switch(select){
		case 0:
			system("clear");
			puts("4桁の数字を当てるゲームです");
			puts("入力回数：5");
			do{
				puts("0:スタート");
				puts("1:やめる");
				scanf("%d",&select);
				if(select==0){
					game_start(5);	
				} else if(select==1){
					goto menu;
				}
			} while(select==1||select==0);
			break;
	}
	return 0;
}
