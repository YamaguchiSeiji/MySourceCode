#include <stdio.h>

int strlen_a(char s[]){
	int len = 0;
	for(; s[len] != '\0'; len++) ;
	return len;
}

int main(){
	char s[256]="Hello!!";
	printf("%s = %d\n", s, strlen_a(s));
	return 0; 
}
