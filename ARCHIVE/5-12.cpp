#include <iostream>

int count_pair(std::string str, std::string pair)
{
  int count = 0;
  for (int i=0; i<str.size()-1; i++)
    if (str[i] == pair[0] && str[i+1] == pair[1])
      count++;
  return count;
}

int count_pair2(const char* str, const char* pair)
{
  int count = 0;
  for (; *str!='\0'; str++)
    if (*str == pair[0] && str[1] == pair[1])
      count++;
  return count;
}

int main()
{
  std::string str = "mama mila amama, i pella lala";
  std::cout << count_pair(str, "la") << std::endl;
  std::cout << count_pair(str, "ma") << std::endl;
  std::cout << count_pair(str, "ll") << std::endl;
  std::cout << count_pair(str, "a ") << std::endl;
  std::cout << count_pair2(str.c_str(), "la") << std::endl;
  std::cout << count_pair2(str.c_str(), "ma") << std::endl;
  std::cout << count_pair2(str.c_str(), "ll") << std::endl;
  std::cout << count_pair2(str.c_str(), "a ") << std::endl;
}
