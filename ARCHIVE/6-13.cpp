#include <iostream>

char* cat(const char* s1, const char* s2)
{
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  char* res = new char[len1+len2+1];
  std::cout << "cat: " << len1+len2 << ' ' << res << '\n';
  int i;
  for(i=0; i<len1+len2; i++)
    if (i < len1)
    {
      res[i] = s1[i];
      std::cout << res[i];
    }
    else
    {
      res[i] = s2[i-len1];
    }
  res[i] = '\0';
  return res;
}

int main()
{
  char* s = cat("abc","def");
  std::cout << "RES:" << s << ' ' << strlen(s);
}
  
