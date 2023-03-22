#include <stdio.h>

void hieu(int a, int b)
{
  printf("Tong : %d\n", a - b);
}

void tong(int a, int b)
{
  printf("Tong : %d\n", a + b);
}

int main(int argc, char const *argv[])
{
  int array_Int[] = {1, 3, 5, 4};
  char array_Char[] = "Hello World";
  double array_double[] = {2.3, 1.5, 4.6, 6.4};
  void (*array_Function[])(int, int) = {&tong, &hieu};

  void *arr[4] = {array_Int, array_Char, array_double, array_Function};

  ((void (*)(int, int))(((void **)arr[3])[0]))(2, 7); // truyền từ array[array_Function] vào hàm tổng
}