#include <iostream>

void show_months(char* arr[], short size)
{
  for (int i=0;i < size; i++)
    std::cout << arr[i] << std::endl;
}

int main()
{
  const short MONTHS = 3;
  char* months[] = {"Jan", "Feb", "Mar"};
  show_months(months, MONTHS);
}

