#include <iostream>

int main()
{
  typedef unsigned char uc;
  typedef const unsigned char cuc;
  typedef int* pint;
  typedef char ** Ppc;
  // указатель на массив char
  typedef char Pac[];
  Pac y = "toge";  
  std::cout << *y;
  // массив из 7 указателей на целые числа
  typedef int* Pa7i[7];
  Pa7i t;
  int r= 67;
  t[2] = &r;
  std::cout << *t[2];
  //указатель на массив из 7 указателей на целые числа
  typedef int* A78[8][7];
  // массив из 8 массивов по 7 указателей на целые
}


