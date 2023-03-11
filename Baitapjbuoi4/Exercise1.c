#include <stdio.h>
#include <stdint.h>
#include <string.h>
int array[100];
void decimalToBinary(int decimalNumber)
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
void convertStringToDec(char *text)
{
  for (int i = 0; i < strlen(text); i++)
  {
    {
      array[i] = (text[i]);
      printf("\n%c: ", text[i]);
      decimalToBinary(array[i]);
    }
  }
}
int main(void)
{
  char text[] = "Hello World";
  convertStringToDec(text);
  return 0;
}
