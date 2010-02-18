/*
 Переделать в класс Node
*/

#include <iostream>

struct Node
{
  int m;
  int n;

  Node(int mm, int nn)
  {
    m=mm;
    n=nn;
  }
  Node()
  {
    m=0;
    n=0;
  }
  
  void print()
  {
    std::cout << m << ":" << n << std::endl;
  }

  bool operator<(const Node&) const;
  bool operator==(const Node&) const;

};

bool Node::operator<(const Node& node) const
{
  return (m<node.m && (m==node.m && n<node.n));
}


bool Node::operator==(const Node& node) const
{
  return (m==node.m && n==node.n);
}


class Data
{
  Node node;
  Data* next;
public:
  Data(Node n) {node = n; next = 0;}
  Data* getNext() { return next; }
  void setNext(Data* d)
  { 
    if (d != this)
      next = d; 
    else
      std::cout <<"ERROR!!!!";
  }
  Node getData() { return node; }
  void print() { node.print(); }

};

class Intset
{
  Data* top;
public:
  Intset() { top = 0;}
  Intset(const Intset&);
  Intset& add(Node);
  const Intset operator+(const Intset&) const;

  bool has(Node) const;

  void print() const;

  friend Intset intersection(Intset a, Intset b);
  friend Intset simmetrical_difference(Intset a, Intset b);

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


Intset& Intset::add(Node node)
{
  if (has(node) )
    return *this;

  Data* what=new Data(node);
  if (top)
  {
    Data* el = top;
    Data* prev = 0;
    while (el)
    {
      if (node < el->getData())
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

bool Intset::has(Node i) const
{
  Data* el = top;
  while (el)
  {
    if (el->getData() == i)
    {
      return true;
    }
    el = el->getNext();
  }
  return false;
}

const Intset Intset::operator+(const Intset& b) const
{
  Intset c = *this;
  Data* el = b.top;
  while (el)
  {
    if (! c.has(el->getData()))
      c.add(el->getData());
    el = el->getNext();

  }
  std::cout << " END\n";

  c.print();

  return c;
}

Intset simmetrical_difference(Intset a, Intset b)
{
  Intset d;
  Data* el = a.top;
  while (el)
  {
    if (! b.has(el->getData()) )
      d.add(el->getData());
    el = el->getNext();
  }
  el = b.top;
  while (el)
  {
    if (! a.has(el->getData()) )
      d.add(el->getData());
    el = el->getNext();
  }
  return d;
}

Intset intersection(Intset a, Intset b)
{
  Intset d;
  Data* el = a.top;
  while (el)
  {
    if (b.has(el->getData()) )
      d.add(el->getData());
    el = el->getNext();
  }
  el = b.top;
  while (el)
  {
    if (a.has(el->getData()) )
      d.add(el->getData());
    el = el->getNext();
  }
  return d;
}


int main()
{
  Intset a;
  a.add(Node(4,1)).add(Node(2,4)).add(Node(15,5)).add(Node(10,3));

  Intset b;
  b.add(Node(3,2)).add(Node(9,5)).add(Node(15,5)).add(Node(4,3)).add(Node(5,5));

  a.print();
  b.print();


  std::cout << "Adding:\n";
  Intset c = a+b;
  c.print();
  std::cout << "Intersection:\n";
  Intset d = intersection(a, b);
  d.print();
  std::cout << "Simmetrical difference:\n";
  Intset e = simmetrical_difference(a, b);
  e.print();
}

