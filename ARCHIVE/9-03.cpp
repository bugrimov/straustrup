#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <fstream>




using namespace std;

string find2(string, string);

struct FileInfo
{
  string name;
  string path;
  int words;
  int line_comments;
  int line_no_comments;
  bool currLineCommented;
  int level;

  FileInfo()
  {
    name = "";
    path = "";
    words = 0;
    line_comments = 0;
    line_no_comments = 0;
    currLineCommented = false;
    level = 0;
  }

};

//map<string, FileInfo*> fi;
vector<FileInfo*> fi;
FileInfo* curr_file = new FileInfo();

enum Token_value
{
	NAME, NUMBER, END, 
	SLASH = '/', 
	DIRECTIVE = '#',
	END_LINE = '\n',
	PLUS='+', MINUS='-', MUL='*',
	PRINT=';', ASSIGN='=', LP='(', RP=')'
};

string string_value;
int no_of_errors;
Token_value curr_tok = PRINT;
Token_value prev_tok = PRINT;
istream* input;
//map<string,double> table;
int level = 0;

void prim(bool);


int error(const string& s, int line)
{
	no_of_errors++;
	cerr << "ERROR: " << s << " (line: " << line << ")\n";
	return 1;
}


Token_value get_token()
{
	char ch;

	prev_tok = curr_tok;
	
	do
	{
   	        input->get(ch);
		if (input->eof() || !input->good()) return curr_tok=END;

	} while (ch != '\n' && isspace(ch));

	string_value = ch;

	switch(ch)
	{
		case '#':
		       return curr_tok = DIRECTIVE;
		case ';':
		case '\n':
		//	return curr_tok=END_LINE;
		// skobki !!??
		case '/': 
		    //return curr_tok = SLASH;
		case '*': case '+': case '-': case '=': case '(': case ')':
			return curr_tok = Token_value(ch);
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8':
		case '9': case '.':
			input->putback(ch);
			*input >> string_value;
			return curr_tok=NUMBER;
		default:
			if (isalpha(ch))
			{
				while (input->get(ch) && isalnum(ch)) string_value.push_back(ch);
				input->putback(ch);
				curr_file->words++;
				return curr_tok = NAME;
			}
			//error("UNKNOWN LEMMA", __LINE__);
			return curr_tok = PRINT;
	}
}

void prim(bool get)
{
  if (get) get_token();

  switch (curr_tok)
  {
    case END_LINE:
      if( curr_file )
      {
        curr_file->line_no_comments++;
        curr_file->currLineCommented = false;
      }
      break;
    case SLASH:
      if ( prev_tok == SLASH )
      {
        curr_file->line_comments++;
        curr_file->currLineCommented = true;
      }
      break;
      
    case DIRECTIVE:
      if ( prev_tok == END_LINE && get_token() == NAME && string_value == "include" 
            )
      {
        while (get_token() != NAME);

        istream* prev_input = input;

        /*
        for (int i=0; i<level; i++)
          cout << ' ';
        cout << string_value;
        */
        /*
        int prev_level;
        if (curr_file)
          prev_level = curr_file->level;
        else
          prev_level = 0;
        */
        
        string filename = find2("C:\\MinGW\\include\\",string_value); //+".h");
        if(filename == "")
        {
          filename = find2("C:\\MinGW\\include\\",string_value+".h");
	}

        if(filename == "")
        {
          cout << "\t[not found]\n";
        }
        else 
        {
          cout << "\t" << filename << '\n';

          input = new ifstream(filename.c_str());

          if (input)
          {
            
            curr_file = new FileInfo();
            curr_file->name = string_value;
            curr_file->path = filename;
            fi.push_back(curr_file);

            curr_file->level = level++;
            while (curr_tok != END)
            {
             get_token();
             prim(false);
            }
            //input.close();

	    /*
	    for (int i=0; i<level; i++)
              cout << ' ';
            cout << "Line-comments: "<< curr_file->line_comments << '\n';
            */
            input = prev_input;
            level--;
          }
          else
            cout << "FILE read error: " << filename << '\n';
        } //filename
      }
    default:
      // er 
      ;
  }
}


int main(int argc, char* argv[])
{
  input = &cin;
	
	while (input)
	{
		get_token();
		if (curr_tok == END) break;
		if (curr_tok == PRINT) continue;
		prim(false);
	}


	cout << "END\n";

	for (int i=0; i<fi.size(); i++)
	{
	  string space = "";
          for (int j=0; j<fi[i]->level; j++)
            space += ' ';

	  cout << space << fi[i]->name << "\t" << fi[i]->path << endl;

	  cout << space << "\t" << fi[i]->line_comments <<
	         " " << fi[i]->line_no_comments << " " << fi[i]->words << endl;


	}
	
	return no_of_errors;
}


			
			


