#include <iostream>

using namespace std;

enum { MIN_KEY_SIZE=1, MAX_KEY_SIZE=5, FILE_SIZE=10*1024};


bool set_next_key(char * key, int size)
{
	int i = size-1;
	while (key[i]++ >= 'z')
	{
		key[i] = 'a';
		if (i--<=0)
			return false;
	}
	return true;
}

bool check_filedata(const char* const filedata, int filesize, const char* const key, int key_size, char* const resdata)
{
	//char test_data[FILE_SIZE];
	int key_pos = 0;
	char c;
	for (int i=0; i<filesize; i++)
	{
		c = filedata[i]^key[key_pos];
		if( ! (isprint(c) || c == '\n' || c == '\t'))
		    return false;
		else
			resdata[i] = c;
		
		if (++key_pos >= key_size)
			key_pos = 0;
	}
	return true;
}

int main(int argc, char* argv[])
{	
	char c;
	char begin[FILE_SIZE] = "";
	char resdata[FILE_SIZE] = "";
	char* filedata = begin;
	int file_len;
	for(file_len=0; cin.get(c); file_len++)
		*(filedata++) = c;
	*(filedata) = '\0';
	filedata = begin;
	/*
	cout << "!!!" << filedata;
	cout << check_filedata(filedata, file_len, "qwe", 3, resdata);
	cout << "!!!" << resdata;
	return 0;
	*/
	char key[10] = "a";
	bool yes = true;
	for (int key_size=MIN_KEY_SIZE; key_size<=MAX_KEY_SIZE; key_size++)
	{
		
		// initalize key
		
		for(int i=0; i<key_size; i++)
			key[i] = 'a';
		key[key_size] = '\0';
		cout << "SIZE: " << key_size << "\n";

		do
		{
			//|| (key[0]=='q' && key[1]=='w' && key[2] == 'e')
			if (check_filedata(filedata, file_len, key, key_size, resdata) )
			{
				cout << "\nKEY: " << key << "\n";
				cout << resdata << '\n';
				//yes = false; // exit from keys cycle
			}
		}
		while (yes && set_next_key(key, key_size));
	}
}


