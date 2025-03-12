#include <stdio.h>
#include <string.h>
int main(){
	int count_word=0;
	char word[16],str[256];
	while(1){
		printf("Input: ");
		scanf("%s",word);
		if(word[0]=='!'||word[0]=='.'){
			str[strlen(str)-1]=word[0];
			break;
		}else{
			strcat(str,word);
			count_word++;
		}
		strcat(str," ");
	}
	puts(str);
	printf("%d words\n",count_word);
	return 0;
}
