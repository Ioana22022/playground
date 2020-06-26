#include<stdio.h>

int main()
{
	int v[] = {1, 2, 3, 4, 5, 9};
	int max = v[0];
	int i = 0;

/*	for(i = 0; i < sizeof(v)/sizeof(v[0]); i++)
	{
		if(v[i] > max)
			max = v[i];
	}
*/

check:
	if(v[i] > max)
		max = v[i];
	i++;

	if(i < sizeof(v)/sizeof(v[0]))
		goto check;
			
	printf("%d", max);
}
