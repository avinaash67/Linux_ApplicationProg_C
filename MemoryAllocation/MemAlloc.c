#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	/* code */
	int* ptr;
	int num, sum=0;

	// Memory allocation 
	num =8;
	printf("We have %d elements to allocate memory to \n",num);

	//Malloc syntax ptr=(cast-type*) malloc(byte-size)
	ptr= (int*)malloc(num*sizeof(int));

	//Check if memory is allocated
	if(ptr==NULL)
	{
		printf("Memory allocation failed");
		exit(1);
	}
	else
	{
		printf("Memory allocation has been successful");
	}

	//Saving '0' to '7' in the integer pointer created
	for(int i = 0; i < num; ++i)
	{
		ptr[i]=i+1;
	}
	printf("insertion of numbers in the pointer successful\n");

	//Printing the inserted elements
	for(int i=0; i<num; ++i)
	{
		printf("%d,", ptr[i]);
	}

	//Clearing the pointer using free method
	free(ptr);
	printf("\nMemory allocation in the pointer has been cleared\n");


	//Reallocating the memory
	ptr = realloc(ptr, 16* sizeof(int));
	printf("Memory has been reallocated\n");


	return 0;
}