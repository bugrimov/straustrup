#include <iostream>
#include <list>

int main()
{
  std::list<std::string> inp;
  bool quit = false;
  while ( !quit )
  {
    std::string word;
    std::getline(std::cin, word);
    inp.push_back(word);
    if (word == "quit")
      quit = true;
  }
  std::string word;
  inp.unique();
  inp.sort();
  while(!inp.empty())
  {
    word = inp.front();
    inp.pop_front();
    std::cout << word << "\n";
  }

  return 0;
}

