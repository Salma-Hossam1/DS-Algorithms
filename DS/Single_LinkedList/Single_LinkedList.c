#include <stdio.h>
#include <stdlib.h>
#include "Single_LinkedList.h"
#include "Platform_Types.h"


return_status_t Insert_Node_At_Beginning(struct Node **List,uint32 data)
{
    return_status_t Error_State = R_NOK;
    struct Node *TempNode = NULL;
    /*Create the needed function , Take care of explicit casting as malloc will return void or Null*/
    TempNode = (struct Node *)malloc(sizeof(struct Node));

    /*Check if malloc succceeded in reserving space*/
    if (NULL != TempNode)
    {
        TempNode->Node_Data = data;

        /*Check if Linked list is empty or not*/
        if (NULL == *List) /*if true -> list is empty*/
        {
            TempNode->Node_Linker = NULL;
            *List = TempNode;
            Error_State = R_OK;
        }
        else /*list is not empty*/
        {
            TempNode->Node_Linker = *List;
            *List = TempNode;
            Error_State = R_OK;
        }
    }
    else
    {
        Error_State = R_NOK;
    }
    return Error_State;
}

return_status_t Insert_Node_At_End(struct Node **List,uint32 data)
{
    return_status_t Error_State = R_NOK;
    struct Node *TempNode = NULL;
    struct Node *LastNode = NULL;

    /*Create the needed node*/
    TempNode = (struct Node *)malloc(sizeof(struct Node));
    /*Check if malloc succceeded in reserving space*/
    if (NULL != TempNode) // succeeded
    {
        TempNode->Node_Data = data;
        /*As we add at end the node linker is always equah to null*/
        TempNode->Node_Linker = NULL;

        /*Check the list is empty or not*/
        if (NULL == *List) /*empty if true*/
        {
            *List = TempNode;
            Error_State = R_OK;
        }
        else /*Not empty*/
        {
            /*traversing over the list until we found the node whose linker points to null which is the last node*/
            LastNode = *List;
            while (LastNode->Node_Linker != NULL)
            {
                LastNode = LastNode->Node_Linker;
            }
            /*As we found the last node , here we make its linker points to add of new node instead of pointing to null*/
            LastNode->Node_Linker = TempNode;
            Error_State = R_OK;
        }
    }
    else
    {
        Error_State = R_NOK;
    }
    return Error_State;
}

return_status_t Insert_Node_After_Specific_Node(struct Node *List,uint32 data,uint16 NodePosition)
{
    return_status_t Error_State = R_NOK;
    struct Node *TempNode = NULL;
    struct Node *NodeListCounter = NULL;
    uint32 ListLength = 0;
    uint32 NodeCounter = 1;

   // printf("Enter Node position (First Node position is 1) : ");


    /*Get_Lenght func -> takes head_list pointer and it returns the number of nodes in that list*/
    ListLength = Get_List_Length(List);

    /*Check if user passed valid or invalid position*/
    if (NodePosition > ListLength)
    {
        printf("Invalid position -> List has (%i) Nodes \n", ListLength);
        Error_State = R_NOK;
    }
    else
    {
        /*Traversing over the list to get the address of position i want to add the new node after*/
        /*NodeListCounter is the pointer which has the address of the specific node*/
        NodeListCounter = List;
        while (NodeCounter < NodePosition)
        {
            NodeCounter++;
            NodeListCounter = NodeListCounter->Node_Linker;
        }
        /*Create new node*/
        TempNode = (struct Node *)malloc(sizeof(struct Node));

        /*Check if malloc succceeded in reserving space*/
        if (NULL != TempNode) // succeeded
        {
            TempNode->Node_Data = data;

            /*Connect the right side connection*/
            TempNode->Node_Linker = NodeListCounter->Node_Linker;
            /*Connect the left side connection*/
            NodeListCounter->Node_Linker = TempNode;
            Error_State = R_OK;
        }
        else
        {
            Error_State = R_NOK;
        }
    }
    return Error_State;
}

return_status_t Delete_Node_At_Beginning(struct Node **List)
{
    return_status_t Error_State = R_NOK;

    //make tempnode the first node
    struct Node *TempNode = *List;
    uint32 ListLength = 0;

    ListLength = Get_List_Length(*List);
    if (ListLength == 0)
    {
        printf("Empty Linked list\n");
        Error_State = R_NOK;
    }
    else
    {
        *List = TempNode->Node_Linker;
        TempNode->Node_Linker = NULL; /*TempNode is a free Node*/
        free(TempNode);
        Error_State = R_OK;
    }
    return Error_State;
}

return_status_t Delete_Node(struct Node **List , uint16 NodePosition)
{
    return_status_t Error_State = R_NOK;
    struct Node *NodeListCounter = *List;
    struct Node *NextNode = *List;
    uint32 ListLength = 0;
    uint32 NodeCounter = 1;

    ListLength = Get_List_Length(*List);
    //printf("Enter the position of Node you want to delete -> (First Node position is 1) : ");
    if (NodePosition > ListLength)
    {
        printf("Invalid position -> List has (%i) Nodes \n", ListLength);
        Error_State = R_NOK;
    }
    else if(ListLength == 1)
    {
        Error_State =Delete_Node_At_Beginning (List);
    }
    else if(ListLength == 0)
    {
        printf("Empty Linked list\n");
        Error_State = R_NOK;
    }
    else
    {
        while (NodeCounter < (NodePosition - 1))
        {
            /*NodeListCounter points to the node before the target node i want to delete*/
            NodeCounter++;
            NodeListCounter = NodeListCounter->Node_Linker;
        }
        /*NextNode points to the target node i want to delete */
        NextNode = NodeListCounter->Node_Linker;
        NodeListCounter->Node_Linker = NextNode->Node_Linker;
        free(NextNode);
        Error_State = R_OK;
    }
    return Error_State;
}

return_status_t Display_ALL_Nodes(struct Node *List)
{
    return_status_t Error_State = R_NOK;
    /*Traversing*/
    struct Node *TempNode = List;
    if (NULL == TempNode)
    {
        printf("List is empty\n");
        Error_State = R_NOK;
    }
    else
    {
        printf("Node Values : ");
        while (TempNode != NULL)
        {
            printf("%i ", TempNode->Node_Data);
            TempNode = TempNode->Node_Linker;
        }
        Error_State = R_OK;
    }
    return Error_State;
}

uint32 Get_List_Length(struct Node *List)
{
    struct Node *TempNode = List;
    uint32 NodeCount = 0;

    while (TempNode != NULL)
    {
        NodeCount++;
        TempNode = TempNode->Node_Linker;
    }
    return NodeCount;
}
