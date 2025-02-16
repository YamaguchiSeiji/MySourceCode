#include <stdio.h>
char getsignchar(int num){
	if(num>0)
		return 'P';
	else if(num<0)
		return 'N';
	else 
		return 'Z';
}
int main(){
	int num;
	scanf("%d",&num);
	printf("%c\n",getsignchar(num));
	return 0;
}
