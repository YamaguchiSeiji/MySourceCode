#include <stdio.h>
#define N 20

int main(){
	char str1[N], str2[N];

	printf("文字列を2つ入力(長さ < 20)\n");
	scanf("%s", str1);
	scanf("%s", str2);

	printf("str1=[%s]\n", str1);
	printf("str2=[%s]\n", str2);

	return 0;
}
