#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Platform_Typs.h"
#include "queue.h"
static bool fake_full (queue_t *my_queue)
{
    if((my_queue->queue_rear)==((my_queue->max_size)-1) && (my_queue->elements_num)<(my_queue->max_size) && ((my_queue->elements_num)>=1))  // num of element<max  (my_queue->queue_front)>0
    {
        return true;
    }
    else{return false;}
}
static bool fake_empty (queue_t *my_queue)
{
    if(( (my_queue->queue_front)==((my_queue->max_size)-1))  && (my_queue->elements_num)<(my_queue->max_size) && ((my_queue->elements_num)>1))  // num of element<max  (my_queue->queue_front)>0
    {
        return true;
    }
    else{return false;}
}
static queue_status IS_QUEUE_FULL (queue_t *my_queue)
{
        if((my_queue->elements_num)==(my_queue->max_size))
        {
            return full_queue;
        }
        else
        {
            return not_full_queue;
        }
}

static queue_status IS_QUEUE_EMPTY (queue_t *my_queue)
{
    if((my_queue->elements_num)==0)
    {
        return empty_queue;
    }
    else
    {
        return not_full_queue;
    }
}


/**
  *@brief THIS FUNCTION TO CREATE THE QUEUE WITH D.A
  *@param (*my_queue) is a pointer to the queue
  *@param (maxx) IS THE NUM OF ELEMENTS WHICH USER WANTS TO RESERVE
  *@retval RETURN STATUS
*/
queue_t* queue_create (uint32 maxx,return_status_t *ret)
{
    queue_t *my_queue;
    *ret = R_NOK;
        my_queue = (queue_t *)malloc(sizeof(queue_t));
        if(!my_queue)
        {
        #ifdef QUEUE_DEBUG
        printf("queue is not allocated\n");
        #endif // STACK_DEBUG
        *ret =R_NOK;
        my_queue =NULL;
        }
        else
        {
            #ifdef QUEUE_DEBUG
            printf("queue package is allocated\n ");
            #endif // QUEUE_DEBUG
            (my_queue->elements_num)=0;
            (my_queue->queue_rear)=-1;
            (my_queue->queue_front)=-1;
            (my_queue->max_size)=maxx;
            (my_queue->queue_arr)=(void **)calloc(maxx,sizeof(void *));
            if(!(my_queue->queue_arr))
            {
                #ifdef QUEUE_DEBUG
                printf("queue array is not allocated \n");
                #endif // QUEUE_DEBUG
                *ret=R_NOK;
                free(my_queue);
                my_queue=NULL;
            }
            else
            {
                #ifdef QUEUE_DEBUG
                printf("queue array is allocated\n");
                #endif // QUEUE_DEBUG
                *ret= R_OK;
            }
        }
    return my_queue;
}


/**
  *@brief THIS FUNCTION TO CREATE THE QUEUE WITH D.A
  *@param (*my_queue) is a pointer to the queue
  *@param (maxx) IS THE NUM OF ELEMENTS WHICH USER WANTS TO RESERVE
  *@retval RETURN STATUS
*/
return_status_t Enqueue_func (queue_t *my_queue,void *data)
{
    return_status_t ret = R_NOK;
    //queue_status stat;
    if(NULL == my_queue || NULL == data)
    {
        #ifdef QUEUE_DEBUG
        printf("NULL pointer in enqueue");
        #endif // STACK_DEBUG
        ret =R_NOK;
    }
    else
    {
        if(IS_QUEUE_FULL(my_queue)==full_queue)
        {
            #ifdef QUEUE_DEBUG
            printf("stack is full , item can not be added\n");
            #endif // QUEUE_DEBUG
            ret =R_NOK;
        }
        else if(IS_QUEUE_EMPTY(my_queue)==empty_queue)
        {
            (my_queue->queue_rear)=0;
            (my_queue->queue_front)=0;
            my_queue->queue_arr[my_queue->queue_rear]= data;
            my_queue->elements_num=1;
            #ifdef QUEUE_DEBUG
            printf("element pushed in case empty\n");
            #endif // QUEUE_DEBUG
            ret =R_OK;
        }
        else if (fake_full(my_queue))
        {
            (my_queue->queue_rear)=0;
            my_queue->queue_arr[my_queue->queue_rear]= data;
            (my_queue->elements_num)++;
            #ifdef QUEUE_DEBUG
            printf("element pushed in case fake full\n");
            #endif // QUEUE_DEBUG
            ret =R_OK;
        }
        else
        {
            (my_queue->queue_rear)++;
            my_queue->queue_arr[my_queue->queue_rear]= data;
            (my_queue->elements_num)++;
            #ifdef QUEUE_DEBUG
            printf("element pushed in case normal\n");
            #endif // QUEUE_DEBUG
            ret =R_OK;
        }


    }
    return ret;
}

