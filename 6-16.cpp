#include <iostream>

int pow(const int what, int pow)
{
  int res;
  for (res = 1; pow>0; --pow)
    res *= what;
  return res;
}

int atoi(const char* s)
{
  int coef = 10;
  int start_pos = 0;

  int len=strlen(s);
  if (s[0] == '0' && s[1] == 'x')
  {
    coef = 16;
    start_pos = 2;
  }
  else if (s[0] == '0')
  {
    coef = 8;
    start_pos = 1;
  }

  int res = 0;

  for (int i=0; i<len-start_pos; i++)
  {
    int si = int(s[start_pos+i]);
    if (si >= int('0') && si <= int('9'))
      si = si-int('0');
    else if (si >= int('A') && si <= int('F'))
      si = 10+si-int('A');
    std::cout << pow(coef,len-i-1-start_pos) << ' ' << si << '!';
    res += pow(coef,len-i-1-start_pos) * si;
  }
  return res;
}

int main()
{
  std::cout << pow(10,4) << ' ' << pow(10,3) << ' ' << pow(10,2) << '\n';
  std::cout << '=' << atoi("0xA1") << '\n';
  std::cout << '=' << atoi("0xFF") << '\n';
  std::cout << '=' << atoi("0x1D") << '\n';
  std::cout << '=' << atoi("123") << '\n';
  std::cout << '=' << atoi("90") << '\n';
  std::cout << '=' << atoi("010") << '\n';
  std::cout << '=' << atoi("020") << '\n';
  std::cout << '=' << atoi("0100") << '\n';

}
