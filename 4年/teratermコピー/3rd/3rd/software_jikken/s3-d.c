#include <stdio.h>
#include <math.h>
#define F 880
#define LEN 2
#define A 5000
#define SAMPLE_RATE 44100

int main(){
	double t;
	double y;

	for(t=0; t<=LEN; t+=1.0 / SAMPLE_RATE){
		y = A * sin(2.0 * M_PI * F * t);
		printf("%d\n%d\n", (short)y, (short)y);
	}
	return 0;

}
