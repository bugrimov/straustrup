#include <iostream>

using namespace std;

int length(char* s)
{
	int i;
	for(i=0; s[i] != '\0'; i++);
	return i;
}

int main(int argc, char* argv[])
{
	char* key;
	if (argc < 2)
	{
		cout << "Need key.\n";
		return 0;
	}
	else
	{
		key = argv[1];
	}
	
	char c;
	int i = 0, len = length(key);
	while (cin.get(c))
	{
		c = (c)^key[i];
		cout << c;
		if (++i >= len)
			i = 0;
	}
}


