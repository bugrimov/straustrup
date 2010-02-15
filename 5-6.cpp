#include <iostream>

void f(char c)
{
	std::cout << c << std::endl;
}

void g(char& c)
{
	std::cout << c << std::endl;
}

void h(const char& c)
{
	std::cout << c << std::endl;
}
	

int main()
{
	f('a');
	//g('a');
	h('a');
	f(49);
	//g(49);
	h(49);
	char c = 'c';
	f(c);
	g(c);
	h(c);
	unsigned char v='g';
	f(v);
	//g(v);
	h(v);
	signed char b = 'b';
	f(b);
	//g(b);
	h(b);
	
}


