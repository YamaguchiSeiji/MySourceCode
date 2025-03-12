#include <stdio.h>
int main(){
	  //1,5,10,50,100,500
	int a,b,c,d,e,f;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	if(a+b*5+c*10+d*50+e*100+f*500>=1000){
		puts("1");
	} else {
		puts("0");
	}
	return 0;
}
