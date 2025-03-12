#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *xp;

	//xp = (int *) malloc(sizeof(int));
	xp = (int *) calloc(1, sizeof(int));

	printf("*xp = %d\n", *xp);
	*xp = 10;

	printf("*xp = %d\n", *xp);

	free(xp);

	return 0;
}
