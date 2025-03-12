#include <stdio.h>
#include <string.h>

#define LEN 256

int main(){
	char st[LEN] = "Hello World!!";

	printf("[%s]の文字列の長さ: %ld\n", st, strlen(st));
	printf("[%s]の文字列の長さ: %ld\n", "ABC", strlen("ABC"));

	return 0;
}
