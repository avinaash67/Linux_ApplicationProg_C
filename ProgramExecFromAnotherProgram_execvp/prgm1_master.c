#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	
	char *args[] = {"./prgm1Slave",NULL}; //path to binary to be executed
	execvp(args[0],args);

	printf("I am replaced by another binary file, So I wont be printed\n");
	return 0;
}