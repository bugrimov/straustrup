#include <iostream>
#include <limits>

struct Override
{
};

double plus(double a, double b)
{
  std::cout << a << " " << b << '\n';
  double c = a+b;
  if (c == a || c == b || c == std::numeric_limits<double>::infinity())
    throw Override();
  else
    return (a+b);
}


int main()
{ 
// i < std::numeric_limits<double>::max()
    for (double i = std::numeric_limits<double>::max(); ; i/=2)

  try
  {
    //for (double i = 2; ; i*=10)
      std::cout << plus(10,i-100) << '\n';
  }
  catch (Override)
  {
    std::cout << "overriding!\n";
  }
}