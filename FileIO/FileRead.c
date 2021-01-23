#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num;
    FILE *fptr;                                         //File pointer
                   

    if((fptr=fopen("file.txt","r"))==NULL)              //Opening file in read mode
    {
        printf("Error opening file");
        exit(1);                                        //exits the program
    }
                          
    fscanf(fptr,"%d",&num);
    printf("Value of num = %d\n", num);    
    fclose(fptr);                                       //Closing the file


}