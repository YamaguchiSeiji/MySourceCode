#include <stdio.h>
char alphashift(char c, int shift){
	if(c>='a' && c<='z'){
		if(c+shift>'z'){
			for(int i=0; i<shift; i++){
				c+=1;
				if(c>'z'){
					c='a';
				}
			}
		} else {
			c+=shift;
		}
	}
	return c;
}

void strshift(char s[], int shift){
	if(shift<=20 && shift>=0){
		for(int i=0; s[i]; i++){
			s[i]=alphashift(s[i],shift);
		}
	}
}

int main(){
	char s[80];
	int shift;
	scanf("%s %d", s, &shift);
	strshift(s,shift);
	puts(s);
	return 0;
}
