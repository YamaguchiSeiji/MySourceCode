#include <stdio.h>
int main(){
	printf("文字を一つ入力してください:");
	int ch;
	ch=getchar();
	if(ch==EOF){
		printf("\nEOFです。\n");
	} else {
		printf("入力された文字は%cです。\n",ch);
		printf("文字コードは10進数で%d、16進数で%Xです。\n",ch,ch);
	}
	return 0;
}
