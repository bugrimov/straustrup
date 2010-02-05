/* Введите последовательность (возможно с символами разделителями)
   пар (имя,значение), где имя является словом, отделяемым символами-
   разделителями, а значение = целым или числом с плавающей точкой.
   Вычислите и выведите сумму и среднее как для каждого отдельного имени, 
   так и для всех имен. (6.1.8)
   стр 183
*/

#include <iostream>
#include <string>
#include <map>

enum {PAIR_DELIM='&', NAME_DELIM = '='};

void store(std::string name, std::string value)
{
  std::cout << "store: " << name << ' ' << value << '\n';
}

int main()
{
  char inp[256];
  std::cout << "Enter data: ";
  std::cin.getline(inp, 256);
  std::cout << inp;
  std::string name = "";
  std::string value = "";
  bool now_input_value = false;
  for (int i=0; i<strlen(inp); i++)
    switch (inp[i])
    {
    case PAIR_DELIM:
      store(name, value);
      name = "";
      value = "";
      now_input_value = false;
      break;
    case NAME_DELIM:
      now_input_value = true;
      break;
    default:
      if (now_input_value)
      {
        value += inp[i];
      }
      else
      {
        name  += inp[i];
      }
    }
  store(name, value);
}

