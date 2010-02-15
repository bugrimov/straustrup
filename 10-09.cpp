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
  void setNext(Data* d)
  { 
    if (d != this)
      next = d; 
    else
      std::cout <<"ERROR!!!!";
  }
  int getData() { return num; }
  void print() { std::cout << num << std::endl; }
};

class Intset
{
  Data* top;
  Data* curr;
  //void add_before(Data* what, Data* before);
public:
  Intset() { curr=top = 0;}
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
{
  Data* el = b.top;
  while (el)
  {
    add(el->getData());
    el = el->getNext();
  }
}


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

    if(el && el->getData() == num)
      return *this;

    if (prev == 0)
    {
      what->setNext(top);
      curr = top = what;
    }
    else if (!el && prev)
    {
      prev->setNext(what);
    }
    else if (el)
    {
      prev->setNext(what);
      what->setNext(el);
    }
    else
      std::cout << "Something was wrong.\n";
  }
  else
  {
    curr = top = new Data(num);
  }
  print();

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

/*
bool Intset::canPop()
{
  if (curr)
    return true;
  else
    return false;
}

int Intset::pop()
{
  if (curr)
  {
    int i = curr->getData();
    curr = curr->getNext();
    //std::cout << "[" << curr << "]";
    return i;
  }
  else
  {
    curr = 0;
    return 0;
  }
}

void Intset::newPop()
{
  curr = top;
}
*/
bool Intset::has(int i) const
{
  Data* el = top;
  while (el)
  {
    if (el->getData() == i)
      return true;
    el = el->getNext();
  }

  return false;
}

const Intset Intset::operator+(const Intset& b) const
{
  Intset c = *this;

  Data* el = top;
  while (el)
  {
    std::cout << "+" << el->getData();
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
  a.add(4).add(9).add(15).add(10);

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

