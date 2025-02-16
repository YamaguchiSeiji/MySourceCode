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
#define S 15000
#define SAMPLE_RATE 44100

void piano(double, double);

int main(){
	piano(C, 0.5);
	piano(D, 0.5);
	piano(E, 0.5);
	piano(F, 0.5);
	piano(E, 0.5);
	piano(D, 0.5);
	piano(C, 0.5);
	piano(0, 0.5);
	piano(E, 0.5);
	piano(F, 0.5);
	piano(G, 0.5);
	piano(A, 0.5);
	piano(G, 0.5);
	piano(F, 0.5);
	piano(E, 0.5);
	piano(0, 0.5);
	return 0;
}

void piano(double f, double time){
	double t;
	double y, y1, y2, y3, y4, y5;
	double theta1=0,theta2=0,theta3=0,theta4=0,theta5=0;
	for(t = 0; t <= time * SAMPLE_RATE; t++){
		y1 = S * sin(theta1);
		y2 = S/2 * sin(theta2);
		y3 = S/3 * sin(theta3);
		y4 = S/4 * sin(theta4);
		y5 = S/5 * sin(theta5);

		printf("%d\n%d\n", (short)y, (short)y);
		theta1 += 2.0 * M_PI * f / SAMPLE_RATE;
		theta2 += 2.0 * M_PI * f * 2 / SAMPLE_RATE;
		theta3 += 2.0 * M_PI * f * 3 / SAMPLE_RATE;
		theta4 += 2.0 * M_PI * f * 4 / SAMPLE_RATE;
		theta5 += 2.0 * M_PI * f * 5 / SAMPLE_RATE;

		y = y1 + y2 + y3 + y4 + y5;
	}
}
