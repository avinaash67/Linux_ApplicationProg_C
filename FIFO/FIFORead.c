#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
	int fd = open("myfifo1", O_RDONLY); //opening FIFO in write only mode
	
	if(fd == -1)
	{
		printf("Opening FIFO failed\n");
	}

	int x;
	if(read(fd, &x,sizeof(x))==-1)
	{
		printf("Reading FIFO failed\n");
	}
	printf("Data Recieved = %d\n", x);
	close(fd);

	return 0;
}