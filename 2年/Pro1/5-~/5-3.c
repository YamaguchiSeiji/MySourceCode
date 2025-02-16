#include <stdio.h>
int main(){
	for(int i=1; i<=16; i++){
		for(int n=1; n<=16; n++){
			printf(" %3d",n*i);
		}
		puts(" ");
	}
	return 0;
}

