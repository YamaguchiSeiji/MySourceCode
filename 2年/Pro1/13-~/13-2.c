#include <stdio.h>
void swapchar(char *s, int d1, int d2){
	char n;
	n=*(s+d1);
	*(s+d1)=*(s+d2);
	*(s+d2)=n;
}

int main(){
	char s[]="hamster";
	swapchar(s,2,5);
	puts(s);
	return 0;
}
