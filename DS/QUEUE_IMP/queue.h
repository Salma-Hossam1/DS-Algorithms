#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


#include "Platform_Typs.h"

typedef enum return_status
{
    R_NOK,  //FAILED IN EXECUTING THE FUNCTION          ---> default val =0
    R_OK    //THE FUNCTION HAS BEEN RUN SUCCESSFULLY    ---> default val =1
}return_status_t;
typedef enum
{
    full_queue,
    not_full_queue,
    empty_queue,
    NULL_pointer,
    OK
}queue_status;

typedef struct
{
    void** queue_arr;
    sint32 elements_num;
    sint32 queue_rear;
    sint32 queue_front;
    sint32 max_size;
}queue_t;


/**
  *@brief THIS FUNCTION TO CREATE THE QUEUE WITH D.A
  *@param (*my_queue) is a pointer to the queue
  *@param (maxx) IS THE NUM OF ELEMENTS WHICH USER WANTS TO RESERVE
  *@retval RETURN STATUS
*/
queue_t* queue_create (uint32 maxx,return_status_t *ret);
return_status_t Enqueue_func (queue_t *my_queue,void *data);
void* Dequeue_Func (queue_t *my_queue,return_status_t *ret);
void* Queue_Front (queue_t *my_queue,return_status_t *ret);
void* Queue_Rear (queue_t *my_queue,return_status_t *ret);
sint32 Elements_count (queue_t *my_queue,return_status_t *ret);
return_status_t Destroy_Queue (queue_t *my_queue);

typedef enum type_to_display
{
    integer,
    character,
    float_point,
    String
}type_to_display;

return_status_t display(queue_t *my_queue,type_to_display choice);
#endif // QUEUE_H_INCLUDED
