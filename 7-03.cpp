#include <iostream>

int main(int argc, char * argv[])
{
	for (int i=1; i<argc; i++)
		std::cout << "Превед " << argv[i] << '\n';
}


