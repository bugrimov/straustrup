
#include <iostream>
#include "name.hpp"

int main()
{
  //char* d = new char("sdfereerv34");

  //std::cout << *d << std::endl;
  
  Name* a = new Name("12345");
  Name* b = new Name("12347");
  Name* c = new Name("cdfklsdfl");
  *c = *b;
  a->print();
  b->print();
  c->print();
  std::cout << (*a == *b) << std::endl;
  std::cout << (*b==*c) << std::endl;
  std::cout << (*a==*c) << std::endl;
 
}