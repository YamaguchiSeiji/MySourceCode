#include <stdio.h>
#include <string.h>
int check_char(char str[]){
	int i=0;
	int alpha_count=0,num_count=0;
	int ng_count=0;
	while(str[i]){
		if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'){
			alpha_count++;
		} else if(str[i]>='0'&&str[i]<='9'){
			num_count++;
		} else if(str[i]!='_'){
			ng_count++;
		}
		i++;
	}
	if(alpha_count>=1&&num_count>=1&&ng_count==0){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	char str[80];
	printf("Input: ");
	scanf("%s",str);
	if(check_char(str)==1&&strlen(str)>=6){
		puts("OK!");
	} else {
		puts("NG");
	}
	return 0;
}
