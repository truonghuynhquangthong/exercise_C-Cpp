/*
 * File: main.c
 * Author: Thong Truong
 * Date: 24/03/2023
 * Description: This file is designed to convert from string to binary
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
/*
 * Union: myData
 * Description: This union is designed to storage data
 */
/*
 * Struct: data
 * Description: This struct is designed to storage data with two fields are uid and infor
 */
typedef union
{
  struct
  {
    char uid[4];
    char infor[9];
  } data;
  /*Desciption: Var clone is used to cacth data of the uid and infor in a var*/
  char clone[12];
} myData;
/*
 * Function: transmit
 * Description: This function to transmit data
 * Input:
 *   uidClone - an char array value
 *   inforClone - an char array value
 * Output:
 *   return the char array of uid and infor 
 */
char *transmit(char *uidClone, char *inforClone)
{
  myData myData;
  static char result[12];
  /*Description: copy uidClone and paste into uid of struct*/
  strcpy(myData.data.uid, uidClone);
  /*Description: copy inforClone and paste into uid of struct*/
  strcpy(myData.data.infor, inforClone);
  /*Desciption: using for loop to catch data var clone of union and put into the result */
  for (int i = 0; i < 12; i++)
  {
    result[i] = myData.clone[i];
  }
  return result;
}
int main(void)
{
  myData myData;
  char *data = transmit((char *)"100", (char *)"10011265");
  for (int i = 0; i < 12; i++)
  {
    printf("%c", data[i]);
  }
  return 0;
}