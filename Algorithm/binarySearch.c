#include <stdio.h>
#include <stdlib.h>


int BinarySearchAlgorithm(int arr[], int Start_Index, int End_Index, int Req_Value){
    int Middle_Index = 0;

    while(Start_Index <=End_Index){
        Middle_Index = Start_Index + ((End_Index - Start_Index) / 2);

        if(Req_Value == arr[Middle_Index]){
            return Middle_Index;
        }
        else if(Req_Value > arr[Middle_Index]){
            Start_Index = Middle_Index + 1;
        }
        else{
            End_Index = Middle_Index - 1;
        }
    }

    return -1;
}
