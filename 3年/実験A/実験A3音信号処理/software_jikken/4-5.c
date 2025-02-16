#include <stdio.h>
#include <math.h>
#define C 261.63 //ド
#define D 293.66 //レ
#define E 329.63 //ミ
#define F 349.23 //ファ
#define G 392.00 //ソ
#define A 440.00 //ラ
#define B 493.88 //シ
#define C2 523.25
#define LEN 8
#define S 20000
#define SAMPLE_RATE 44100

void sound(double, double);

int main(){
	double t;
	sound(C, 0.5);
	sound(D, 0.5);
	sound(E, 0.5);
	sound(F, 0.5);
	sound(E, 0.5);
	sound(D, 0.5);
	sound(C, 0.5);
	sound(0, 0.5);

	sound(E, 0.5);
	sound(F, 0.5);
	sound(G, 0.5);
	sound(A, 0.5);
	sound(G, 0.5);
	sound(F, 0.5);
	sound(E, 0.5);
	sound(0, 0.5);

	sound(C, 0.5);
	sound(0, 0.5);
	sound(C, 0.5);
	sound(0, 0.5);
	sound(C, 0.5);
	sound(0, 0.5);
	sound(C, 0.5);
	sound(0, 0.5);


	sound(C, 0.25);
	sound(C, 0.25);
	sound(D, 0.25);
	sound(D, 0.25);
	sound(E, 0.25);
	sound(E, 0.25);
	sound(F, 0.25);
	sound(F, 0.25);
	sound(E, 0.5);
	sound(D, 0.5);
	sound(C, 0.5);
	sound(0, 0.5);

	return 0;
}

void sound(double f, double time){
	double t;
	double y;
	double theta = 0;
	for(t = 0; t <= time * SAMPLE_RATE; t++){
		y = A * sin(theta);
		printf("%d\n%d\n", (short)y, (short)y);
		
		theta +=  2.0 * M_PI * f / SAMPLE_RATE;
	}	
}
