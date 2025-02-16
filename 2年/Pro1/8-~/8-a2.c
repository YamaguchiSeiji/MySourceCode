#include <stdio.h>
#define LEN 5

double average(int v[],int len){
	double sum=0;
	for(int i=0; i<len; i++){
		sum+=v[i];
	}
	return sum/len;
}
double variance(int v[], int len, double ave){
	double sum=0;
	for(int i=0; i<len ;i++){
		sum+=(v[i]-ave)*(v[i]-ave);
	}
	return sum/len;
}

int main(){
	int x[LEN];
	printf("%dつの整数を入力してください：\n",LEN);
	for(int i=0; i<LEN; i++){
		scanf("%d",&x[i]);
	}
	printf("平均: %.1f\n",average(x,LEN));
	printf("分散: %.1f\n",variance(x,LEN,average(x,LEN)));
	return 0;
}
