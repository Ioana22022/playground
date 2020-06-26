#include<stdio.h>

int search(int x, int v[], int n, int low, int high)
{
	int mid;
	//int low = 0, high = n - 1;

	mid = (low + high) / 2;

	if(x == v[mid])
		return mid;

	else if(x < v[mid])
	{
		//low = mid + 1;
		return search(x, v, n, mid + 1, high);
	}

	else
	{
		return search(x, v, n, low, mid - 1);
	}
	
	return -1;
}

int main()
{
	int v[] = {1, 2, 3, 9, 9, 9};
	int n = sizeof(v)/sizeof(v[0]);
	int low = 0;
	int high = n - 1;
	int ret = v[0];
	int mid;
	
	/*harcoded search*/
	int x = 3;
check_middle:

	mid = (low + high) / 2;	
	if(x == v[mid])
	{
		ret = mid;
		goto end;
	}
	//printf("%d", search(3, a, n, 0, n - 1));
	
	if(x < v[mid])
	{
		low = mid + 1;
		goto check_middle;
	}

	if(x > v[mid])
	{
		high = mid - 1;
		goto check_middle;
	}

end:
	printf("%d ", ret);
	return 0;
	
}
