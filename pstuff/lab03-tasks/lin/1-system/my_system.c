#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int my_system(const char* cmd){

	pid_t pid;
	int status;
	const char* argv[] = {cmd, NULL};
	pid = fork();

	switch(pid){
	case -1:
		return EXIT_FAILURE;
	case 0:
		execvp(cmd, (char* const) argv[]);
		exit(EXIT_FAILURE);

	default:
		break;

	}

	waitpid(pid, &status, 0);
	if(WIFEXITED(status)) 
		printf("Child %d terminated normally, existed with code %d\n", pid, WEXITSTATUS(status));
	return status;
}

int main(int args, char **argv){
	my_system(argv);
	return 0;

}
