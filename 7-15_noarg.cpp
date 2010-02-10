#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

enum Token_value
{
	NAME, OTHER, END, SPACE,
	DIRECTIVE_START='#', END_LINE='\n',
	PLUS='+', MINUS='-', MUL='*', DIV='/',
	PRINT=';', ASSIGN='=', LP='(', RP=')', LF='{', RF='}'
};

string string_value;
int no_of_errors;
Token_value curr_tok = PRINT;
map<string,string> table;

string prim(bool);

int d(const string& s)
{
	cout << "DEBUG: " << s << '\n';
	return 1;
}

int error(const string& s, int line=0)
{
	no_of_errors++;
	cerr << "ERROR: " << s;
	if (line != 0 )
		cout << " (line: " << line << ")";
	cout << "\n";
	return 1;
}


Token_value get_token()
{
	char ch;
	
	if (!cin.get(ch)) return curr_tok=END;
	
	switch(ch)
	{
		case EOF:
			return curr_tok=END;
		case '\n':
			return curr_tok = END_LINE;
		case ' ':
		case '\t':
			string_value = ch;
			return curr_tok = SPACE;
		case '#':
			//if (isalpha(ch))
			{
				string_value="";
				while (cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
				cin.putback(ch);
				return curr_tok = DIRECTIVE_START;
			}
			return curr_tok = PRINT;
		default:
			if (isalpha(ch))
			{
				string_value=ch;
				while (cin.get(ch) && (isalnum(ch) || ch =='_')) string_value.push_back(ch);
				cin.putback(ch);
				return curr_tok = NAME;
			}
			string_value=ch;
			return curr_tok = OTHER;
	}
}


string prim(bool get)
{
  if (get) get_token();

  switch (curr_tok)
  {
  case END_LINE:
		  return "\n";
  case NAME:
		  if (table.count(string_value))
			  return table[string_value];
		  else
		    return string_value;
  case DIRECTIVE_START:
		  if (string_value == "define")
		  {
			  while (get_token() != NAME && curr_tok != END_LINE);
			  string name = string_value;
			  string& macro_body = table[name];
			  macro_body = "";
			  while (get_token() == SPACE);
			  do macro_body += string_value;
			  while (get_token() !=	END_LINE);
			  d("Macro defined: " + name + ": " +macro_body);
			  return "";
		  }
		  else
			  return "#"+string_value;
	  case SPACE:
  default:
		  return string_value;
  }
}


int main(int argc, char* argv[])
{	
	while (cin)
	{
		get_token();
		if (curr_tok == END) break;
		cout << prim(false);
	}
	
	return no_of_errors;
}


			
			


