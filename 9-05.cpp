#include <iostream>
#include <vector>

class Histogram
{
public:
  class Overload {
  public:
  Overload(){
    std::cout <<" AAAAa !!! \n";
    }
  };
  
  Histogram(int n[], int count);
  ~Histogram() {}
  void print();
private:
  std::vector<int> data;

};

Histogram::Histogram(int n[], int count)
{
  for (int i=0; i<count; i++)
    if (n[i] < 15)
      throw Overload();
    else
      data.push_back(n[i]);
}

void Histogram::print()
{
  for (int i=0; i<data.size(); i++)
  {
    for (int j=0; j<data[i]; j++)
      std::cout << "#";
    std::cout << "\n";
  }
}

int main()
{
  int a[5] = {5, 6,34,6,1};
  Histogram h(a ,5);
  h.print();
}