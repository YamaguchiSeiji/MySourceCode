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

int main(){
	char c;
	int shift;
	scanf("%c %d", &c, &shift);
	printf("%c\n", alphashift(c,shift));
	return 0;
}
