#include <iostream>

struct Limit_reached
{
  int num;
  Limit_reached(int n)
  {
    num = n;
    std::cout << "END OF LIMIT: " << n << "\n";
  }
};

int f1(int total, int curr=0)
{
  try
  {
  if (curr < total)
    f1(curr+1, total);
  else
    throw Limit_reached(curr);
  }
  catch(Limit_reached r)
  {
    std::cout << "reached limit " << r.num << '\n';
  }
}


int main()
{
  f1(10);
  f1(100000000);
}
 