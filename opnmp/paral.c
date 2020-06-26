#include "util.h"

int main(void)
{
	int i;
	double x, sum = 0.0;
	
	omp_set_num_threads(4);
#pragma omp parallel for reduction( + : sum )

	for (i = 0; i < STEPS; i++)
	{
		x = (i - 0.5)/(double)STEPS;
		sum += 4.0/(1.0 + x*x);
	}

	printf("res = %lf", sum / (double)STEPS);
	return 0;
}
