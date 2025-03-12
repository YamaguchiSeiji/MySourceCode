#include <stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	if(a<0||b<0){
		puts("Error");
	} else {
		printf("%.1f\n",(a+b)/2.0);
	}
	return 0;
}
