#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(){
	system("clear");	
	int mode,mode2,ans,time_inter;
	char ready;
	int a=0,r,i=0;
	srand((unsigned)time(NULL));
	
	menu:
	puts("<< ナンバーサーチゲーム >>");
	puts("0: ノーマルモード");
	puts("1: フラッシュモード");
	puts("2: バトルモード(2人用)");
	puts("3: ルール説明");
	puts("4: ゲームを終了する");
	printf("数字を入力してください: ");
	scanf("%d",&mode);
	system("clear");
	if(mode==0){
		puts("-ノーマルモード-");
		int size;
		printf("数字の数を入力してください: ");
		scanf("%d",&size);
		int num[size+1];
		for(int i=0; i<size; i++){
			num[i]=i+1;
		}
		do{
			puts("準備が出来たら'r'を入力してください");
			scanf("%s",&ready);
		} while(ready!='r');

		for(i=3; i>0; i--){
			system("clear");
			printf("%d\n",i);
			usleep(1000*1000);
		}

		system("clear");
		puts("スタート");
		usleep(1000*1000);
		system("clear");

		for(i=size-1; i>=0; i--){
			r=rand()%size+1;
			num[size]=num[i];
			num[i]=num[r];
			num[r]=num[size];
		}

		for(i=1; i<size; i++){
			printf("%3d",num[i]);
		}
			
		puts("");
	
		printf("欠けている数字はどれ？:");

		scanf("%d",&ans);
		if(ans==num[0]){
			puts("正解！");
			do{
				puts("0:次へ進む");
				scanf("%d",&mode);
			} while(mode!=0);

		} else{
			puts("不正解");
			printf("正解は%dでした\n",num[0]);
			do{
				puts("0:次へ進む");
				scanf("%d",&mode);
			} while(mode!=0);

		}

	} else if(mode==1){
		int size;
		puts("-フラッシュモード-");
		printf("数字の数を入力してください: ");
		scanf("%d",&size);
		int num[size+1];
		for(int i=0; i<size; i++){
			num[i]=i+1;
		}

		printf("問題の出題間隔(ミリ秒)を入力してください: ");
		scanf("%d",&time_inter);	
		
		do{
			puts("準備が出来たら'r'を入力してください");
			scanf("%s",&ready);
		} while(ready!='r');

		for(i=3; i>0; i--){
			system("clear");
			printf("%d\n",i);
			usleep(1000*1000);
		}

		system("clear");
		puts("スタート");
		usleep(1000*1000);
		system("clear");

		for(i=size-1; i>=0; i--){
			r=rand()%size+1;
			num[size]=num[i];
			num[i]=num[r];
			num[r]=num[size];
		}
		
		for(i=1; i<size; i++){
			printf("%d\n",num[i]);
			usleep(time_inter*1000);
			system("clear");
		}
	
		printf("欠けている数字はどれ？:");

		scanf("%d",&ans);
		if(ans==num[0]){
			puts("正解！");
			do{
				puts("0:次へ進む");
				scanf("%d",&mode);
			} while(mode!=0);

		}else {
			puts("不正解");	
			printf("正解は%dでした\n",num[0]);
			do{
				puts("0:次へ進む");
				scanf("%d",&mode);
			} while(mode!=0);
		}
	} else if(mode==2){
		puts("-バトルモード-");

		int dec;
		char name[2][256]={{1},{2}};
		rename:
		
		do{
			puts("プレイヤーの名前を決めますか？");
			puts("0:決める");
			puts("1:決めない");
			scanf("%d",&dec);
		} while(dec!=0&&dec!=1);
		system("clear");
		if(dec==0){
			puts("プレイヤー1の名前を入力してください:");
			scanf("%s",name[0]);
			puts("プレイヤー2の名前を入力してください:");
			scanf("%s",name[1]);
		} else{
			strcpy(name[0],"プレイヤー1");
			strcpy(name[1],"プレイヤー2");
		}
		int gamenum;
		do{
			printf("ゲーム数を入力してください(1～100): ");
			scanf("%d",&gamenum);
		}while(gamenum<1&&gamenum>100);
		printf("問題の出題間隔(ミリ秒)を入力してください: ");
		scanf("%d",&time_inter);	

		system("clear");
		puts("-バトルモード-");
		printf("ゲーム数: %d\n",gamenum);
		usleep(2000000);
		system("clear");
				
		int win,lose=2;
		for(int size=2; size<gamenum+2; size++){
			int num[size];
			printf("%dゲーム目\n",size-1);
			for(int p=0; p<=1; p++){
				if(lose!=2)break;
				printf("%sの番です。\n",name[p]);
				printf("数字の数:%d\n",size);
				do{
					puts("準備が出来たら'r'を入力してください");
					scanf("%s",&ready);
				} while(ready!='r');

				system("clear");
				puts("スタート");
				usleep(1000*1000);
				system("clear");
				for(int i=0; i<size; i++){
					num[i]=i+1;
				}
				for(i=size-1; i>=0; i--){
					r=rand()%size+1;
					num[size]=num[i];
					num[i]=num[r];
					num[r]=num[size];
				}
			
				for(i=1; i<size; i++){
					printf("%d\n",num[i]);
					usleep(time_inter*1000);
					system("clear");
				}
	
				printf("欠けている数字はどれ？:");

				scanf("%d",&ans);
				if(ans==num[0]){
					puts("正解！");
					usleep(500000);
					system("clear");
				}else {
					puts("不正解");
					printf("正解は%dでした\n",num[0]);
					lose=p;
					if(lose==0){
						win=1;
					} else {
						win=0;
					}
				}
			}
			if(lose!=2)size=gamenum+1;
		}
		if(lose==2){
			usleep(1000000);
			system("clear");
			puts("-ゲーム終了-");
			puts("引き分け");
			do{
				puts("0:次へ進む");
				scanf("%d",&mode);
			} while(mode!=0);
		} else {
			usleep(1000000);
			system("clear");
			puts("-ゲーム終了-");
			printf("勝者:%s\n",name[win]);
			printf("敗者:%s\n",name[lose]);
			do{
				puts("0:次へ進む");
				scanf("%d",&mode);
			} while(mode!=0);
		}
	}else if(mode==3){
		rule:
		system("clear");
		puts("-ルール-");
		puts("1: ノーマルモード");
		puts("2: フラッシュモード");
		puts("3: バトルモード");
		puts("4: メニューに戻る");
		printf("数字を入力してください: ");
		scanf("%d",&mode);
		system("clear");
		if(mode==1){
			puts("-ノーマルモードのルール-");
			puts("指定した数字の数までの数字が表示されます。");
			puts("その数字までの範囲で欠けている数字を答えてください。");
			do{
				puts("0: 戻る");
				scanf("%d",&mode);
			}while(mode!=0);
			goto rule;
		}else if(mode==2){
			puts("-フラッシュモードのルール-");
			puts("指定した数字の数までの数字が一定間隔で表示されます。");
			puts("その数字までの範囲で欠けている数字を答えてください。");
			do{
				puts("0: 戻る");
				scanf("%d",&mode);
			}while(mode!=0);
			goto rule;

		}else if(mode==3){
			puts("-バトルモードのルール-");
			puts("二人用です。");
			puts("数字がが一定間隔で表示されます。");
			puts("その数字までの範囲で欠けている数字を交互に答えてください。");
			puts("数字はゲーム数が増えると増えていきます。");
			puts("先に間違えたほうが負けです。");
			puts("指定したゲーム数までゲームが続いたら引き分けになります。");
			do{
				puts("0: 戻る");
				scanf("%d",&mode);
			}while(mode!=0);
			goto rule;

		}else if(mode==4){
			goto menu;
		}
	}else if(mode==4){
		goto end;
	}
	
	system("clear");
	puts("0:メニューに戻る");
	puts("1:ゲームを終了する");
	printf("数字を入力してください: ");
	scanf("%d",&mode);
	switch(mode){
		case 0:
			system("clear");
			goto menu;
		case 1:
			break;
	}
	end:
	return 0;
}
