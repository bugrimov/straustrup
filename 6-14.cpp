#include <iostream>

void rev(char* s)
{
  int len = strlen(s)/2;
  char temp;
  for (int i=0; i<=len; i++)
  {
    temp = s[i];
    s[i] = s[len-i];
    s[len-i] = temp;
    std::cout << s[i] << ' ' << s[len-i] << '\n';
  }
}

int main()
{
  char d[] = "asdfg";
  std::cout << d << '\n';
  rev(d);
  std::cout << d << '\n';
}

