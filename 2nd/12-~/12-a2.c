#include <stdio.h>
void swap(int *px, int *py){
	int num;
	num=*px;
	*px=*py;
	*py=num;
}

void sort3(int *x,int *y,int *z){
	while(*x>*y||*y>*z){
		if(*x>*y)
			swap(x,y);
		if(*y>*z)
			swap(y,z);
		if(*x>*z)
			swap(x,z);
	}
}

int main(){
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	sort3(&x,&y,&z);
	printf("%d %d %d\n",x,y,z);
	return 0;
}
