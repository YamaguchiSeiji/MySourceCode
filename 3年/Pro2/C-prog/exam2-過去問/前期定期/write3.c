#include <stdio.h>

int main(){
	FILE *fp;
	int tmp;

	fp = fopen("data_int", "rb");
	
	fseek(fp, -2*sizeof(int), SEEK_END);

	fread(&tmp, sizeof(int), 1, fp);
	printf("data = %d\n", tmp);

	fclose(fp);

	return 0;
}
