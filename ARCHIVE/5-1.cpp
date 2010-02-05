#include <iostream>

int main()
{
  char* s = "y";
  int arr[10]= {1,2,3,4,5,6};
  // ссылка на массив из 10 целых
  int *r_arr = arr;
  // указатель на массив символьных строк
  char* arr2[3] = {"sdfsdf", "Sdfsdfsdfs"};
  // указатель на указатель на символ
  char ** p_s = &s;
  std::cout << **p_s << std::endl;
  // указатель на целую константу
  int b = 5;
  const int * a = &b;
  std::cout << *a << std::endl;
  // константный укзатель на целое
  int * const p_a = &b;
  //p_a = &b;
  //*p_a = 5;

}

