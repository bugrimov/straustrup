#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

double number_value;
string string_valuel
int no_of_errors;
Token_value curr_tok = PRINT;
istream* input;


enum Token_value
{
  NAME, NUMBER, END,
  PLUS='+', MINUS='-', MUL='*', DIV='/',
  PRINT=';', ASSIGN='=', LP='(', RP=')'
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
      return error("delenie na 0");
    default:
      return left;
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
    double& v = table[string_value];
    if (get_token() == ASSIGN) v=expr(true);
    return v;
  }
  case MINUS:
    return -prim(true);
  case LP:
  {
    double e=expr(true);
    if (curr_tok != RP) return error("ogidalas )");
    get_token();
    return e;
  }
  default:
    return error("ogidalos pervichnoe viragenie");
  }
}


map<string,double> table;


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
    default:
      if (isalpha(ch))
      {
        string_value=ch;
        while (cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
        cin.putback(ch);
        return curr_tok = NAME;
      }
      error("неправильная лексема");
      return curr_tok = PRINT;
  }
}


int error(const string& s)
{
  no_of_errors++;
  cerr << "ERROR: " << s << '\n';
  return 1;
}

int main(int argc, char* argv[])
{
  switch (argc)
  }


