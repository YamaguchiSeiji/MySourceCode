#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fi;
	int ch;

	if((fi = fopen("test.txt", "r")) == NULL){
		printf("Cannot open test.txt.\n");
		exit(1);
	}

	while((ch = fgetc(fi)) != EOF){
		putchar(ch);
	}

	fclose(fi);

	return 0;
}
