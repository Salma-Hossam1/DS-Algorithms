#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static stack_status IS_STACK_FULL (stack_t* stack_obj)
{
    if(stack_obj->stack_top <((stack_obj->stack_max_size)-1))
    {
        return Stack_Not_Full;
    }
    else
    {
        return Stack_Full;
    }
}
static stack_status IS_STACK_EMPTY (stack_t* stack_obj)
{
    if((stack_obj->stack_top) == -1)
    {
        return Stack_Empty;
    }
    else
    {
        return Stack_Not_Full;
    }
}

/**
  *@brief THIS FUNCTION TO BUILD STRUCT FOR THE STACK AND ALLOCATE THE ARRAY
  *@param Max_array_size IS THE SIZE OF ARRAY
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@retval RETURN STATUS
*/
stack_t* create_stack (sint32 Max_array_size,return_status_t *ret)
{
    stack_t *stack_obj;
    *ret = R_NOK;
    if(NULL == stack_obj)
    {
        #ifdef STACK_DEBUG
        printf("NULL POINTER\n");
        #endif // STACK_DEBUG
        *ret = R_NOK;
    }
    else
    {
        stack_obj =(stack_t *)malloc(sizeof(stack_t));
        if(!stack_obj)       //->checking if the space is reserved or not
        {
            *ret = R_NOK;
            stack_obj=NULL;   //->we didn't use (free) as the the function actually failed in reserving space so the address in stack_obj is invalid
            #ifdef STACK_DEBUG
            printf("error in allocating the stack package\n");
            #endif // STACK_DEBUG
        }
        else
        {
            #ifdef STACK_DEBUG
            printf("Stack is allocated\n");
            #endif // STACK_DEBUG
            stack_obj->stack_top = -1;
            stack_obj->stack_max_size=Max_array_size;
            stack_obj->element_counter=0;
            stack_obj->StackArray=(void **)calloc(stack_obj->stack_max_size,sizeof(void *));
            if(!stack_obj->StackArray)
            {
                *ret=R_NOK;
                free(stack_obj);
                stack_obj=NULL;
                #ifdef STACK_DEBUG
                printf("Error in allocating stack_array\n");
                #endif // STACK_DEBUG
            }
            else
            {
                #ifdef STACK_DEBUG
                printf("Allocating stack_array is done successfully\n");
                #endif // STACK_DEBUG
                *ret = R_OK;
            }
        }
    }
   return stack_obj;
}



/**
  *@brief THIS FUNCTION TO DESTROY THE STACK -> free
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@retval RETURN STATUS
*/
return_status_t destroy_stack (stack_t *stack_obj)
{
    return_status_t ret = R_NOK;
    if(NULL == stack_obj)
    {
        #ifdef STACK_DEBUG
        printf("NULL POINTER\n");
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        free(stack_obj->StackArray);
        free(stack_obj);
        stack_obj=NULL;
        #ifdef STACK_DEBUG
        printf("Stack is destroyed\n");
        #endif // STACK_DEBUG
        ret = R_OK;
    }
    return ret;
}


/**
  *@brief THIS FUNCTION TO PUSH DATA TO THE STACK
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@param ptr_data IS A VOID POINTER WHICH POINTS TO THE DATA TO BE STORED OF ANY DATA TYPE
  *@retval RETURN STATUS
*/
return_status_t push_data (stack_t *stack_obj, void *ptr_data)
{
    stack_status stat ;
    return_status_t ret = R_NOK;
    if(NULL == stack_obj || NULL == ptr_data)
    {
        #ifdef STACK_DEBUG
        printf("NULL POINTER\n");
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        stat = IS_STACK_FULL(stack_obj);
        if(stat == Stack_Full)
        {
            #ifdef STACK_DEBUG
            printf("Stack is full\n");
            #endif // STACK_DEBUG
            ret = R_NOK;
        }
        else
        {
            stack_obj->stack_top++;
            stack_obj->StackArray[stack_obj->stack_top]= ptr_data;  //prob
            (stack_obj->element_counter)++;
            #ifdef STACK_DEBUG
            printf("Data is pushed successfully\n");
            #endif // STACK_DEBUG
            ret = R_OK;
        }
    }
    return ret;
}


