#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
  

/* Id of the child process always starts with '0' and the parent process can be of any ID*/

int main(int argc, char const *argv[])
{	
	pid_t cpid; 
	int id = fork();

	if(id == 0){
		printf("Hello from child Forkid= %d\n",id);
		sleep(2);
        exit(0);           /* terminate child */
	}
	else{
		cpid = wait(NULL); /* reaping parent once the child has ended*/
		printf("Hello from parent %d\n",getpid());
	} 
	printf("cpid %d\n",cpid);
	return 0;
}
