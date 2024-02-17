#include <stdio.h>
#include <stdlib.h>

void Swap_Two_Num (int *num1 ,int *num2);
void display (int *list,int list_length);
void Selection_Sort (int *list,int list_length);

int arr[10]={12, 85, 96, 3, 7, 100, 36, 205, 9, 71};

int main ()
{
    printf("Array before sorting : ");
    display (arr,10);
    Selection_Sort(arr,10);
    printf("\n");
    printf("Array After sorting : ");
    display (arr,10);
}
void Swap_Two_Num (int *num1 ,int *num2)
{
    int temp =*num1;
    *num1 = *num2;
    *num2 = temp;
}

void display (int *list,int list_length)
{
    for(int i=0;i<list_length;i++)
    {
        printf("%i ",arr[i]);
    }
}

void Selection_Sort (int *list,int list_length)
{
    int minimum_index=0;
    for(int i=0;i<list_length-1;i++)
    {
        minimum_index=i;
        for(int j=i+1;j<list_length;j++)
        {
            if(list[j]<list[minimum_index])
            {
                minimum_index=j;
            }
            else{}
        }
        Swap_Two_Num(&list[minimum_index],&list[i]);
    }
}
