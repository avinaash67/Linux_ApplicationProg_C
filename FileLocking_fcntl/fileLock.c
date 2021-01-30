#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
					/*l_type	l_whence,	lstart,  l_pid*/
	struct flock fl = {F_UNLCK, SEEK_SET, 0, 100, 0};   // Creating an instance of flock structure
	int fd;


	if((fd= open("test.txt",O_RDWR))==-1){
		perror("Error opening file");
		exit(1);
	}
	printf("File opened in Read-Write mode");
	printf("Press enter to lock file\n");
	printf("****************************\n");

	getchar();

	fl.l_type = F_WRLCK; 	// Replacing F_UNLCK with F_WRLCK; Replacing FileUnlock with FileWriteLock
	fl.l_pid = getpid();		// Replacing process id '0' with the process id of the current process

	//Setting lock using fcntl function
	if((fcntl(fd,F_SETLK, &fl))==-1){
		perror("Cannot set exclusive lock");
	}
	else if(fl.l_type !=F_UNLCK){	//if the file is locked, then print the process if (PID) of the process that is locking the file 
		printf("File locked by another process %d\n",fl.l_pid);
	}
	else{
		printf("file has been locked by current process = %d\n", getpid());
	}
	printf("press key to unlock the file\n");

	getchar();

	printf("File has been unlocked\n");
	
	return 0;
}