#include <stdio.h>
#include <stdarg.h>
double total(int sum, ...)
{
  double flag = 0.0;
  va_list ptr;
  va_start(ptr, sum);
  for (int i = 0; i < sum; i++)
  {
    if (*ptr != 0)
      flag = flag + va_arg(ptr, int);
    else
    {
      flag = flag + va_arg(ptr, double);
    }
  }
  va_end(ptr);
  return flag;
}
int main(void)
{
  printf("%.3f", total(4, 2.5, 3, 4, 5.0));
  return 0;
}
