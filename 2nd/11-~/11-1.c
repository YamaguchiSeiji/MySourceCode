#include <stdio.h>
void showhint(const char target[], const char try[]){
	int i=0;
	char hint[4];
	while(target[i]){
		if(target[i]==try[i]){
			hint[i]=try[i];
		} else {
			hint[i]='#';
		}
		i++;
	}
	printf("%s\n",hint);
}

int main(){
	showhint("1234","1234");
	showhint("1234","1289");
	showhint("1234","5294");
	showhint("1234","6789");
	return 0;
}
