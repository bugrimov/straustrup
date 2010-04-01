#include <iostream>

using std::string;
using std::cout;

namespace Stack
{

  struct Element
  {
    string* data;
    Element* next;
    Element* prev;

    Element(const char* s)
    {
      data = new string(s);
      next = 0;
      prev = 0;
    }

    ~Element()
    {
      delete data;
    }
  };

  Element* last = 0;
  Element* top = 0;


  Stack::Element* push(const char*, Element*);
  Stack::Element* push(Element*, Element*);
  Stack::Element* push_top(Element*);
  Stack::Element* push_last(Element*);
  Stack::Element* push_between(Element*, Element*, Element*);
  Element* cut(Element* el);

  void print();
  void print_line();
  void print_reverse();
  void print(const Element*);

  Element* get(int);
  int cmp(const Element*, const Element*);
  void sort();
  void reverse();
  void myswitch(Element*, Element*);
}

Stack::Element* Stack::push(const char* s, Element* before=0)
{
  Element* el = new Element(s);

  return push(el, before);

}


Stack::Element* Stack::push_top(Element* el)
{
  el->prev = 0;
  top->prev = el;
  el->next = top;
  return top = el;
}

Stack::Element* Stack::push_last(Element* el)
{
  el->prev = last;
  last->next = el;
  el->next = 0;
  return last = el;
}

Stack::Element* Stack::push_between(Element* el, Element* el1, Element* el2)
{
  el1->next = el;
  el->prev = el1;
  el2->prev = el;
  el->next = el2;
  return el;
}

Stack::Element* Stack::push(Element* el, Element* before=0)
{

  if (!top)
  {
    el->prev = 0;
    el->next = 0;
    top = el;
    last = el;
    return el;
  }

  if (before)
  {
    if (before == top)
      return push_top(el);
    else if (before->prev)
      return push_between(el, before->prev, before);
    else
    {
      cout << "ERROR!!! cannot paste element before:\n";
      print(el);
      print(before);
    }
  }
  else
  {
    cout << "LAST: ";
    print(el);
    return push_last(el);
  }
}

void Stack::print()
{
  Element* t = top;
  print(t);
  while ((t = t->next) != 0)
    print(t);
}

void Stack::print_line()
{
  Element* t = top;
  cout << "LINE: " << *(t->data);
  while ((t = t->next) != 0)
    cout << " " << *(t->data);
  cout << '\n';
}

void Stack::print_reverse()
{
  Element* t = last;
  print(t);
  cout << "was 'last'\n";
  while ((t = t->prev) != 0)
    print(t);
}

void Stack::reverse()
{
  Element* t = last;
  Element* was_top = top;
  Element* prev=0;
  do
  {
    //print(t);
    prev = t->prev; // before cut!!!
    cut(t);

    //print_line();
    push(t,was_top);
    //print_line();
    t = prev;
  }
  while (t != was_top);
}

void Stack::print(const Element* el)
{
  if(el)
    cout << *(el->data) << "\t" << el << " prev: " << el->prev << "\tnext: " << el->next << '\n';
  else
    cout << "(empty)\n";
}

Stack::Element* Stack::get(int n)
{
  Element* t = top;
  for (int i=0; i<n && (t = t->next) != 0; i++);
  return t;
}

int Stack::cmp(const Element* el1, const Element* el2)
{
  //cout << "Compare\n";
  //print(el1);
  //print(el2);
  int i;
  string data1 = *(el1->data), data2 = *(el2->data);
  for(i=0; data1[i] == data2[i] && i<data1.size()-1 && i<data2.size()-1; i++);
  if (data1[i] == data2[i]) return 0;
  else if (data1[i] < data2[i]) return 1;
  else return -1;
}

Stack::Element* Stack::cut(Element* el)
{
  Element* prev = el->prev;
  Element* next = el->next;
  if (prev && next)
  {
    prev->next = el->next;
    next->prev = el->prev;
  }
  else if (prev)
  {
    last = prev;
    prev->next = 0;
  }
  else if (next)
  {
    top = next;
    next->prev = 0;
  }
  else
    last = top = prev->next = next->prev = 0;

  el->next = el->prev = 0;
  return el;
}

void Stack::myswitch(Element* el1, Element* el2)
{
  if(el2 && el1)
  {
    cut(el2);
    push(el2, el1);
  }
  else
  {
    cout << "SWITCH: can't\n";
    print(el1);
    print(el2);
  } 
}

void Stack::sort()
{
  bool need_change = true;
  while (need_change)
  {
    need_change = false;
    Element* t = top;
    do
    {
      if (cmp(t, t->next) == -1)
      {
        //cout << "SWITCH:\n";
        //print(t);
        //print(t->next);
        myswitch(t, t->next);
        //print_line();
        need_change = true;
      }
    }
    while ((t = t->next) != 0 && t->next != 0);
    
  }
}

int main()
{
  Stack::push("odin");
  Stack::Element* tri = Stack::push("tri");
  Stack::push("dva", tri); 
  Stack::push("chetyre"); 
  Stack::push("pyat'"); 
  Stack::print();
  /*
  cout << "== REVERSEd print\n";
  Stack::print_reverse();
  cout << "== SORTing\n";
  Stack::sort();
  cout << "== after SORT\n";
  Stack::print();
  cout << "== TOP and LAST\n";
  Stack::print(Stack::top);
  Stack::print(Stack::last);

  cout << "== REVERSEd print\n";
  Stack::print_reverse();
  */
  cout << "== REAL REVERSE\n";
  Stack::reverse();
  cout << "== after REVERSE\n";
  Stack::print();
}



