#include <iostream>
//#include <vector>
//#include <algorithm>
#include <iterator>
using namespace std;

ostream_iterator<string> oo (cout);

istream_iterator<string> ii (cin);
int main()
{
	string s1 = *ii;
	++ii;
	*oo = *ii;
	++oo;
	*oo = " мир!\n";
}


