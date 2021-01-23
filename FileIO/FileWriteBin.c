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


    if((fptr=fopen("numbers.bin","wb"))==NULL)
    {
        printf("Error opening file for writing in binary mode");
        exit(1);                                        //exits the program
    }

    for(num=1; num<5; ++num)
    {
        number.num1 = num;
        number.num2 = 2*num;
        number.num3 = 3*num;

        //fwrite(address_data,size_data,numbers_data,pointer_to_filte)
        fwrite(&num, sizeof(struct threeNumb), 1, fptr);
    }
    

    fclose(fptr);                                       //Closing the file

}