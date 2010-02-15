#include <iostream>

const int MAX_LEN = 10, BASE = 10;

char* itoa(int num, char where[])
{
	//std::cout << "\n!\n";
	char* & where1 = where;
	int j=0;
	char rev[MAX_LEN] = "";
	while (num > 10)
	{
		rev[j++] = '0'+num%10;
		num = num/10;
	}
	rev[j] = '0'+num%10;
	rev[++j] = '\0';
	
	for(int i=strlen(rev)-1; i>=0; i--)
	{
		*(where1++) = rev[i];
	}
	*(where1) = '\0';
	return where;
}

int main()
{
	char s[MAX_LEN] = "";
	itoa(0712334560, s);
	std::cout << s << "_\n";
}


