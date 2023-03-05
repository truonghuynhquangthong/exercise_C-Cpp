/*
echo "# C-C-exercise" >> README.md
git init
//git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/truonghuynhquangthong/C-C-exercise.git
git push -u origin main
*/
#include <iostream>
#include <stdarg.h>
using namespace std;
int tong(int sum, ...)
{
  int flag = 0;
  va_list ptr;
  va_start(ptr, sum);

  for (int i = 0; i < sum; i++)
  {
    flag = flag + va_arg(ptr, double);
  }
  va_end(ptr);
  return flag;
}
int main(void)
{
  cout << tong(4, 1, 2, 3, 3.2);
  return 0;
}