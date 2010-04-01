#include <iostream>

int main()
{
  char* j = "juga jaga maga puga luga baga";
  for (int i=0; j[i] != '\0'; i++)
    std::cout <<j[i];
  for (; *j != '\0'; j++)
        std::cout <<*j;
}
