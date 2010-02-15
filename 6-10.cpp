#include <iostream>

int strlen1(const char * str)
{
	int len = 0;
	while ( str[len]!='\0')
		len++;
	return len;
}

int strcpy1(const char* what, char* where)
{
	do {
		*where = *what;
		where++;
	}
	while (*(what++)!='\0');
	return 0;
}

bool strcmp1(const char* s1, const char* s2)
{
	while ( *s1 == *s2 && *s1!='\0' && s2!='\0')
	{
		s1++;
		s2++;
	}
	return *s1 == *s2;
}

int main()
{
	char s[] = "bakaka";
	std::cout << strlen1(s) << '\n';
	strcpy1("ktoksdfsdfsdf56", s);
	std::cout << s << '\n';
	std::cout << strcmp1(s, "sdf") << ' ' << strcmp1(s, "ktoksdfsdfsdf56") << '\n';
	std::cout << strcmp1("sdf", s) << ' ' << strcmp1("ktoksdfsdfsdf56", s) << '\n';
	strcpy1("sdf", s);
	std::cout << strcmp1("sdf", s) << ' ' << strcmp1("ktoksdfsdfsdf56", s) << '\n';
}



