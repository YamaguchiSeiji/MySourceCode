#include <stdio.h>

int eqaul(int x,int y,int z){
	if(x==y&&y==z){
		return 2;
	} else if(x==y||y==z||x==z){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int x,y,z;
	printf("3つの値を入力してください：");
	scanf("%d %d %d",&x,&y,&z);
	printf("equalの戻り値: %d\n",eqaul(x,y,z));
	if(eqaul(x,y,z)==2){
		puts("すべての値が等しいです。");
	} else if(eqaul(x,y,z)==1){
		puts("3つのうち、2つが等しいです。");
	} else {
		puts("すべて異なる値です。");
	}
	return 0;
}
