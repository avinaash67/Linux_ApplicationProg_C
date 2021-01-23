#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char  **argv)
{
	int fd =inotify_init();
	char buf[sizeof(struct inotify_event) + NAME_MAX + 1]; 
	struct inotify_event *myevent;

	if(fd<0)
	{
		printf("inotity_init() failed\n");
		return(-1);
	}
	
	// man inotify_add_watch
	int watchfd = inotify_add_watch(fd, argv[1], IN_MODIFY|IN_DELETE);
	printf("%d", watchfd);

	// Read about read(2) from linux man page
	while(1)
	{
		read(fd, buf, sizeof(buf)); // This function is able to read the events and stores the value into buf
		myevent = (struct inotify_event*) buf; //Casting the buf into inotify_event structure

		if(myevent->len > 0)
		{
			printf("File modified %s\n", myevent->name);
		}	

	}

}