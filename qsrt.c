#include<stdio.h>
#include<stdlib.h>

int values[] = {80, 25, 56, 100, 2, 3};

int cmpfunc(const void* a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{

	int numval = (int)(sizeof(values)/sizeof(values[0]));
	int i;

	printf("Values before: ");
	for(i = 0; i < numval; i++)
	{
		
		printf("%d ", values[i]);	
	}
	qsort(values, numval, sizeof(int), cmpfunc);

	printf("Values after: ");
	for(i = 0; i < numval; i++)
	{
		
		printf("%d ", values[i]);	
	}

 
 return 0;
}
