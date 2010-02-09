
#include <iostream>


class Name
{
  char* s;
public:
  Name(const char* str)
  {
    int i;
    for (i=0; str[i] != '\0'; i++);
    s = new char[i+1];
    for (i=0; str[i] != '\0'; i++)
      s[i] = str[i];
    s[i] = '\0';
  }
  Name()
  {
    s = 0;
  }

  const char* value()
  {return s;}
  bool operator==(Name& b) const;
  Name& operator=(const Name& n)
  {
    if (this != &n)
    {
      delete s;
      int i;
      for (i=0; n.s[i] != '\0'; i++);
      s = new char[i+1];
      for (i=0; n.s[i] != '\0'; i++)
        s[i] = n.s[i];
      s[i] = '\0';

    }
    return *this;
  }

  void print()
  {
    std::cout << s << std::endl;
  }


};

bool Name::operator==(Name& b) const
{
  /*char* a1=s;
  char* b1=&b;
  while (*(a1++) == *(b1++) && *a1 != '\0' && *b1 != '\0');
  */
  int i;
  for (i=0; s[i] != '\0' && b.s[i] != '\0'; i++)
  {
    std::cout << b.s[i] << "==" << s[i] << " ";
    if (b.s[i] != s[i])
      return false;
  }
  return s[i] == b.s[i];
}

