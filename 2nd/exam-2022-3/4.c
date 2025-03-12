#include <stdio.h>
int numcheck(char s[]){
	int i=0;
	char num=s[0];
	while(s[i]){
		if(s[i]<'0'||s[i]>'9'){
			return -1;
		} else if(num<=s[i]){
			num=s[i];
		} else {
			return 0;
		}
		i++;
	}
	return 1;
}
int main(){
	char s[80];
	scanf("%s",s);
	printf("%d\n",numcheck(s));
	return 0;
}
