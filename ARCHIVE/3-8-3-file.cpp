#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
  string from, to;
  cin >> from >> to;

  ifstream is(from.c_str());
  istream_iterator<string> ii(is);
  istream_iterator<string> eos;

  vector<string> b(ii, eos);
  sort(b.begin(), b.end());

  ofstream os(to.c_str());
  //ostream_iterator<string> oo(os,"\n");
  ostream_iterator<string> oo(os);
  unique_copy(b.begin(), b.end(), oo);

  return !is.eof() || !os;
}

