#include <iostream>

int main()
{
  char* s = "y";
  int arr[10]= {1,2,3,4,5,6};
  // ������ �� ������ �� 10 �����
  int *r_arr = arr;
  // ��������� �� ������ ���������� �����
  char* arr2[3] = {"sdfsdf", "Sdfsdfsdfs"};
  // ��������� �� ��������� �� ������
  char ** p_s = &s;
  std::cout << **p_s << std::endl;
  // ��������� �� ����� ���������
  int b = 5;
  const int * a = &b;
  std::cout << *a << std::endl;
  // ����������� �������� �� �����
  int * const p_a = &b;
  //p_a = &b;
  //*p_a = 5;

}

