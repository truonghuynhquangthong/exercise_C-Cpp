/*
 * File: main.c
 * Author: Thong Truong
 * Date: 24/03/2023
 * Description: This file is designed to convert from string to binary
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
int array[100];
/*
 * Function: convert_decimal_to_binary
 * Description: This function to convert decimal to binary
 * Input:
 *   decimalNumber - an integer value
 * Output:
 *   print the binary array of a decimal
 */
void convert_decimal_to_binary(int decimalNumber)
{
  int binaryNumber[32];
  int i = 0;
  while (decimalNumber > 0)
  {
    binaryNumber[i] = decimalNumber % 2;
    decimalNumber = decimalNumber / 2;
    i++;
  }
  for (int j = i - 1; j >= 0; j--)
  {
    printf("%d", binaryNumber[j]);
  }
}
/*
 * Function: convert_string_to_decimal
 * Description: This function to convert string to decimal following the ASCII table code
 * Input:
 *   decimalNumber - an integer value
 * Output:
 *   print the binary array of a decimal
 */
void convert_string_to_decimal(char *text)
{
  for (int i = 0; i < strlen(text); i++)
  {
    {
      array[i] = (text[i]);
      printf("\n%c: ", text[i]);
      convert_decimal_to_binary(array[i]);
    }
  }
}
int main(void)
{
  char text[] = "Hello World";
  convert_string_to_decimal(text);
  return 0;
}
