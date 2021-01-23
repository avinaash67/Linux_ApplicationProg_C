#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //header file included to find the processID


int main()
{
	int proc_id, parent_proc_id;

	proc_id = getpid(); 								//Get process ID
	parent_proc_id=getppid();							//Get parent process ID

	printf("Process ID = %d\n", proc_id);
	printf("Parent Process ID = %d\n",parent_proc_id);
	

}