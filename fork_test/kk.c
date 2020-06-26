#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	//int i = 0;
	for(int i = 0; i < 3; i++)
	{
		int pid = fork();
		switch(pid)
		{
			case 0:
				printf("(i = %d, pid = %d)\n", i, getpid());
				break;

			case -1:
				printf("Fork error");
				break;

			default:
				printf("(i = %d, pid = %d)\n", i, getpid());
				break;
		}
	}
	return 0;
}
