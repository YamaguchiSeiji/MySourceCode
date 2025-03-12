#include <stdio.h>
#include <string.h>
int mystrcmp(const char *s1, const char *s2){

}

int main(){
	printf("文字比較(abc:abc): %d\n", strcmp("abc", "abc"));
	printf("文字比較(aB:ab): %d\n", strcmp("aB", "ab"));
	printf("文字比較(ab:aB): %d\n", strcmp("ab", "aB"));
	printf("文字比較(abc:ab): %d\n", strcmp("abc", "ab"));
	printf("文字比較(ab:abc): %d\n", strcmp("ab", "abc"));

	return 0;
}
