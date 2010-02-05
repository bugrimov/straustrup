#include <iostream>
#include <fstream>
#include <iterator>
#include <map>

using namespace std;

map<string, int> histogram;

void record(const string& s);
void print(const pair<const string, int>& r);

int main()
{


  string from, to;
  cin >> from;

  ifstream is(from.c_str());
  istream_iterator<string> ii(is);
  istream_iterator<string> eos;

  for_each(ii, eos, record);
  for_each(histogram.begin(), histogram.end(), print);

}

void record(const string& s)
{
  histogram[s]++;
}

void print(const pair<const string, int>& r)
{
  cout << r.first << ' ' << r.second << '\n';
}
