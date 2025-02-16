#include <math.h>
#include "func.h"

double mysin(double t)
{
	double ans;

	ans = sin(t*M_PI/180.0);

	return ans;
}
