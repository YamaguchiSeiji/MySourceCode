#include <stdio.h>
void del_digit(char s[]){
	for(int i=0; s[i]; i++){
		if(s[i]>='0'&&s[i]<='9'){
			for(int j=i; s[j]; j++){
				s[j]=s[j+1];
			}
			i--;
		}
	}
}

int main(){
	char s[80];
	printf("文字列を入力してください: ");
	scanf("%s",s);
	printf("del_digitを呼び出す前: %s\n",s);
	del_digit(s);
	printf("del_digitを呼び出した後: %s\n",s);
}
