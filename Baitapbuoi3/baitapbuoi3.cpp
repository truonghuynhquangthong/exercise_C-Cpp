#include <stdio.h>
#include <stdarg.h>

double tong(int n, ...)
{
  double sum = 0.0;
  va_list ptr;
  va_start(ptr, n);

  int i;
  for (i = 0; i < n; i++)
  {
    float temp = va_arg(ptr, double);
    if (temp != 0.0)
    {

      sum = sum + temp;
    }
    else
    {
      ptr = ptr - sizeof(ptr);
      // printf("check1: %d", ptr);
      // printf("check2: %d", va_arg(ptr, int));
      sum = sum + va_arg(ptr, int);
    }
  }
  return sum;
}
int main()
{
  printf("%f", tong(7, 8.8, 8, 2.6, 2, 3, 1.2, 6.6));
  return 0;
}