#include <iostream>

void printChars(char c, char to)
{
	while (c <= to) 
	{
		std::cout << c << " " << std::
		hex << int(c) << std::endl;
		c++;
	}
}

int main()
{
	printChars('a', 'z');
	printChars('0','9');

}



