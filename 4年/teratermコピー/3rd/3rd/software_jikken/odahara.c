#include <stdio.h>
#include <math.h>
#include <time.h>

#define BM 73.416
#define DM 87.307
#define EM 97.99
#define FM 110
#define GM 123.471
#define AL 138.59
#define BL 146.83
#define CL 164.81

#define DL 174.61
#define EL 195.99
#define FL 220
#define GL 246.94
#define A 261.63 //音階
#define B 293.66
#define C 329.63
#define D 349.23
#define E 392.00
#define F 440.00
#define G 493.88
#define AH 523.25
#define BH 587.33
#define CH 659.26
#define DH 698.46
#define EH 783.99
#define FH 880
#define GH 987.77
#define SAMPLE_RATE 44100 // wav ファイルのサンプリング周波数
void sound(double,double,double,double,double,double);
int main(){
double hanon=1.059463;
sound(B,FL*hanon,0,0,0,0.5);
sound(B*hanon,A,0,0,0,0.5);
sound(B,FL*hanon,0,0,0,0.5);
sound(B*hanon,A,0,0,0,0.5);
sound(B,FL*hanon,0,0,0,0.5);
sound(B*hanon,A,0,0,0,0.5);
sound(A,FL,0,0,0,0.5);
sound(B,FL*hanon,0,0,0,0.5);
sound(A,FL,0,0,0,0.5);
sound(B,FL*hanon,0,0,0,0.5);
sound(A,FL,0,0,0,0.5);
sound(B,FL*hanon,0,0,0,0.5);

sound(FL*hanon,EL,0,0,0,0.5);
sound(A,FL,0,0,0,0.5);
sound(FL*hanon,EL,0,0,0,0.5);
sound(A,FL,0,0,0,0.5);
sound(FL*hanon,EL,0,0,0,0.5);
sound(A,FL,0,0,0,0.5);
sound(FL,DL*hanon,0,0,0,0.5);
sound(EL,BL*hanon,0,0,0,0.5);
sound(DL*hanon,BL,0,0,0,1.5);
sound(0,0,0,0,0,0.25);
sound(BM,0,0,0,0,2);
sound(FM,BM,0,0,0,0.25);
sound(BL,BM,0,0,0,0.25);
sound(DL*hanon,BM,0,0,0,0.25);
sound(FL,BM,0,0,0,0.25);
sound(B,BM,0,0,0,0.25);
sound(D*hanon,BM,0,0,0,0.25);
sound(E*hanon,BM,0,0,0,0.25);
sound(FL,BM,0,0,0,0.25);
sound(B,BM,0,0,0,0.25);
sound(D*hanon,BM,0,0,0,0.25);
sound(F,BM,0,0,0,0.25);
sound(AH,BM,0,0,0,3);
sound(0,0,0,0,0,3);
sound(B,0,0,0,0,1);
sound(E,0,0,0,0,1);
sound(F*hanon,0,0,0,0,1);
sound(BH,FL*hanon,BL*hanon,0,0,1);
sound(0,0,0,0,0,1);
sound(BH,0,0,0,0,1);
sound(AH,D,C,B,0,1);
sound(F*hanon,0,0,0,0,1);


sound(F,0,0,0,0,1);
sound(F*hanon,0,0,0,0,3);
sound(0,0,0,0,0,1.5);
sound(E,0,0,0,0,0.5);
sound(F*hanon,0,0,0,0,0.5);
sound(BH,0,0,0,0,0.5);
sound(EH,BH,F*hanon,0,0,2);
sound(EH,0,0,0,0,1);
sound(EH,AH,F,0,0,1);
sound(FH,0,0,0,0,1);
sound(DH,0,0,0,0,0.5);
sound(BH*hanon,0,0,0,0,0.5);
sound(DH,BH,F,0,0,3);
sound(0,0,0,0,0,1.5);
sound(F,0,0,0,0,0.5);
sound(BH,0,0,0,0,0.5);
sound(DH,0,0,0,0,0.5);
sound(FH,BH,F*hanon,0,0,2);
sound(EH,BH,F*hanon,0,0,1);
sound(DH,AH,C,0,0,1);
sound(CH,0,0,0,0,1);
sound(DH,EH,0,0,0,1);
sound(EH,AH,F,0,0,2);
sound(DH,0,0,0,0,1);
sound(CH,F,D,0,0,2);
sound(BH,0,0,0,0,1);
sound(AH,D,B,0,0,1);
sound(F*hanon,0,0,0,0,1);
sound(AH,0,0,0,0,1);
sound(BH,E,C,0,0,1);
sound(AH,0,0,0,0,1);
sound(E,0,0,0,0,1);
sound(F,0,0,0,0,1);
sound(0,0,0,0,0,0.5);

sound(B,0,0,0,0,0.5);
sound(E,0,0,0,0,0.5);
sound(F,0,0,0,0,0.5);
sound(B*hanon,B,A,FL,DL*hanon,3);
sound(0,0,0,0,0,2);

return 0;
}
void sound(double o,double p,double q,double r,double s,double time){
static double thetao=0,thetap=0,thetaq=0,thetar=0,thetas=0,o2=0,p2=0
,q2=0,r2=0,s2=0;
double t,sum,a=1700,b=0;
double yo,yp,yq,yr,ys;
for (t = 0; t <= time * SAMPLE_RATE/2; t++){
if(o==BM || p==BM )
a=2500;
if(o==0){
thetao += 2.0 * M_PI * o2 /SAMPLE_RATE;
thetap += 2.0 * M_PI * p2 /SAMPLE_RATE;
thetaq += 2.0 * M_PI * q2 /SAMPLE_RATE;
thetar += 2.0 * M_PI * r2 /SAMPLE_RATE;
thetas += 2.0 * M_PI * s2 /SAMPLE_RATE;
if(a>b)
b = a/(time * SAMPLE_RATE) *t*4;
}
yo= (a-b) * sin(thetao);
yp= (a-b) * sin(thetap);
yq= (a-b) * sin(thetaq);
yr= (a-b) * sin(thetar);
ys= (a-b) * sin(thetas);
sum =yo+yp+yq+yr+ys;
if(sum>=30000 && sum<100000){
sum=2767/70000*(sum-30000)+30000;
}

else if(sum>100000)
sum=32767;
if(sum<= -30000 && sum>-100000){
sum=-2767/70000*(sum+30000)-30000;
}
else if(sum<-100000)
sum=-32767;
printf("%d\n%d\n", (short)sum, (short)sum);
thetao += 2.0 * M_PI * o*2 /SAMPLE_RATE;
thetap += 2.0 * M_PI * p*2 /SAMPLE_RATE;
thetaq += 2.0 * M_PI * q*2 /SAMPLE_RATE;
thetar += 2.0 * M_PI * r*2 /SAMPLE_RATE;
thetas += 2.0 * M_PI * s*2 /SAMPLE_RATE;
}
o2=o;
p2=p;
q2=q;
r2=r;
s2=s;
}
