/*
 * File: main.c
 * Author: Thong Truong
 * Date: 24/03/2023
 * Description: This is a sample file for input with many parameters
 */
#include <stdio.h>
#include <stdarg.h>
/*
 * Function: sum
 * Description: This function calculates the sum of multiple parameters
 * Input:
 *   n - an integer value for the amount paramters
 *   ... - Multiple integer or double values
 * Output:
 *   returns the sum of multiple values
 */
double sum(int n, ...)
{
  double sum = 0.0;

  /*Description: declares a var 'ptr' of type va_list used to work with var-length argument list */
  va_list ptr;

  /*Description: initializes the variable argument list by setting the `ptr` pointer to the first argument following the parameter `n` */
  va_start(ptr, n);
  int i;

  /*Description: loop with the n time coressponding the argument list */
  for (i = 0; i < n; i++)
  {
  /*Description: The va_arg macro is used to retrieve the next variable argument of type "double" from the argument list
  and its value is then assigned to the temp var*/
    double temp = va_arg(ptr, double);
    if (temp != 0.0)
    {
      sum = sum + temp;
    }
    else
    {
      ptr = ptr - sizeof(ptr);
      sum = sum + va_arg(ptr, int);
    }
  }
  return sum;
}
int main()
{
  printf("%f", sum(7, 8.8, 8, 2.6, 2, 3, 1.2, 6.6));
  return 0;
}