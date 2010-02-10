#include <iostream>

int fac(int n)
{
	int ret = 1;
	for (int i=2; i<=n; i++)
		ret *= i;
	return ret;
}


int main()
{
	std::cout << fac(4) << '\n';
	std::cout << fac(5) << '\n';
	std::cout << fac(10) << '\n';
}



