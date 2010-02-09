
#include <iostream>
#include "table.hpp"

int main()
{
  Table a;
  Name n("qwe");
  a.add(n, 0.5);
  a.add(Name("xcv"), 673.3466);
  a["abc"] = 99.5566;
  std::cout << a["abc"] << std::endl;
}