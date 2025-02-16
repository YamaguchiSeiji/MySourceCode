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

void sound(double, double, double, double, double, double);

int main(){
	double t;

	sound

	return 0;
}

void sound(double f1, double f2, double f3, double f4, double f5 double time){
	double t;
	double y, y1, y2, y3, y4, y5;
	double theta = 0.0;
	for(t = 0; t <= time; t += 1.0/SAMPLE_RATE){
		y1 = A * sin(2.0 * M_PI * f1 * t);
		y2 = A * sin(2.0 * M_PI * f2 * t);
		y3 = A * sin(2.0 * M_PI * f3 * t);
		y4 = A * sin(2.0 * M_PI * f4 * t);
		y5 = A * sin(2.0 * M_PI * f5 * t);

		y = y1 + y2 + y3 + y4 + y5;

		printf("%d\n%d\n", (short)y, (short)y);
	}
	
}
