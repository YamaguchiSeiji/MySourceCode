#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

double dist(double, double, double, double);

int main(int ac, char *av[]){
	FILE *fp1, *fp2;
	int n;
	double data[100];
	double len;

	if(ac <= 2){
		puts("Usage: ./a.out filename1 filename2");
		exit(1);
	} else if(ac == 3){
		if((fp1 = fopen(av[1], "rb")) == NULL){
			printf("file open error: %s\n", av[1]);
			exit(1);
		}
		if((fp2 = fopen(av[2], "wb")) == NULL){
			printf("file open error: %s\n", av[2]);
			exit(1);
		}

		n = fread(data, sizeof(double), 100, fp1);
		for(int i = 0; i < n; i++){
			printf("%5.2f", data[i]);
			if(i % 2 == 1) puts("");
		}
		puts("");

	}
	
		for(int i = 0; i < n+2; i++){
			if(i % 2 == 1 && i >= 3){	
				if(i == n+1){
					len = dist(data[0], data[i-3], data[i-2], data[1]);
				} else {
					len = dist(data[i-3], data[i-1], data[i-2], data[i]);
				}
				printf("%.6f\n", len);
				fwrite(&len, sizeof(double), 1, fp2);
			}
		}
	fclose(fp1);
	fclose(fp2);
	return 0;

}

double dist(double x1, double x2, double y1, double y2){
	return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
}
