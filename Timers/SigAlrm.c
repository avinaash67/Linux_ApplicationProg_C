#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>


void wakeUpFunction()
{
	printf("Sig alarm handler function\n");
}

int main(int argc, char const *argv[])
{
	int i;

	struct sigaction action;
	sigemptyset(&action.sa_mask);
	action.sa_handler = (void (*) (int))wakeUpFunction;
	action.sa_flags = SA_RESTART;

	if(sigaction(SIGALRM,&action,0)==1)
	{
		perror("sigaction error");
	}


	while(1){
		alarm(5);
		pause();
		printf("Waiting for alarm\n");
	}

	return 0;
}