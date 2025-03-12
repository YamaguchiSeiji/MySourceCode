#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *xp;

	printf("*xp = %d\n", *xp);
	xp = (int *) malloc(sizeof(int));

	if(xp == NULL){
		
	}
	
	printf("*xp = %d\n", *xp);
	

	*xp = 10;

	printf("*xp = %d\n", *xp);

	free(xp);

	return 0;
}
