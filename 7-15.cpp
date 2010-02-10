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
	ARGS_DELIM = ',',
	DIRECTIVE_START='#', END_LINE='\n',
	PLUS='+', MINUS='-', MUL='*', DIV='/',
	PRINT=';', ASSIGN='=', LP='(', RP=')', LF='{', RF='}'
};

string string_value;
int no_of_errors;
Token_value curr_tok = PRINT;
map<string,string> table;
map<string,vector<string> > args;
istream* input = &cin;

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
	
	if (!input->get(ch)) return curr_tok=END;
	string_value=ch;
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
		case LP:
			return curr_tok = LP;
		case RP:
			return curr_tok = RP;
		case ',':
			return curr_tok = ARGS_DELIM;
		case '#':
				string_value="";
				while (input->get(ch) && isalnum(ch)) string_value.push_back(ch);
				input->putback(ch);
				return curr_tok = DIRECTIVE_START;
		default:
			if (isalpha(ch))
			{
				
				while (input->get(ch) && (isalnum(ch) || ch =='_')) string_value.push_back(ch);
				input->putback(ch);
				return curr_tok = NAME;
			}
			return curr_tok = OTHER;
	}
}

void show_vector(vector<string>* v)
{
	for (int i=0; i< v->size(); i++)
		cout << (*v)[i] << " ";
	cout << '\n';
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
			{
				string name = string_value;
				if (get_token() == LP)
				{
					map<string, string> values;
					vector<string>* theArgs = &args[name];
					vector<string>::iterator it;
					it = (*theArgs).begin();
					string value = "";
					while (get_token() != RP)
						if (curr_tok == ARGS_DELIM)
						{
							values[*(it++)] = value;
							value = "";
							//it++;
						}
						else if (curr_tok != SPACE){
							value += string_value;
						}
					//show_vector(theArgs);
					values[*(it)] = value;
					
					string body = "";
					
					//d("BODY: " + table[name]);
					input = new istringstream(table[name]);
					while (*input)
					{
						get_token();
						//d(string_value);
						if (curr_tok == NAME && values.count(string_value))
						{
							//d("!!!" + values[string_value]);
							body += values[string_value];
						}
						else
							body += string_value;
					}
					input = &cin;
					 
					return body;
				}
				else
				{
					input->putback(curr_tok);
					return table[string_value];
				}
			}
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
				if (curr_tok == LP)
				{
					vector<string>* theArgs;
					theArgs = &args[name];
					int i = 0;
					while (get_token() != RP)
						if (curr_tok == NAME)
							(*theArgs).push_back(string_value);
						if (curr_tok == ARGS_DELIM)
							i++;
					while (get_token() == SPACE);
				}
				do macro_body += string_value;
				while (get_token() !=	END_LINE);
				//d("Macro defined: " + name + ": " +macro_body);
				return "";
			}
			else
				return "#"+string_value;
		//case SPACE:
		default:
			return string_value;
	}
}


int main(int argc, char* argv[])
{	
	while (*input)
	{
		get_token();
		if (curr_tok == END) break;
		cout << prim(false);
	}
	
	return no_of_errors;
}


			
			


