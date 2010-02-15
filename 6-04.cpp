#include <iostream>

// 183
int main()
{
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
		{
			std::cout << i << '&' << j << '=' << (i&j) << '\n';
		}
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
		{
			std::cout << i << '|' << j << '=' << (i|j) << '\n';
		}
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
		{
			std::cout << i << '^' << j << '=' << (i^j) << '\n';
		}
	for (int j=0; j<2; j++)
	{
		std::cout << "~" << j << '=' << (~j) << '\n';
	}
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
		{
			std::cout << i << "<<" << j << '=' << (i<<j) << '\n';
		}
	for (int i=0; i<4; i++)
		for (int j=0; j<3; j++)
		{
			std::cout << i << ">>" << j << '=' << (i>>j) << i/j << '\n';
		}
}