/**
  *@brief THIS FUNCTION TO POP DATA FROM THE STACK
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@param ptr_data IS A VOID POINTER WHICH POINTS TO THE DATA TO BE POPPED OF ANY DATA TYPE
  *@retval RETURN STATUS
*/
void * pop_data (stack_t *stack_obj, return_status_t *ret)
{
    void *ptr_data;
    stack_status stat ;
    *ret = R_NOK;
    if(NULL == stack_obj || NULL == ptr_data)
    {
        #ifdef STACK_DEBUG
        printf("NULL POINTER\n");
        #endif // STACK_DEBUG
        *ret = R_NOK;
        ptr_data = NULL;
    }
    else
    {
        stat = IS_STACK_EMPTY(stack_obj);
        if(stat == Stack_Empty)
        {
            #ifdef STACK_DEBUG
            printf("Stack is empty\n");
            #endif // STACK_DEBUG
            *ret = R_NOK;
            ptr_data = NULL;
        }
        else
        {
            ptr_data= (stack_obj->StackArray[stack_obj->stack_top]);
            (stack_obj->element_counter)--;
            (stack_obj->stack_top)--;
            #ifdef STACK_DEBUG
            printf("Data is popped successfully\n");
            #endif // STACK_DEBUG
            *ret = R_OK;
        }
    }
    return ptr_data;
}




/**
  *@brief THIS FUNCTION TO GET DATA ON THE TOP
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@param ptr_data IS A VOID POINTER WHICH POINTS TO THE DATA ON THE TOP
  *@retval RETURN STATUS
*/
void* stack_top (stack_t *stack_obj, return_status_t *ret)
{
    void *ptr_data;
    stack_status stat ;
    *ret = R_NOK;
    if(NULL == stack_obj || NULL == ptr_data)
    {
        #ifdef STACK_DEBUG
        printf("NULL POINTER\n");
        #endif // STACK_DEBUG
        *ret = R_NOK;
        ptr_data = NULL;
    }
    else
    {
        stat = IS_STACK_EMPTY(stack_obj);
        if(stat == Stack_Empty)
        {
            #ifdef STACK_DEBUG
            printf("Stack is empty\n");
            #endif // STACK_DEBUG
            *ret = R_NOK;
            ptr_data = NULL;
        }
        else
        {
            ptr_data= (stack_obj->StackArray[stack_obj->stack_top]);
            *ret = R_OK;
        }
    }
    return ptr_data;
}



/**
  *@brief THIS FUNCTION TO GET THE NUMBER OF ELEMENTS IN THE STACK
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@param counter IS A POINTER TO RETURN THE NUM OF ELEMENTS
  *@retval RETURN STATUS
*/
sint32 stack_count (stack_t *stack_obj,return_status_t *ret)
{
    sint32 counter =0;
    *ret = R_NOK;
    if(NULL == stack_obj )
    {
        #ifdef STACK_DEBUG
        printf("NULL POINTER\n");
        #endif // STACK_DEBUG
        *ret = R_NOK;
    }
    else
    {
        counter = stack_obj->element_counter;
        printf("Number of elements is %i",counter);
        *ret = R_OK;
    }
    return counter;
}

return_status_t display(stack_t *stack_obj,type_to_display choice)
{
    stack_status stat ;
    return_status_t ret = R_NOK;
    if(NULL == stack_obj)
    {
        #ifdef STACK_DEBUG
        printf("NULL POINTER\n");
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        stat = IS_STACK_EMPTY(stack_obj);
        if(stat == Stack_Empty)
        {
            #ifdef STACK_DEBUG
            printf("Stack is empty!!\n");
            #endif // STACK_DEBUG
            ret = R_NOK;
        }
        else
        {
            if(choice == integer)
            {
                for(int i= stack_obj->stack_top;i>=0;i--)
                {
                    printf("%d ",*((int *)(stack_obj->StackArray[i])));
                }
            }
            else if(choice == float_point)
            {
                for(int i= stack_obj->stack_top;i>=0;i--)
                {
                    printf("%f ",*((float *)(stack_obj->StackArray[i])));
                }
            }
            else if(choice == character)
            {
                for(int i= stack_obj->stack_top;i>=0;i--)
                {
                    printf("%c ",*((char *)(stack_obj->StackArray[i])));
                }
            }
            else if(choice == String)
            {
                for(int i= stack_obj->stack_top;i>=0;i--)
                {
                    printf("%s ",(char *)(stack_obj->StackArray[i]));
                }
            }
            else{}
        }
    }
    return ret;
}

