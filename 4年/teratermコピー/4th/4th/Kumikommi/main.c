#include <stdio.h>
#include "func.h"

double x;

int main(void){
	double t;

	t = 30.0;

	x = mysin(t);

	printf("t=%lf, x=%lf\n", t, x);

	return 0;
}
