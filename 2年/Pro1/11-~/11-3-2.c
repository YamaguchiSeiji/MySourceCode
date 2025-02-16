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

int main(){
	int i,n,r;
	srand((unsigned)time(NULL));
	char ans[11],num[5];
	for(int i=0; i<=9; i++){
		ans[i]='0'+i;
	}
	for(i=0; i>=0; i--){
		r=rand()%10;
		n=ans[i];
		ans[i]=ans[r];
		ans[r]=n;
	}
	ans[4]='\0';
	puts("<<<数字当てゲーム>>>");
	printf("4桁の数字です。\n");
	for(int i=5; i>0; i--){
		printf("<残り%d回>\n",i);
		puts("数字を入力してください。");
		scanf("%s",num);
		if(strcmp(ans,num)==0){
			puts("gameclear!!");
			break;
		} else if(strcmp(ans,num)!=0&&i!=1){
			showhint(ans,num);	
		} else if(i==1){
			puts("gameover");
			printf("正解は%sでした。\n",ans);
			break;
		}
	}
	return 0;
}
