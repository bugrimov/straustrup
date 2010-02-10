#include <iostream>
#include <limits>

struct Overhead
{
};

struct DivisionZero
{
};

void assert1(double a, double b, double c)
{
	if (c == a || c == b || c == std::numeric_limits<double>::infinity() || c == -std::numeric_limits<double>::infinity() )
		throw Overhead();
}

double plus(double a, double b)
{
	std::cout << a << "+" << b << '=' << a+b;
	double c = a+b;
	assert1(a, b, c);
	return (a+b);
}

double minus(double a, double b)
{
	std::cout << a << "-" << b << '=' << a-b;
	double c = a-b;
	assert1(a, b, c);
	return (a-b);
}

double multiply(double a, double b)
{
	//std::cout << a << "-" << b << '=' << a-b;
	double c = a*b;
	assert1(a, b, c);
	return c;
}

double divide(double a, double b)
{
	if (b == 0) throw DivisionZero();
	//std::cout << a << "-" << b << '=' << a-b;
	double c = a/b;
	assert1(a, b, c);
	return c;
}


int main()
{
	// i < std::numeric_limits<double>::max()
    for (double i = std::numeric_limits<double>::max(); ; i/=10)
		try
		{
			std::cout << divide(i,0) << '\n';
		}
		catch (Overhead)
		{
			std::cout << "overhead!\n";
			break;
		}
	
}
