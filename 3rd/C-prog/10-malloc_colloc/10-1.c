#include <stdio.h>
#include <stdlib.h>

void change(double[], int);

int main(int argc, char *argv[]){
	FILE *fp;
	int i,n;
	double *height;


	if(argc == 1){
		fp = stdin;
	} else if(argc == 2){
		fp = fopen(argv[1], "r");
		if(fp == NULL){
			printf("FILE OPEN ERROR\n");
			exit(1);
		}

	} else {
		printf("Usage: %s [filename]\n", argv[0]);
		exit(0);
	}

	fscanf(fp, "%d", &n);
	printf("n=%d\n", n);
	
	height = (double*)malloc(sizeof(double)*n);
	if(height == NULL){
		printf("malloc error\n");
	}

	for(i=0; i < n; i++){
		fscanf(fp, "%lf", &height[i]);
	}

	change(height, n);

	for(i=0; i < n; i++){
		printf("%5.1f\n",height[i]);
	}

	if(argc == 2){
		fclose(fp);
	}

	free(height);
	
	return 0;
}

void change(double height[], int n){
	double num;
	
	for(int i=1; i < n; i++){
		if(height[i-1] > height[i]){
			num = height[i];
			height[i] = height[i-1];
			height[i-1] = num;
			i=0;
		}
	}
}
