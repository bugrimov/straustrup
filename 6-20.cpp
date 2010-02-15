#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>

using namespace std;

enum Token_value
{
	NAME, NUMBER, END,
	PLUS='+', MINUS='-', MUL='*', DIV='/',
	PRINT=';', ASSIGN='=', LP='(', RP=')', LF='{', RF='}'
};

double number_value;
string string_value;
int no_of_errors;
Token_value curr_tok = PRINT;
istream* input;
map<string,double> table;
map<string,bool> is_function; // это функция или переменная
map<string,string> func_body; // тела функций

double prim(bool);

int d(const string& s)
{
	cout << "DEBUG: " << s << '\n';
	return 1;
}

int error(const string& s, int line)
{
	no_of_errors++;
	cerr << "ERROR: " << s << " (line: " << line << ")\n";
	return 1;
}


double term(bool get)
{
	double left=prim(get);
	
	for (;;)
		switch (curr_tok)
    {
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d=prim(true))
			{
				left /= d;
				break;
			}
			return error("delenie na 0", __LINE__);
		default:
			return left;
    }
}



double expr(bool get)
{
  double left=term(get);

  for (;;)
    switch(curr_tok)
    {
    case PLUS:
      left += term(true);
      break;
    case MINUS:
      left -= term(true);
      break;
    default:
      return left;
    }
}


Token_value get_token()
{
	char ch;
	
	do
	{
		if (!cin.get(ch)) return curr_tok=END;
	} while (ch != '\n' && isspace(ch));

	switch(ch)
	{
		case ';':
		case '\n':
			return curr_tok=PRINT;
		// skobki !!??
		case '*': case '/': case '+': case '-': case '=': case '(': case ')': case '{': case '}':
			return curr_tok = Token_value(ch);
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8':
		case '9': case '.':
			cin.putback(ch);
			cin >> number_value;
			return curr_tok=NUMBER;
		default:
			if (isalpha(ch))
			{
				string_value=ch;
				while (cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
				//std::cout << "found name:" << string_value << '\n';
				cin.putback(ch);
				return curr_tok = NAME;
			}
			error("неправильная лексема", __LINE__);
			return curr_tok = PRINT;
	}
}



double prim(bool get)
{
  if (get) get_token();

  switch (curr_tok)
  {
  case NUMBER:
  {
    double v=number_value;
    get_token();
    return v;
  }
  case NAME:
  {
	if (is_function[string_value])
	{
		//cout << "Function call\n" ;
		string& body = func_body[string_value];
		for (int i=body.size()-1; i>=0; i--)
			cin.putback(body[i]);
		return expr(true);
	}
	else
	{
		double& v = table[string_value];

		char tok=get_token();
		if (tok == ASSIGN) v=expr(true);
		if (tok == LF)
		{
			cout << "Saving function: " << string_value << '\n';
			is_function[string_value] = true;
			string& body = func_body[string_value] = "";
			while (cin.get(tok) && tok != RF) body += tok;
			//cout << 'F' << body << "/F";// v=expr(true)

			//cout << "function body: " << tok << "<- ERROR "<< func_body[string_value] << '\n';
			return PRINT;

		}
		return v;
	}

		
  }
  case MINUS:
    return -prim(true);
  case LP:
  {
    double e=expr(true);
    if (curr_tok != RP) return error("ogidalas )", __LINE__);
    get_token();
    return e;
  }
  default:
    return error("ogidalos pervichnoe viragenie", __LINE__);
  }
}


int main(int argc, char* argv[])
{
  switch (argc)
	{
		case 1:
			input = &cin;
			break;
		case 2:
			input = new istringstream(argv[1]);
			break;
		default:
			error("to many parameters", __LINE__);
			return 1;
	}
	
	table["pi"] = 3.135523523523;
	table["e"] = 2.7234234;
	
	while (input)
	{
		get_token();
		if (curr_tok == END) break;
		if (curr_tok == PRINT) continue;
		cout << expr(false) << '\n';
	}
	if (input != &cin) delete input;
	
	return no_of_errors;
}


			
			


