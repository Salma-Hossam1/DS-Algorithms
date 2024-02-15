#ifndef SINGLE_LINKEDLIST_H_INCLUDED
#define SINGLE_LINKEDLIST_H_INCLUDED

#include "Platform_Types.h"

struct Node
{
    uint32 Node_Data;
    struct Node *Node_Linker;
};
//struct Node *ListHead = NULL;

return_status_t Insert_Node_At_Beginning(struct Node **List,uint32 data);
return_status_t Insert_Node_At_End(struct Node **List,uint32 data);
return_status_t Insert_Node_After_Specific_Node(struct Node *List,uint32 data,uint16 NodePosition);
return_status_t Delete_Node_At_Beginning(struct Node **List);
return_status_t Delete_Node(struct Node **List , uint16 NodePosition);
return_status_t Display_ALL_Nodes(struct Node *List);
uint32 Get_List_Length(struct Node *List);



#endif // SINGLE_LINKEDLIST_H_INCLUDED
