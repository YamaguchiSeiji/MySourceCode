#include <stdio.h>
int nCr(int n ,int r){
	if(n < r || r < 0){
		puts("無効な値です");
		return -1;
	} else if(r != 0 && r != n){
		return nCr(n-1,r-1) + nCr(n-1, r);
	} else {
		return 1;
	}
}

int main(){
	int n,r;
	puts("異なるn個のボールの中からr個のボールを取り出す組み合わせを求めます。");
	puts("nとrを入力してください。(n>=r,r>=0)");
	printf("n: ");
	scanf("%d",&n);
	printf("r: ");
	scanf("%d", &r);

	if(nCr(n,r) == -1){
		return 0;
	}

	printf("異なる%d個のボールの中から%d個のボールを取り出す組み合わせは\n",n,r);
	printf("%d通りあります。\n",nCr(n,r));

	return 0;
}

