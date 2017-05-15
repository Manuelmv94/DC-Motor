/*! **********************************************************************************************
* 2016  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      StringUtils.c
* @author(s): Manuel Madrigal Valenzuela; Efra�n Duarte L�pez
*
* @brief (Theory of Operation)
*     The present file allows the user to treat arrays of chars as if they were strings. It contains
*     comparisons of strings done char by char and translations from Number to String and String
*     to number
*
**************************************************************************************************/


/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "StringUtils.h"

/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/
#define ASCII_OFFSET 0x30
#define LOWEST_DECIMAL_NUMBER 0
#define HIGHES_DECIMAL_NUMBER 9
#define INIT_VALUE   0
#define DECIMAL_SHIFT_LEFT 10
/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/


/*************************************************************************************************/
/*********************                  Static Variables                    **********************/
/*************************************************************************************************/

static u16 accumulatedValue;
static u8 index;//used to traverse the strings

/*************************************************************************************************/
/*********************					Global Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Constants                    **********************/
/*************************************************************************************************/


/*************************************************************************************************/
/*********************                  Global Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************				   Exported Functions					**********************/
/*************************************************************************************************/




void StringUtils_Num2Str(u16 num, u8 strSize, char string[])
{  
  accumulatedValue=num;
  for(index=strSize;index>INIT_VALUE;index--)
  {
    string[index-1]=accumulatedValue%DECIMAL_SHIFT_LEFT +ASCII_OFFSET;//Translate the rightmost number into its character representation
    accumulatedValue/=DECIMAL_SHIFT_LEFT;//Moves from the rightmost number to the consecutive one at the left
  }
}



//-------------------------------------------------------------------------------------------------


/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/

