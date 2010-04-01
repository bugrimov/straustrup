#include <iostream>
#include <string>

using namespace std;

char a[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void print(int num, int base=10)
{
  int i=num;
  string s = "";
  do
  {
    s.insert(0,1,a[i%base]);
    i = i/base;
  }
  while (i!=0);

  cout << s << '\n'; // << i/base << '\n';
}

int main()
{
  print(31);
  print(500,5);
  print(31, 10);
  print(31, 16);
  print(255, 16);
  print(4095, 16);
  print(31, 2);
}
