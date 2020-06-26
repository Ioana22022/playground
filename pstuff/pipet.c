#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void childProc();
void parentProc();

char buf[25];
char *msg = "HII";
int fd[2];
int status;

int main()
{
	
	pid_t cpid;
	
	if(pipe(fd) < 0) { perror("pipe"); exit(1); }

	cpid = fork();
	if (cpid == -1) { perror("fork"); exit(2); }

	else if(cpid == 0) childProc();
	
	else if(cpid > 0) parentProc();
 

	return 0;
}

void childProc(){
 //Code for reading from parent
 /*
	close(fd[1]);
	int n = read(fd[0], &buf, 25);
 	write(STDOUT_FILENO, &buf, 25);

	printf("n is %d\n", n);
	printf("Child out\n");
	
	close(fd[0]);
*/

 //Code for sending to parent
 close(fd[0]);
 write(fd[1], msg, strlen(msg));
 printf("\nI wrote to father!\n");
 close(fd[1]);	
		

}

void parentProc(){
 //Code for writing to child

/*
	close(fd[0]);
	write(fd[1], msg, strlen(msg));
	printf("I wrote to child this: %s", msg);
	write(STDOUT_FILENO, "\n", 1);
	close(fd[1]);
	wait(&status);
*/
 //Code for eading from child
	close(fd[1]);
	int n = read(fd[0], &buf, 25);
	write(STDOUT_FILENO, buf, 25);
	printf("I got from son!");
	wait(&status);
}
