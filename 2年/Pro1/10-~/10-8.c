#include <stdio.h>
#include <string.h>
int main(){
	char str[80];
	while(1){
		printf("Input string: ");
		scanf("%s",str);
		if(strcmp(str,"abc123")){
			puts("Wrong!");
		} else {
			puts("OK.");
			break;
		}
	}
	return 0;
}
