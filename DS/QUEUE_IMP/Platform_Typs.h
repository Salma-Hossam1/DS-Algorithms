//#ifndef PLATFORM_TYPS_H_INCLUDED
#define PLATFORM_TYPS_H_INCLUDED
/*-------------------------------------*/
#define ZERO_INIT 0
#define ZERO      0
/*-------------------------------------*/
#define QUEUE_DEBUG

/*-------------------------------------*/

//typedef enum return_status
//{
//    R_NOK,  //FAILED IN EXECUTING THE FUNCTION          ---> default val =0
//    R_OK    //THE FUNCTION HAS BEEN RUN SUCCESSFULLY    ---> default val =1
//}return_status_t;
/*-------------------------------------*/


/*-------------------------------------*/
#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

#define CPU_TYPE CPU_TYPE_64

#if ( CPU_TYPE == CPU_TYPE_64 )
typedef unsigned char boolean ;
typedef unsigned char uint8 ;
typedef unsigned short uint16 ;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8 ;
typedef signed short sint16 ;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif ( CPU_TYPE == CPU_TYPE_32 )
typedef unsigned char boolean ;
typedef unsigned char uint8 ;
typedef unsigned short uint16 ;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8 ;
typedef signed short sint16 ;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif ( CPU_TYPE == CPU_TYPE_16 )
typedef unsigned char boolean ;
typedef unsigned char uint8 ;
typedef unsigned short uint16 ;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8 ;
typedef signed short sint16 ;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif ( CPU_TYPE == CPU_TYPE_16 )
typedef unsigned char boolean ;
typedef unsigned char uint8 ;
typedef unsigned short uint16 ;
typedef unsigned long uint32;
typedef signed char sint8 ;
typedef signed short sint16 ;
typedef signed long sint32;
typedef float float32;
/*-------------------------------------*/

#endif // PLATFORM_TYPS_H_INCLUDED
