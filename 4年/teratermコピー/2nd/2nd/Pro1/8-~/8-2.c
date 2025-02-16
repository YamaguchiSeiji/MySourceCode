#include <stdio.h>
void greetings(int m,int n){
	for(int i=0; i<n; i++){
		if(m==0)
			puts("Hello!");
		else
			puts("Hi!");
	}
}

int main(){
	greetings(0,3);
	greetings(1,2);
	return 0;
}
