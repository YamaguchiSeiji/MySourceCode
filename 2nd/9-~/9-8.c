#include <stdio.h>
int main(){
	char c;
	while(1){
		printf("アルファベットの文字を1つ入力してください: ");
		scanf(" %c",&c);
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')
			break;
		puts("不正な入力です。");
	}
	if(c>='a'&&c<='z'){
		printf("%cの大文字は%cです。\n",c,c-('a'-'A'));
	}
	if(c>='A'&&c<='Z'){
		printf("%cの小文字は%cです。\n",c,c+('a'-'A'));
	}
	return 0;
}
