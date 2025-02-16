#include <stdio.h>
int main(){
	int n,m,sum=0;
	scanf("%d %d",&n,&m);
	for(int i=n; i<=m; i++){
		printf("%d",i);
		sum+=i;
		if(i==m)break;
		printf(" + ");
	}
	if(m>=n){
		printf(" = ");
	}
	printf("%d\n",sum);
	return 0;
}
