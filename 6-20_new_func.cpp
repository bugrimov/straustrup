#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

enum Token_value
{
	NAME, NUMBER, END,
	PLUS='+', MINUS='-', MUL='*', DIV='/',
	PRINT=';', ASSIGN='=', LP='(', RP=')', LF='{', RF='}'
};

struct Symbol
{
	Token_value tok = PRINT;
	double number_value;
	string string_value;
};

int no_of_errors;
Symbol curr_symb;
istream* input;
map<string,double> table;
map<string,bool> is_function; // это функция или переменная
map<string,string> func_body; // тела функций
map<string, vector<string> > func_args;

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
	
	// всегда храним строковое значение токена чтобы иметь возможность
	// сохранять его при записи тела функции
	string_value = ch;
	
	stringstream s1;
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
			
			s1 << number_value;
			s1 >> string_value;
			return curr_tok=NUMBER;
		default:
			if (isalpha(ch))
			{
				while (cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
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
			string prev = string_value;
			
			// надо вызывать перед get_token так как он трет string_value
			string& body = func_body[string_value];
			vector<string>& args = func_args[string_value];
			
			char tok=get_token();
			
			if (tok == ASSIGN) {
				double& v=table[prev];
				v=expr(true);
				return v;
			}
		

			if (body.size() > 0)
			{
				

				
				
				// если нет скобок то это видимо вызов обычной переменной
				if(tok == LP){
					// временное хранилище для переменных которые уже были определены ранее
					map<string,double> temp_var; 
					int i=0;
					while (tok=get_token() != RP)
					{
						string var = args[i++];
						temp_var[var] = table[var];
						cout << var << "=" << number_value << '\n';
						table[var] = number_value;
					}
					
					cin.putback(RP);
					for (int i=body.size()-1; i>=0; i--)
						cin.putback(body[i]);
					cin.putback(LP);
					
					double res = expr(true);
					
					// вернуть значения переопределенных переменных
					for (int i=0; i<args.size(); i++)
						table[args[i]] = temp_var[args[i]];
					
					return res;
				}
			}
			else
			{

				if (tok == LP)
				{
					while (tok=get_token() != RP)
						if (curr_tok == NAME)
							args.push_back(string_value);
						else
							error("в качестве аргумента в объявлении можно использовать только имя переменной", __LINE__);
					tok=get_token();
						
				}
				if (tok == LF) 
				{
					while (tok=get_token() != RF) body += string_value;
					return 0; // определение функции нолик возвращает
				}
			}
			//если это обычная переменная
			return table[prev];
			
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






