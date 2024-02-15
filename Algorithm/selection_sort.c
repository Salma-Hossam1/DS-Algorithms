#include <stdio.h>
#include <stdlib.h>

void Swap_Two_Num (int *num1 ,int *num2);
void display (int arr[],int arr_length);
void Selection_Sort (int arr[],int arr_length);

void Swap_Two_Num (int *num1 ,int *num2)
{
    int temp =*num1;
    *num1 = *num2;
    *num2 = temp;
}

void display (int arr[],int arr_length)
{
    for(int i=0;i<arr_length;i++)
    {
        printf("%i\t",arr[i]);
    }
}

void Selection_Sort (int arr[],int arr_length)
{
    int minimum_index=0;
    for(int i=0;i<arr_length-1;i++)
    {
        minimum_index=i;
        for(int j=i+1;j<arr_length;j++)
        {
            if(arr[j]<arr[minimum_index])
            {
                minimum_index=j;
            }
            else{}
        }
        Swap_Two_Num(&arr[minimum_index],&arr[i]);
    }
}
