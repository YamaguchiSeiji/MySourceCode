#include <stdio.h>
void search_c(char c,char str[]){
	int count=0;
	for(int i=0; str[i]; i++){
		if(str[i]==c){
			count++;
		}
	}
	printf("文字列%sの中には文字%cが%d個含まれています。\n",str,c,count);
}
int main(){
	char c,str[80];
	printf("文字列を入力してください: ");
	scanf("%s",str);
	printf("探したい文字を入力してください: ");
	scanf(" %c",&c);
	search_c(c,str);
	return 0;
}
