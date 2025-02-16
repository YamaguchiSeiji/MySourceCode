#include <stdio.h>
#include <string.h>
void reverse(char *s){
	int n=strlen(s)-1;
	char t;
	int i=0,j=n;
	while(i<=n/2){
		t=*(s+j);
		*(s+j)=*(s+i);
		*(s+i)=t;
		i++;
		j--;
	}
}
int main(){
	char s[80];
	printf("文字列は？: ");
	scanf("%s",s);
	reverse(s);
	puts(s);
	return 0;
}
