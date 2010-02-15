#include <iostream>
#include <fstream>
#include <string>
#define START 1
#define CLOSE_FILE thefile.close()
#define PRINT(a, b) cout << a << b << endl

using namespace  std;

int main(int argc, char* argv[])
{
	for (int i=START; i<argc; i++)
	{
		string line;
		ifstream thefile(argv[i]);
		if (thefile.is_open())
		{
			while (! thefile.eof() )
			{
				getline (thefile, line);
				PRINT(line, "asd");
			}
			CLOSE_FILE;
		}
		else cout << "Unable to open youre fucking file: " << argv[i];
		
	}
}

