#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	double y;
	double r;
	int i;

	srandom(time(NULL));

	for(i = 0; i < 44100 * 2; i++){
		r = random();
		y = 15000.0 * (r / RAND_MAX - 0.5);
		printf("%d\n%d\n", (short)y, (short)y);
	}

	return 0;
}
