#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num;
    FILE *fptr;                                         //File pointer
    fptr = fopen("file.txt","w");                       //opening file in write mode

    if(fptr==NULL)
    {
        printf("Error opening file");
        exit(1);                                        //exits the program
    }

    printf("Enter num: ");
    scanf("%d",&num);                                   // getting a number from the user

    fprintf(fptr/*pointer reference*/, "%d\n", num);    //Prints the number in the file
    fclose(fptr);                                       //Closing the file


}