/*
 ���������� � ���������� � ������������ ����� Intset ��� ��������� �����
 �����. ���������� �������� �����������, ����������� � ������������ ��������.
*/

#include <iostream>

class Data
{
  int num;
  Data* next;
public:
  Data(int n) {num = n; next = 0;}
  Data* getNext() { return next; }
  void setNext(Data* d) { next = d; }
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
  Intset& add(int num);
  Intset& operator+(Intset&);

  bool has(int);

  int pop();
  void newPop();
  bool canPop();

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
  return *this;
}

void Intset::print()
{
  std::cout << "\nPrinting " << this << ":\n";

  Data* el = top;
  while (el)
  {
    el->print();
    el = el->getNext();
  }
}

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
    return i;
  }
  else
    return 0;
}

void Intset::newPop()
{
  curr = top;
}

bool Intset::has(int i)
{
  newPop();
  while (canPop())
    if (pop() == i)
      return true;
  return false;
}

Intset& Intset::operator+(Intset& b)
{
  // need copy constructor here
  // create new set from this,
  // then add elements from b

  newPop();
  while (canPop())
    if (! b.has(pop()))

  
}


int main()
{
  Intset a;
  a.add(4).add(9).add(15).add(10);

  Intset b;
  b.add(3).add(9).add(15).add(4).add(3);

  a.print();
  b.print();

  std::cout << a.has(1) << a.has(10);

  //Intset c = a+b;
  //c.print();
}

