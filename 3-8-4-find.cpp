#include <iostream>
#include <fstream>
#include <iterator>
#include <map>

using namespace std;

map<string, int> histogram;

void record(const string& s);
void print(const pair<const string, int>& r);

bool gt_42(const pair<const string, int>& r)
{
  return r.second > 2;
}



int main()
{


  string from, to;
  cin >> from;

  ifstream is(from.c_str());
  istream_iterator<string> ii(is);
  istream_iterator<string> eos;

  for_each(ii, eos, record);

  typedef map<string,int>::const_iterator MI;  
  //MI i = find_if(histogram.begin(), histogram.end(), gt_42);
  MI eoi;
  //print(*i);
  for_each(find_if(histogram.begin(), histogram.end(), gt_42), eoi, print);

}

void record(const string& s)
{
  histogram[s]++;
}

void print(const pair<const string, int>& r)
{
  cout << r.first << ' ' << r.second << '\n';
}
