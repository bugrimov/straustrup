#include <iostream>
#include <string>
#include <cctype>
#include <sstream>


class Expr
{
	enum Token_value
	{
		NAME, OTHER, END, SPACE,
		END_LINE='\n', NUMBER,
		PLUS='+', MINUS='-', MUL='*', DIV='/',
		PRINT=';', ASSIGN='=', LP = '(', RP=')',
	};
	
	char* expr_str; //place to store source expression
	std::string string_value;
	double number_value; //result value may be here
	std::istream* input;
	
	Token_value curr_tok;
	int no_of_errors;
	
	double prim(bool get);
	double Expr::term(bool get);
	int error(const std::string& s, int);
	double expr(bool get);
	Token_value get_token();
	
	void assert1(double a, double b, double c);
	double plus(double a, double b);
	double minus(double a, double b);
	double multiply(double a, double b);
	double divide(double a, double b);
	
public:
		Expr (char*);
	~Expr()
	{
		delete input;
		delete expr_str;
	}
		double eval();
		void print();
	
	struct DivisionZero
	{
	};
	
	struct GdeSkobka
	{
	};
	
	struct PervichnoeViragenie
	{
	};
	
	struct Overhead
	{
	};
};

void Expr::print()
{
	std::cout << "Value is: " << number_value << "\n";
}

double Expr::eval()
{
	double res = expr(true);
	number_value = res;
	return res;
}

void Expr::assert1(double a, double b, double c)
{
	//if (c == a || c == b || c == std::numeric_limits<double>::infinity() || c == -std::numeric_limits<double>::infinity() )
	//	throw Overhead();
}

double Expr::plus(double a, double b)
{
	//std::cout << a << "+" << b << '=' << a+b;
	double c = a+b;
	assert1(a, b, c);
	return (a+b);
}

double Expr::minus(double a, double b)
{
	//std::cout << a << "-" << b << '=' << a-b;
	double c = a-b;
	assert1(a, b, c);
	return (a-b);
}

double Expr::multiply(double a, double b)
{
	//std::cout << a << "-" << b << '=' << a-b;
	double c = a*b;
	assert1(a, b, c);
	return c;
}

double Expr::divide(double a, double b)
{
	if (b == 0) throw DivisionZero();
	//std::cout << a << "-" << b << '=' << a-b;
	double c = a/b;
	assert1(a, b, c);
	return c;
}

Expr::Expr(char* cs)
{
	curr_tok = PRINT;

	expr_str = new char(100);
	char* to = expr_str;
	while(*cs)
	{
		*to = *cs;
		to++;
		cs++;
	}
	input = new std::istringstream(expr_str);
	std::cout << "Constructor: " << expr_str << "\n";
}



int Expr::error(const std::string& s, int line=0)
{
	no_of_errors++;
	std::cerr << "ERROR: " << s;
	if (line != 0 )
		std::cout << " (line: " << line << ")";
	std::cout << "\n";
	return 1;
}

double Expr::term(bool get)
{
	double left=prim(get);
	
	for (;;)
		switch (curr_tok)
    {
		case MUL:
			left = multiply(left, prim(true));
			//left *= prim(true);
			break;
		case DIV:
			if (double d=prim(true))
			{
				left = divide(left, d);
				//left /= d;
				break;
			}
			throw DivisionZero();
			//return error("delenie na 0", __LINE__);
		default:
			return left;
    }
}

double Expr::expr(bool get)
{
	double left=term(get);
	
	for (;;)
		switch(curr_tok)
    {
		case PLUS:
			left = plus(left, term(true));	
			//left += term(true);
			break;
		case MINUS:
			left = minus(left, term(true));				
			//left -= term(true);
			break;
		default:
			return left;
    }
}


Expr::Token_value Expr::get_token()
{
	char ch;
	
	do
	{
		if (!input->get(ch)) return curr_tok=END;
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
			input->putback(ch);
			*input >> number_value;
			return curr_tok=NUMBER;
		default:
			if (isalpha(ch))
			{
				string_value=ch;
				while (input->get(ch) && isalnum(ch)) string_value.push_back(ch);
				input->putback(ch);
				return curr_tok = NAME;
			}
			std::cout << ch << "<-";
			Expr::error("неправильная лексема", __LINE__);
			return curr_tok = PRINT;
	}
}


double Expr::prim(bool get)
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
		/*
		case NAME:
		{
			double& v = table[string_value];
			if (get_token() == ASSIGN) v=expr(true);
			return v;
		}
		*/
		case MINUS:
			return -prim(true);
		case LP:
		{
			double e=expr(true);
			if (curr_tok != RP) throw GdeSkobka();// return error("ogidalas )", __LINE__);
			get_token();
			return e;
		}
		default:
			std::cout << string_value << " " <<  curr_tok << "\n";
			throw PervichnoeViragenie();
			//return error("ogidalos pervichnoe viragenie", __LINE__);
	}
}

int main()
{
	Expr x("2+2+2");
	x.eval();
	x.print();
	Expr y("(5*5+5-5)/3+1");
	y.eval();
	y.print();
}


