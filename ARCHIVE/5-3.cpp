#include <iostream>

int main()
{
  typedef unsigned char uc;
  typedef const unsigned char cuc;
  typedef int* pint;
  typedef char ** Ppc;
  // ��������� �� ������ char
  typedef char Pac[];
  Pac y = "toge";  
  std::cout << *y;
  // ������ �� 7 ���������� �� ����� �����
  typedef int* Pa7i[7];
  Pa7i t;
  int r= 67;
  t[2] = &r;
  std::cout << *t[2];
  //��������� �� ������ �� 7 ���������� �� ����� �����
  typedef int* A78[8][7];
  // ������ �� 8 �������� �� 7 ���������� �� �����
}


