#include <iostream>

void change(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void change2(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int a = 5, b = 6;
	std::cout << a << ' ' << b << std::endl;
	change(&a, &b);
	std::cout << a << ' ' << b << std::endl;
	change2(a, b);
	std::cout << a << ' ' << b << std::endl;
}


