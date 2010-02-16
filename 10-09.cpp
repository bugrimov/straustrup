/*
 Определите и реализуйте и оттестируйте класс Intset для множества целых
 чисел. Реализуйте операции объединения, пересечения и симметричной разности.
*/

#include <iostream>

class Data
{
  int num;
  Data* next;
  bool has_next;
public:
  Data(int n) {num = n; next = 0; has_next=false;}
  Data* getNext() { return next; }
  bool hasNext() { return has_next; }
  void setNext(Data* d)
  { 
    if (d != this)
      next = d; 
    else
      std::cout <<"ERROR!!!!";
    has_next = true;
  }
  int getData() { return num; }
  void print() { std::cout << num << std::endl; }
};

class Intset
{
  Data* top;
  //Data* curr;
  //void add_before(Data* what, Data* before);
public:
  Intset() { top = 0;}
  Intset(const Intset&);
  Intset& add(int num);
  const Intset operator+(const Intset&) const;

  bool has(int) const;

  //int pop();
  //void newPop();
  //bool canPop();

  void print() const;
};

Intset::Intset(const Intset& b)
:top(0)
{
  Data* el = b.top;
  while (el)
  {
    //std::cout << el->getData();
    add(el->getData());
    if (el != el->getNext())
      el = el->getNext();
    else
      std::cout << "?????";
  }
  //std::cout << "copy end\n";
}


Intset& Intset::add(int num)
{
  if (has(num) )
    return *this;

  Data* what=new Data(num);
  if (top)
  {
    Data* el = top;
    Data* prev = 0;
    while (el)
    {
      if (num < el->getData())
        if (prev == 0)
        {
          what->setNext(el);
          top = what;
          return *this;
        }
        else
        {
          prev->setNext(what);
          what->setNext(el);
          return *this;
        }

      prev = el;
      el = el->getNext();
    }


    if ( prev )
      prev->setNext(what);
    else
      std::cout << "Something was wrong.\n";
  }
  else
  {
    top = what;
  }
  //print();

  return *this;
}

void Intset::print() const
{
  std::cout << "\nPrinting " << this << ":\n";

  Data* el = top;
  while (el)
  {
    el->print();
    el = el->getNext();
  }
}

bool Intset::has(int i) const
{
  Data* el = top;
  while (el)
  {
    //std::cout << " [" << el << " " << el->getData() << " " << el->getNext() << "]";
    if (el->getData() == i)
    {
      //std::cout << "[has]";
      return true;
    }
    el = el->getNext();
  }
  //std::cout << "[not has]";
  return false;
}

const Intset Intset::operator+(const Intset& b) const
{
  Intset c = *this;
  Data* el = b.top;
  while (el)
  {
    //std::cout << "+" << el->getData();
    if (! c.has(el->getData()))
      c.add(el->getData());
    el = el->getNext();

  }
  std::cout << " END\n";

  c.print();

  return c;
}


int main()
{
  Intset a;
  a.add(4).add(2).add(15).add(10);

  Intset b;
  b.add(3).add(9).add(15).add(4).add(3);

  a.print();
  b.print();

  //std::cout << a.has(1) << a.has(10);


  std::cout << "START\n";
  Intset c = a+b;
  std::cout << " END\n";

  c.print();
}

