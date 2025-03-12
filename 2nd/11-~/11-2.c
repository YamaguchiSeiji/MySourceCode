#include <stdio.h>
void showhint(const char target[], const char try[]){
	int i=0;
	char hint[4];
	while(target[i]){
		if(target[i]==try[i]){
			hint[i]=try[i];
		} else if(target[i]<try[i]){
			hint[i]='_';
		} else {
			hint[i]='^';
		}
		i++;
	}
	printf("%s\n",hint);
}

int main(){
	showhint("1234","1234");
	showhint("1234","5231");
	showhint("1234","5670");
	return 0;
}
