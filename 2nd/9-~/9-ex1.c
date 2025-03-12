#include <stdio.h>
void ccount(int chcounter[],char ch){
	int j='a',n='A';
	for(int i='A'; i<'Z'; i++){
		if(ch==j||ch==n){
			chcounter[i-'A']++;
		}
		j++;
		n++;
	}
}
int main(){
	int ch;
	int chcounter['Z'-'A']={};
	while(1){
		ch=getchar();
		ccount(chcounter,ch);
		if(ch==EOF){
			break;
		}
	}
	int n=0,max=0;
	char maxch;
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
