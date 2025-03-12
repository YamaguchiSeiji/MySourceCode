#include <stdio.h>
int main(){
	char ch,maxch;
	int n=0,max=0;
	int chcounter[26]={};
	while(ch!=EOF){
		ch=getchar();
		for(int i='A'; i<='Z'; i++){
			if(i==ch || i+('a'-'A')==ch){
				chcounter[i-'A']++;
			}
		}
	}
	for(int i='A'; i<='Z'; i++){
		printf("%c: %4d   ",i,chcounter[n]);
		if((n+1)%6==0){
			puts("");
		}
		if(chcounter[n]>=max){
			max=chcounter[n];
			maxch=i;
		}
		n++;
	}
	puts("");
	printf("一番多かった文字: %c\n",maxch);
	return 0;
}