void* Dequeue_Func (queue_t *my_queue,return_status_t *ret)
{
    void *ptr_data =NULL;
    queue_status stat=OK;
    if(my_queue == NULL || ret == NULL)
    {
        stat=NULL_pointer;
    }
    else
    {
        if(IS_QUEUE_EMPTY(my_queue)==empty_queue)
        {
            *ret=R_NOK;
            ptr_data =NULL;
        }
        //last element in queue
        else if((my_queue->elements_num)==1)
        {
            ptr_data = my_queue->queue_arr[my_queue->queue_front];
            (my_queue->queue_front)=-1;
            (my_queue->queue_rear)=-1;
            (my_queue->elements_num)--;
            *ret =R_OK;
        }
        else if (fake_empty(my_queue))
        {
            ptr_data = my_queue->queue_arr[my_queue->queue_front];
            (my_queue->queue_front)=0;
            (my_queue->elements_num)--;
            *ret =R_OK;
        }
        else{
            ptr_data = my_queue->queue_arr[my_queue->queue_front];
            (my_queue->queue_front)++;
            (my_queue->elements_num)--;
            *ret =R_OK;
        }
    }
    return ptr_data;
}

void* Queue_Front (queue_t *my_queue,return_status_t *ret)
{
    void *ptr_data =NULL;
    queue_status stat=OK;
    if(my_queue == NULL || ret == NULL)
    {
        stat=NULL_pointer;
    }
    else
    {
        if(IS_QUEUE_EMPTY(my_queue)==empty_queue)
        {
            *ret=R_NOK;
            ptr_data =NULL;
        }
        else
        {
            ptr_data = my_queue->queue_arr[my_queue->queue_front];
            *ret=R_OK;
        }
    }
    return ptr_data;
}

void* Queue_Rear (queue_t *my_queue,return_status_t *ret)
{
    void *ptr_data =NULL;
    queue_status stat=OK;
    if(my_queue == NULL || ret == NULL)
    {
        stat=NULL_pointer;
    }
    else
    {
        if(IS_QUEUE_EMPTY(my_queue)==empty_queue)
        {
            *ret=R_NOK;
            ptr_data =NULL;
        }
        else
        {
            ptr_data = my_queue->queue_arr[my_queue->queue_rear];
            *ret=R_OK;
        }
    }
    return ptr_data;
}

sint32 Elements_count (queue_t *my_queue,return_status_t *ret)
{
    sint32 counter=0;
    queue_status stat=OK;

    if(my_queue == NULL || ret == NULL)
    {
        stat=NULL_pointer;
    }
    else
    {
    if(IS_QUEUE_EMPTY(my_queue)==empty_queue)
        {
            *ret=R_NOK;
            counter=0;
        }
        else
        {
            counter = (my_queue->elements_num);
            *ret=R_OK;
        }
    }
    return counter;
}

return_status_t Destroy_Queue (queue_t *my_queue)
{
    return_status_t ret =R_NOK;
    if(my_queue == NULL)
    {
        ret=R_NOK;
    }
    else
    {
        free(my_queue->queue_arr);
        free(my_queue);
        ret=R_OK;
    }
    return ret;
}

return_status_t display(queue_t *my_queue,type_to_display choice)
{
    queue_status stat =OK;
    return_status_t ret = R_NOK;
    int position , size;
    if(NULL == my_queue)
    {
        ret = R_NOK;
    }
    else
    {
        stat = IS_QUEUE_EMPTY (my_queue);
        if(stat == empty_queue)
        {
            ret = R_NOK;
        }
        else
        {
            if(choice == integer)
            {
                for(position= my_queue->queue_front,size=0;size<(my_queue->elements_num);size++)
                {
                    printf("%d ",*((int *)(my_queue->queue_arr[position])));
                    position=(position+1)%(my_queue->max_size);
                }
            }
            else if(choice == float_point)
            {
                for(position= my_queue->queue_front,size=0;size<(my_queue->elements_num);size++)
                {
                    printf("%f ",*((float *)(my_queue->queue_arr[position])));
                    position=(position+1)%(my_queue->max_size);
                }
            }
            else if(choice == character)
            {
                for(position= my_queue->queue_front,size=0;size<(my_queue->elements_num);size++)
                {
                    printf("%c ",*((char *)(my_queue->queue_arr[position])));
                    position=(position+1)%(my_queue->max_size);
                }
            }
            else if(choice == String)
            {
                for(position= my_queue->queue_front,size=0;size<(my_queue->elements_num);size++)
                {
                    printf("%s ",(char *)(my_queue->queue_arr[position]));
                    position=(position+1)%(my_queue->max_size);
                }
            }
            else{}
        }
    }
    return ret;
}

