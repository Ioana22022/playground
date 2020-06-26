#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum){

	switch(signum){
		case SIGINT:
			printf("CTRL+C received in %d, exiting\n", getpid());
			exit(EXIT_SUCCESS);

		case SIGUSR1:
			printf("SIGUSR1 received;\n");
	


	}
}




int main()

{

	printf("Process %d started\n", getpid());

	if (signal(SIGKILL, signal_handler) == SIG_ERR)
		printf("You shall not catch me, SIGKILL");

	if (signal(SIGINT, signal_handler) == SIG_ERR){

		printf("Unable to catch SIGINT");
		exit(1);
	}

	if (signal(SIGUSR1, signal_handler) == SIG_ERR){
			
		printf("Unable to catch SIGUSR1");
		exit(2);
	}

	printf("Press Ctr+C to stop me");

	while(1) sleep(1);
	return 0;

}
