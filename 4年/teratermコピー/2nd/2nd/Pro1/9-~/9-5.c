#include <stdio.h>
int main(){
	puts("文字を入力してください。");
	int ch;
	int count=0;
	while(1){
		ch=getchar();
		if(ch<='9'&&ch>='0'){
			count++;
		}
		if(ch==EOF){
			break;
		}
	}
	printf("入力された文字の中に、数字は%d個含まれています。\n",count);
	return 0;
}
