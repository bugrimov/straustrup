#include <iostream>
#include <time.h>

using std::cout;
using std::clock;

struct myErr
{
};

void f2(int n = 10)
{
  for (int  i=n; i<10000000; i++)
    if ((i%1000) == 9999990)
      cout << '.';
}


int f(bool err)
{
    f2();

  if(err)
    throw myErr();
  else
    return 10;
}


int main()
{
  cout << clock() << '\n';
  try
  {
    f(0);
  }
  catch(myErr)
  {
  }
  cout << clock() << '\n';
  try
  {
    f(1);
  }
  catch(myErr)
  {
  }
  cout << clock() << '\n';

 
}