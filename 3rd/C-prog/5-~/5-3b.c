#include <stdio.h>
#include <string.h>
#define N 20

int main(){
	char str1[N], str2[N];

	printf("文字列を2つ入力(長さ < 20)\n");
	fgets(str1, N, stdin);
	fgets(str2, N, stdin);
	
	if(str1[strlen(str1)-1] == '\n')
		str1[strlen(str1)-1] = '\0';

	printf("str1=[%s]\n", str1);
	printf("str2=[%s]\n", str2);

	return 0;
}
