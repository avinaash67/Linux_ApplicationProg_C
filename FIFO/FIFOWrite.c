#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	if(mkfifo("myfifo1",0777)==-1) // Creating a FIFO with access to all '0777'
		{
		if(errno != EEXIST)
		{
			printf("Could not create FIFO file\n" );
			return 1;
		}
	}

	int fd = open("myfifo1", O_WRONLY); //opening FIFO in write only mode
	
	int x = 97;
	if(write(fd, &x, sizeof(x))== -1) //Writing into FIFO
	{
		printf("Error Writing into FIFO");
		return 2;
	}

	close(fd); // Closing FIFO
	printf("FIFO has been closed\n");
	return 0;
}