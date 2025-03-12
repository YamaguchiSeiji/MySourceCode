#include <stdio.h>
#include <stdlib.h>

void output(int[], int);

int main(){
	int data[100];
	int n;
	FILE *fp;
	
	if((fp = fopen("data_int_only", "rb")) == NULL){
		printf("cannot file open.");
		exit(1);
	}

	n = fread(data, sizeof(int), 100, fp);
	
	output(data, n);

	fclose(fp);

	return 0;	
}

void output(int data[], int n){

	for(int i=0; i < n; i++){
		printf("%d ", data[i]);
		if((i + 1) % 5 == 0){
			puts("");
		}
	}

}
