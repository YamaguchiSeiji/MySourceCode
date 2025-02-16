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
#define GUITAR 100
void sound(double);

int main(){
	sound(2);
}

void sound(double time){
	double t;
	double y,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10;
	for(t = 0; t <= time; t += 1.0/SAMPLE_RATE){
		y1 = A/1.56 * sin(2.0 * M_PI * (140/ GUITAR) * t);
		y2 = A/2 * sin(2.0 * M_PI * (170 / GUITAR) * t);
		y3 = A/2.3 * sin(2.0 * M_PI * (185 / GUITAR) * t);
		y4 = A/1.8 * sin(2.0 * M_PI * (195 / GUITAR) * t);
		y5 = A * sin(2.0 * M_PI * (261 / GUITAR) * t);
		y6 = A/1.5 * sin(2.0 * M_PI * (393 / GUITAR) * t);
		y7 = A/1.7 * sin(2.0 * M_PI * (520 / GUITAR) * t);
		y8 = A/2 * sin(2.0 * M_PI * (650 / GUITAR) * t);
		y9 = A/2 * sin(2.0 * M_PI * (790 / GUITAR) * t);
		y10 = A/3 * sin(2.0 * M_PI * (900 / GUITAR) * t);

		y = y1 + y2 + y3 + y4 + y6 + y7 + y8 +y9 +y10;
		printf("%d\n%d\n", (short)y, (short)y);
	}	
}
