#include <stdio.h>

char getmaxalpha(char *p){
	char maxalpha='a';
	char c='*';
	for(int i=0; *p; i++,p++){
		if(*p >= 'a' && *p <= 'z'){
			if(maxalpha <= *p){
				maxalpha = *p;
			}
			c = maxalpha;
		}
	}
	return c;
}

int main(){
	char c;
	c = getmaxalpha("alpha");
	printf("%c\n", c);
	c = getmaxalpha("ABC123");
	printf("%c\n", c);
	c = getmaxalpha("{zoo}");
	printf("%c\n", c);
	return 0;
}
