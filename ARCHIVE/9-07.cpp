#include <iostream>
#include <fstream>

int main()
{
  std::ofstream myfile;
  myfile.open("test.txt", std::ios::out);
  for (int n=0; n<1000; n++)
  {
    char filename[50];
    std::sprintf(filename, "9-07\\%d.txt\0", n);
    std::cout <<  filename << '\n';
    //myfile.open(filename, std::ios::out);

    for (int i=0; i< 15000; i++)
    {
      myfile << 'a';
    }
  }
  myfile.close();
  return 0;
}

