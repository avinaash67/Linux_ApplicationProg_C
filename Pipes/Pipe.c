#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	// Two descriptors for 2 ends of the pipe; Read end = fd[]0; Write end = fd[1]
	int fd[2];

	if(pipe(fd)==-1){
		printf("Error ocurred when opening pipe\n");
		return 1;
	}

	//Forking child process
	int id = fork();

	if(id==-1){
		printf("error Forking child\n");
	}
	if(id==0){
		//Child process execution
		close(fd[0]); //Closing read end of the pipe
		int x;
		printf("Input a number:\n");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(x))==1) // Writing into the pipe using the fd[1]
		{
			printf("Error occurred when writing into pipe\n");
			return 2;
		}
		close(fd[1]); //Closing the write end of the pipe
	}
	else{
		//Parent process execution
		close(fd[1]);
		int y;
		if(read(fd[0],&y,sizeof(y))==-1) //Reading from the pipe using fd[0]
		{
			printf("Error reading when reading from pipe\n");
			return 3;
		}
		close(fd[0]);
	printf("Value got from child process through the pipe %d\n", y);

	}

	return 0;
}