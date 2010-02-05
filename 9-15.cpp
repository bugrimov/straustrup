#include <iostream>

struct Init
{
  Init()
  {
    std::cout << "Initalize" << std::endl;
  }

  ~Init()
  {
    std::cout << "Deleting" << std::endl;
  }

};

Init a;

int main()
{
  std::cout << "Hello World!" << std::endl;
 
}
