#include <iostream>
#include <cstdarg>

using namespace std;

void error(const char* s ...)
{
  va_list ap;
  va_start(ap, s);

  for(;*s != '\0'; s++)
  {
    if (*s == '%')
    {
      switch (*(s+1))
      {
        case 's':
          char* p = va_arg(ap, char*);
          cerr << p;
          s++;
          break;
        case 'd':
          int number = va_arg(ap, int);
          cerr << number;
          s++;
          break;
        case 'c':
          char user_char = va_arg(ap, int);
          cerr << user_char;
          s++;
          break;
        default:
          cerr << '?';
      }
    }
    else
      cerr << *s;
  }
  cerr << '\n';
  va_end(ap);  
}

int main()
{
  char t = 't';
  char* null = 0;
  error("TEst: %s %s", "r", "dfM");
  error("Three datas: (%s) [%d] {%c}", "bebe",24, 'r');
}
