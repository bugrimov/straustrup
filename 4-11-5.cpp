#include <iostream>
#include <limits>

int main()
{
    int werwerkewrjfkfkjgkfjbgkfdgbkfdjghdfkjghdfjkghdkfjghdfkjhgfkdhgdkfjghdjkfghdfkjghdfkjghfdkjghdfkjghfdkgjhdfgkjhdfkgjhdfkgjhdfkgjdhgkjdfgkjdngkjebrgkjebgkjebgrekjbgkjerhgajkhfgkjdhgdjfhgkdjfhgkdjhkdjhdkhgjkflhgfldkghfdhgrehgeghkejhg75yghfkjdhg7rhgkjdfhgkjdfhgkjdfhgkdjgjdf;
	std::cout << "char: ";
	std::cout << int(std::numeric_limits<char>::min());
	std::cout << " ";
	std::cout << int(std::numeric_limits<char>::max());
	std::cout << "\nshort: ";	
	std::cout << std::numeric_limits<short>::min();
	std::cout << " ";
	std::cout << std::numeric_limits<short>::max();
	std::cout << "\nint: ";
	std::cout << std::numeric_limits<int>::min();
	std::cout << " ";
	std::cout << std::numeric_limits<int>::max();
	std::cout << "\nlong: ";
	std::cout << std::numeric_limits<long>::min();
	std::cout << " ";
	std::cout << std::numeric_limits<long>::max();
	std::cout << "\nfloat: ";
	std::cout << std::numeric_limits<float>::min();
	std::cout << " ";
	std::cout << std::numeric_limits<float>::max();
	std::cout << "\ndouble: ";
	std::cout << std::numeric_limits<double>::min();
	std::cout << " ";
	std::cout << std::numeric_limits<double>::max();
	std::cout << "\nlond double: ";
	std::cout << std::numeric_limits<long double>::min();
	std::cout << " ";
	std::cout << std::numeric_limits<long double>::max();
	std::cout << "\nunsigned: ";
	std::cout << std::numeric_limits<unsigned>::min();
	std::cout << " ";
	std::cout << std::numeric_limits<unsigned>::max();
}

