#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct coord{
	double x;
	double y;
} COORD;

COORD input_coord(FILE*);
void output_coord(double);
double length(COORD, COORD);
void change(double[], int);

COORD a, *p;

int main(){
	p = &a;
	
	FILE *fp;
	int n;
	fp = fopen("9-1_data", "r");
	if(fp == NULL){
		puts("file cannot open");
		exit(1);
	} 
		fscanf(fp, "%d", &n);
		double len[n];
		COORD vector[n];	
		vector[0] = input_coord(fp);
		for(int i=1; i<n; i++){
			vector[i] = input_coord(fp);
			len[i-1] = length(vector[i-1], vector[i]);
			if(i == n-1){
				len[i] = length(vector[i], vector[0]);
			}
		}
		
		change(len, n);
		
		output_coord(len[1]);
	



	return 0;
}

COORD input_coord(FILE *fp){
	fscanf(fp, "%lf %lf", &a.x, &a.y);
	return a;
}

double length(COORD vec1, COORD vec2){
	return sqrt(pow((vec1.x - vec2.x), 2) + pow((vec1.y - vec2.y), 2));
}

void output_coord(double len){
	printf("len = %.2f\n", len);
}

void change(double len[], int n){
	double num;

	for(int i=1; i<n; i++){
		if(len[i-1] > len[i]){
			num = len[i];
			len[i] = len[i-1];
			len[i-1] = num;
			i=0;
		}
	}
}
