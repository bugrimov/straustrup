#include <iostream>
#include <fstream>

int main()
{
  std::ifstream myfile;
  myfile.open("test.txt", std::ios::in);

  for (int n=0; n<1000; n++)
  {
    char filename[50];
    std::sprintf(filename, "9-07\\%d.txt\0", n);
    std::cout <<  filename << '\n';
    //myfile.open(filename, std::ios::in);
    char c;

    while (! myfile.eof())
    {
      myfile >> c;
    }
  }
    myfile.close();
  return 0;
}

