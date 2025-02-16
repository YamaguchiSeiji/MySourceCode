#include <stdio.h>
void mushikui(char s[],int step){
	int count;
	for(int i=0; s[i]; i++){
		if(i%step==0){
			s[i]='#';
			count++;
		}
	}
	printf("%d\n",count);
	printf("%s\n",s);
}
int main(){
	char s[80];
	int step;
	scanf("%s %d",s,&step);
	mushikui(s,step);
	return 0;
}
