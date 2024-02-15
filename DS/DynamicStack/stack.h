#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Platform_Typs.h"

typedef struct{
    void **StackArray;
    sint32 element_counter;
    sint32 stack_max_size;
    sint32 stack_top;
}stack_t;


typedef enum{
    Stack_Empty,
    Stack_Full,
    Stack_Not_Full
}stack_status;


/**
  *@brief THIS FUNCTION TO BUILD STRUCT FOR THE STACK AND ALLOCATE THE ARRAY
  *@param Max_array_size IS THE SIZE OF ARRAY
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@retval RETURN STATUS
*/
stack_t* create_stack (sint32 Max_array_size,return_status_t *ret);


/**
  *@brief THIS FUNCTION TO DESTROY THE STACK -> free
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@retval RETURN STATUS
*/
return_status_t destroy_stack (stack_t *stack_obj);



/**
  *@brief THIS FUNCTION TO PUSH DATA TO THE STACK
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@param ptr_data IS A VOID POINTER WHICH POINTS TO THE DATA TO BE STORED OF ANY DATA TYPE
  *@retval RETURN STATUS
*/
return_status_t push_data (stack_t *stack_obj, void* ptr_data);



/**
  *@brief THIS FUNCTION TO POP DATA FROM THE STACK
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@param ptr_data IS A VOID POINTER WHICH POINTS TO THE DATA TO BE POPPED OF ANY DATA TYPE
  *@retval RETURN STATUS
*/
void * pop_data (stack_t *stack_obj, return_status_t *ret);



/**
  *@brief THIS FUNCTION TO GET DATA ON THE TOP
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@param ptr_data IS A VOID POINTER WHICH POINTS TO THE DATA ON THE TOP
  *@retval RETURN STATUS
*/
void* stack_top (stack_t *stack_obj, return_status_t *ret);



/**
  *@brief THIS FUNCTION TO GET THE NUMBER OF ELEMENTS IN THE STACK
  *@param Stack_obj IS POINTER TO THE OBJECT FROM STRUCT OF STACK
  *@param counter IS A POINTER TO RETURN THE NUM OF ELEMENTS
  *@retval RETURN STATUS
*/
sint32 stack_count (stack_t *stack_obj,return_status_t *ret);

typedef enum type_to_display
{
    integer,
    character,
    float_point,
    String
}type_to_display;

return_status_t display(stack_t *stack_obj,type_to_display choice);
#endif // STACK_H_INCLUDED
