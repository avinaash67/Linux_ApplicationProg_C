#include<stdio.h>
#include<time.h>

void func_name()
{
	printf("Function start\n");
	printf("Press any key to stop function\n");
	for(;;)
	{
		if(getchar())
			break;
	}
	printf("Function terminated by the user\n");
}

int main(int argc, char const *argv[])
{
	/* code */

	//Inbuilt data-type clock_t
	clock_t t;

	//Getting current time using the clock() function
	t = clock();
	
	func_name();	//Calling infinite function
	
	//Calculating the time elapsed
	t=clock() - t;

	double time_taken_by_func = ((double)t)/CLOCKS_PER_SEC;

	printf("Time taken by the function before termination is = %f", time_taken_by_func);

	return 0;
}