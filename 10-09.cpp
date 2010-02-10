/*
 Определите и реализуйте и оттестируйте класс Intset для множества целых
 чисел. Реализуйте операции объединения, пересечения и симметричной разности.
*/

#include <iostream>

class Data
{
  int num;
  Data* next;
public:
  Data(int n) {num = n; next = 0;}
  Data* getNext() { return next; }
  int getData() { return num; }
  void print() { std::cout << num << std::endl; }
};

class Intset
{
  Data* top;
  add_before(Data* what, Data* before);
public:
  Intset() { top = 0; }
  Intset& Data::add(int num);
  void print();
};


Intset& Intset::add(int num)
{
  if (top)
  {
    Data* what=new Data(num);
    Data* el = top;
    Data* prev = 0;
    while (el && el->getData() < num)
    {
      prev = el;
      el = el->getNext();
    }

    if (prev == 0)
    {
      what->setNext(top);
      top = what;
    }
    //else if ()

  }
  else
  {
    top = new Data(num);
    return *this;
  }
}

void Intset::print()
{
  Data* el = top;
  while (el)
  {
    el->print();
    el = el->getNext();
  }
}






