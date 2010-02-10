
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
  double& Table::operator[](const char*);
  double& Table::operator[](std::string);
};

double& Table::operator[](std::string str) 
{ 
  return (*this)[str.c_str()];
}

double& Table::operator[](const char* key) 
{ 
  Name* k = new Name(key);
  for (int i=0; i<curr; i++)
    if( p[i] == *k)
      return values[i];

  values[curr] = 0;
  Name* n = new Name(key);
  p[curr] = *n;
  curr++;
  return values[curr-1];
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

