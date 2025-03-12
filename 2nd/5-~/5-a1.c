#include <stdio.h>
int main(){
	int mincm,maxcm,skipcm;
	printf("何cmから：");scanf("%d",&mincm);
	printf("何cmまで：");scanf("%d",&maxcm);
	printf("何cmごと：");scanf("%d",&skipcm);

	for(int n=mincm; n<=maxcm; n+=skipcm){
		printf("%dcm  %.2fkg\n",n,(n-100)*0.9);
	}

	return 0;
}
