#include <iostream>

using std::cout;


struct Divide_zero
{
  //Divide_zero(){}
};


int mydiv(int n, int m)
{
  if (m == 0)
    throw Divide_zero();
  return n/m;
}


void print_div(int n, int m)
{
  int res = 0;
  try
  {
    cout << mydiv(n,m) << '\n';
  }
  catch(Divide_zero)
  {
    cout << "can't divide to zero\n";
  }
}


int main()
{
  print_div(10,4);
  print_div(1,0);
  print_div(100,4);
}

