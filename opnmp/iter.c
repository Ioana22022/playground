#include "util.h"

int main(void)
{
	int i;
	double x, sum = 0.0;

	for (i = 0; i < STEPS; i++)
	{
		x = (i - 0.5)/(double)STEPS;
		sum += 4.0/(1.0 + x*x);
		
		//( (i + 1) % 2 ) ? (sum -= 1.0/(2 * i - 1)) : (sum += 1.0/(2 * i - 1));
		
	}
	printf("res = %lf", sum / (double)STEPS);
	return 0;
}
