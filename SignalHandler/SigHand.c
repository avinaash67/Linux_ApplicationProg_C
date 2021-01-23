#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void mySignalHandler(int);


int main(int argc, char const *argv[])
{
	signal(SIGINT, mySignalHandler);

	for(;;)
	{
		printf("Sleeping...\n");
		sleep(2);
	}
	return 0;
}

void mySignalHandler(int signum)
{
	printf("Signal Handler: Signal caught %d\n", signum);
	exit(1);
}