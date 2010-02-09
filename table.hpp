
#include "name.hpp"

class Table
{
  enum {MAX_ELEMENTS};
  Name* p;
  double* values;
  int sz;
  int curr;
public:
  Table(int s=15)
  { 
    p=new Name[sz=s]; 
    values = new double[sz];
    curr=0;
  }

  ~Table() {delete [] p;}
  bool add(Name, double);
  double Table::operator[](const char*);
};


double Table::operator[](const char* key) 
{ 
  Name* k = new Name(key);
  for (int i=0; i<curr; i++)
    if( p[i] == *k)
      return values[i];
  return 0;
}


bool Table::add(Name name, double value)
{
  if( sz >= curr)
  {
    values[curr] = value;
    p[curr] = name;
    curr++;
    return true;
  }
  else
  {
    return false;
  }
}

