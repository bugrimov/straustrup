#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
#include "table.hpp"

using std::cout;
using std::cerr;
using std::cin;
using std::istream;
using std::string;
using std::map;
using std::istringstream;

namespace Tokenz
{

enum Token_value
{
	NAME, NUMBER, END,
	PLUS='+', MINUS='-', MUL='*', DIV='/',
	PRINT=';', ASSIGN='=', LP='(', RP=')'
};

double number_value;
string string_value;
Token_value curr_tok = PRINT;

Token_value get_token();

} // Tokenz


namespace Calc
{

int no_of_errors;
istream* input;
//map<string,double> table;
Table table;

double prim(bool);
int d(const string& s);
int error(const string& s, int);
double term(bool);
double prim(bool);
double expr(bool);

struct DivisionZero
{
};

struct GdeSkobka
{
};

struct PervichnoeViragenie
{
};

} // Calc

int Calc::d(const string& s)
{
	cout << "DEBUG: " << s << '\n';
	return 1;
}

int Calc::error(const string& s, int line=0)
{
	no_of_errors++;
	cerr << "ERROR: " << s << " (line: " << line << ")\n";
	return 1;
}


double Calc::term(bool get)
{
	double left=prim(get);
	
	for (;;)
		switch (Tokenz::curr_tok)
    {
		case Tokenz::MUL:
			left *= prim(true);
			break;
		case Tokenz::DIV:
			if (double d=prim(true))
			{
				left /= d;
				break;
			}
			throw DivisionZero();
			//return error("delenie na 0", __LINE__);
		default:
			return left;
    }
}



double Calc::expr(bool get)
{
  double left=term(get);

  for (;;)
    switch(Tokenz::curr_tok)
    {
    case Tokenz::PLUS:
      left += term(true);
      break;
    case Tokenz::MINUS:
      left -= term(true);
      break;
    default:
      return left;
    }
}


Tokenz::Token_value Tokenz::get_token()
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
		case '*': case '/': case '+': case '-': case '=': case '(': case ')':
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
				cin.putback(ch);
				return curr_tok = NAME;
			}
			Calc::error("неправильная лексема", __LINE__);
			return curr_tok = PRINT;
	}
}



double Calc::prim(bool get)
{
  if (get) Tokenz::get_token();

  switch (Tokenz::curr_tok)
  {
  case Tokenz::NUMBER:
  {
    double v=Tokenz::number_value;
    Tokenz::get_token();
    return v;
  }
  case Tokenz::NAME:
  {
    double& v = table[Tokenz::string_value];
    if (Tokenz::get_token() == Tokenz::ASSIGN) v=expr(true);
    return v;
  }
  case Tokenz::MINUS:
    return -prim(true);
  case Tokenz::LP:
  {
    double e=expr(true);
    if (Tokenz::curr_tok != Tokenz::RP) throw GdeSkobka();// return error("ogidalas )", __LINE__);
    Tokenz::get_token();
    return e;
  }
  default:
    throw PervichnoeViragenie();
    //return error("ogidalos pervichnoe viragenie", __LINE__);
  }
}


int main(int argc, char* argv[])
{
  switch (argc)
	{
		case 1:
			Calc::input = &cin;
			break;
		case 2:
			Calc::input = new istringstream(argv[1]);
			break;
		default:
			Calc::error("to many parameters", __LINE__);
			return 1;
	}
	
	Calc::table["pi"] = 3.135523523523;
	Calc::table["e"] = 2.7234234;
	
	while (Calc::input)
	{
	  try
	  {
		Tokenz::get_token();
		if (Tokenz::curr_tok == Tokenz::END) break;
		if (Tokenz::curr_tok == Tokenz::PRINT) continue;
		cout << Calc::expr(false) << '\n';
	  }
	  catch(Calc::DivisionZero)
	  {
	    Calc::error("Division by zero");
	  }
	  catch(Calc::GdeSkobka)
	  {
	    Calc::error("GdeSkobka tvau mat' ?");
	  }
	  
	  catch(Calc::PervichnoeViragenie)
	  {
	    Calc::error("Ogidalasya pervichnoe =viragenie");
	  }

		
	}
	if (Calc::input != &cin) delete Calc::input;
	
	return Calc::no_of_errors;
}


			
			


