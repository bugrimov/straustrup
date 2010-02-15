/* ������ ��᫥����⥫쭮��� (�������� � ᨬ������ ࠧ����⥫ﬨ)
   ��� (���,���祭��), ��� ��� ���� ᫮���, �⤥�塞� ᨬ������-
   ࠧ����⥫ﬨ, � ���祭�� = 楫� ��� �᫮� � ������饩 �窮�.
   ���᫨� � �뢥��� �㬬� � �।��� ��� ��� ������� �⤥�쭮�� �����, 
   ⠪ � ��� ��� ����. (6.1.8)
   ��� 183
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

