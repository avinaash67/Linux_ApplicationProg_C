#include<stdio.h>
#include<stdlib.h>

struct threeNumb
{
    int num1,num2,num3;
};

int main()
{
    int num;
    FILE *fptr;                                         //File pointer
    struct threeNumb number;


    if((fptr=fopen("numbers.bin","rb"))==NULL)
    {
        printf("Error opening file for reading in binary mode");
        exit(1);                                        //exits the program
    }

    for(num=1; num<5; ++num)
    {
        //fread(address_data,size_data,numbers_data,pointer_to_filte)
        fread(&num, sizeof(struct threeNumb), 1, fptr);
        printf("num1: %d\tnum2: %d\t num3:%d",number.num1,number.num2,number.num3);
    }
    

    fclose(fptr);                                       //Closing the file

}