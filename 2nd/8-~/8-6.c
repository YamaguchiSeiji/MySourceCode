#include <stdio.h>
int getmul3num(int v[],int len){
	int num=0;
	for(int i=0; i<len; i++){
		if(v[i]%3==0){
			num++;
		}
	}
	return num;
}
int main(){
	int x[6]={10,8,3,14,15,26};
	int count;
	count=getmul3num(x,6);
	printf("3の倍数の値は%d個含まれています。\n",count);
	return 0;
}
