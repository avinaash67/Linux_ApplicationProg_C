#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	int res = mkdir("./C_Created_Folder",0777);

	if (res ==0)
	{
		printf("Creation of directory successful\n");
	}
	else
	{
		printf("creation of directory failed\n");
	}

	sleep(5);


	char diretoryPath[] = "./C_Created_Folder";

	if(rmdir(diretoryPath) != 0)
	{
		perror("rmdir() could not remove directory\n");
	}
	else
	{
		puts("directory removed\n");
	}

	return 0;
}