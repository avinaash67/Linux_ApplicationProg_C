#include<stdio.h>
#include<sys/statvfs.h>

int main(int argc, char const *argv[])
{
	struct statvfs buf;

	if(statvfs(".", &buf)==-1){
		perror("error");
	}
	else
	{
		printf("Each block of this file system has a size of %ld bytes\n", buf.f_frsize); //Prints block size of a file system. This is given by f_frsize
		printf("There are %ld blocks available out of %ld \n",buf.f_bavail, buf.f_blocks); // 
	}

	return 0;
}