#include <stdio.h>
#include <stdint.h>
#include <string.h>
typedef union
{
  struct
  {
    char uid[4];
    char infor[9];
  } data;
  char clone[12];
} myData;
char *transmit(char *uid1, char *infor1)
{
  myData myData;
  static char result[12];
  strcpy(myData.data.uid, uid1);
  strcpy(myData.data.infor, infor1);
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