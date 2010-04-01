#include <iostream>
#include <fstream>
#include <vector>

int main()
{

  std::vector<std::ifstream*> v;

  for (int n=0; n<1000; n++)
  {
    char filename[50];
    std::sprintf(filename, "9-07\\%d.txt\0", n);
    std::cout <<  filename << '\n';
    std::ifstream* myfile = new std::ifstream;
    (*myfile).open(filename, std::ios::in);
    if ( (*myfile).is_open() )
      v.push_back(myfile);
    else
    {
      std::cout << "closed!\n";
      break;
    }
    //myfile.close();
  }

  for (int n=0; n<1000; n++)
  {
    std::cout << n << ' ' << v[n] << '\n';
    //std::ifstream* myfile = v[n];
    char c;
    while (! (*v[n]).eof())
    {
      (*v[n]) >> c;
      //std::cout << c;
    }

  }
    

  return 0;
}

