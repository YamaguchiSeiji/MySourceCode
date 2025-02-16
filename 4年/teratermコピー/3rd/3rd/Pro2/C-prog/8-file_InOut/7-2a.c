#include <stdio.h>
#include <stdlib.h>

void output(double [], int);

int main(){
	double data[100];
	int n;
	int i;
	FILE *fp;
	
	if((fp = fopen("data7_2", "wb")) == NULL){
		printf("file cannot open:data7_2\n");
		exit(1);
	}

	for(i=0; scanf("%lf",&data[i]) != EOF; i++){
		if(i >= 100)exit(1);
	}
	
	n = i;

	printf("data count = %d\n", n);
	fwrite(&n, sizeof(int), 1, fp);	
	output(data, n);
	fwrite(data, sizeof(double), n, fp);


	return 0;
}

void output(double data[], int n){
	for(int i=0; i < n; i++){
		printf("%f " , data[i]);
		if(i % 5 == 4)printf("\n");
	}
	printf("\n");
}
