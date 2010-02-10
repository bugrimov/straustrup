#include <iostream>

using namespace std;

int main()
{
	bool in_line=false, in_multi=false;
	char ch, prev = '\0';
	while (cin.get(ch))
	{
		//cout << "!";
		
		if ( prev == '/' && ch == '*' && !in_line)
			in_multi = true;
		else if (prev == '*' && ch == '/' && in_multi)
		{
			in_multi = in_line = false;
			prev = '\0';
			continue;
		}
		else if (prev == '/' && ch == '/' && ! in_multi)
			in_line = true;
		else if (ch == '\n' && in_line)
		{
			in_line = false;
			prev = '\0';
		}
		
		if (! in_line && ! in_multi && prev != '\0')
			cout << prev;

		prev = ch;
		if ( prev == '\n')
		{
			cout << prev;
			prev = '\0';
		}
			
	}
	
}


