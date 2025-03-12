#include <stdio.h>

int mystrcmp(const char *s1, const char *s2);

int main(){
	printf("文字比較(abc:abc): %d\n", mystrcmp("abc", "abc"));
	printf("文字比較(aB:ab): %d\n", mystrcmp("aB", "ab"));
	printf("文字比較(ab:aB): %d\n", mystrcmp("ab", "aB"));
	printf("文字比較(abc:ab): %d\n", mystrcmp("abc", "ab"));
	printf("文字比較(ab:abc): %d\n", mystrcmp("ab", "abc"));

	return 0;
}

int mystrcmp(const char *s1, const char *s2){
	int num;
	for(; *s1 != '\0' || *s2 != '\0'; s1++,s2++){
		if(*s1 > *s2) return 1;
		if(*s1 < *s2) return -1;
	}
	return 0;
}

