#include <stdio.h>
#include <math.h>
#define F 440
#define LEN 2
#define A 20000
#define SAMPLE_RATE 44100

int main(){
	double t;
	double y = A;
	double T = (1/F)/2.0;

	for(t=0; t<=LEN; t+=1.0 / SAMPLE_RATE){
		if(A * sin(2.0 * M_PI * F *t)>=0){
			y = -A;
		} else {
			y = A;
		}
		printf("%d\n%d\n", (short)y, (short)y);
	}
	return 0;

}
