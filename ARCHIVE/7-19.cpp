#include <iostream>

using namespace std;

/*
struct struct_date
{
    char day;
    char month;
    short year;
};
 
int what_day(const struct struct_date * const date)
{
    int a = (14 - date->month) / 12;
    int y = date->year - a;
    int m = date->month + 12 * a - 2;
    return (7000 + (date->day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
}
*/


struct Date
{
   int day;
   int month;
   int year;
};

bool is_leap_year(int year)
{
  return ((year%4==0) && (year%100 != 0)) || (year%400==0);
}

void add_month(Date& d)
{
  if (d.month >= 12)
  {
    d.year++;
    d.month = 1;
  }
  else
    d.month++;
}


void add_day(Date& d)
{
  int days_in_month[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (is_leap_year(d.year))
    days_in_month[1] = 29;
  else
    days_in_month[1] = 28;

  if (d.day >= days_in_month[d.month-1])
  {
    d.day = 1;
    add_month(d);
  }
  else
    d.day++;
}


void print(const Date& d)
{
  cout << d.day << '.' << d.month << '.' << d.year << '\n';
}

int get_day_of_week(const Date& d)
{
  Date d1;
  d1.day = 1;
  d1.month = 1;
  d1.year = 1970;
  int week_d = 3; // 4etverg

  while( !(d1.day == d.day && d1.month == d.month && d1.year == d.year))
  {
    add_day(d1);
    //print(d1);
    if(week_d >= 6)
      week_d = 0;
    else
      week_d++;
  }
  return week_d;
}

void print_week_day(const Date& d)
{
  cout << "Day of week: " << get_day_of_week(d) << '\n';
}

void print_date_to_ponedelnik(const Date& d)
{
  Date t;
  t.day = d.day;
  t.month = d.month;
  t.year = d.year;
  while(0 != get_day_of_week(t))
  {
    add_day(t);
  }
  cout << "Ponedelnik: ";
  print(t);
}

int main()
{
  Date t;
  t.day = 29;
  t.month = 9;
  t.year = 2010;
  print(t);
  add_day(t);
  print(t);
  add_day(t);
  print(t);
  add_day(t);
  print(t);
  add_day(t);
  print(t);
  print_week_day(t);

  add_month(t);
  print(t);
  add_month(t);
  print(t);
  add_month(t);
  print(t);
  add_month(t);
  print(t);
  print_week_day(t);
  print_date_to_ponedelnik(t);

}


