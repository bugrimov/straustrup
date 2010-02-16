#include <string>
#include <stdio.h>


namespace Chrono
{
	
	class Date
	{
		public:
			enum Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
			
			class BadDate {};
			
			Date(int dd=0, Month mm=0, int yy=0);
			
			int day() const;
			Month month() const;
			int year() const;
			
			std::string string_rep() const;
			void char_rep(char s[]) const;
			static Date* default_date;
			static int t;
		
		 void static set_default(int dd, Month mm, int yy)
			{
				//Date::
				//Chrono::Date::t=0;
				default_date = new Date(dd, mm, yy);
			}
			
			Date& add_year(int n);
			Date& add_month(int n);
			Date& add_day(int n);
			
			//	inline bool operator== (Date a, Date b);


			
		private:
			int d, m, y;
			
			mutable bool cache_valid;
			mutable std::string cache;
			void compute_cache_value();
	};
	
	bool leapyear(int year)
	{
		if ((year%4==0) && (year&100 != 0) || (year%400==0))
			return true;
		else
			return false;
	}

	/*
	static void Date::set_default(int dd, Month mm, int yy)
	{
		default_date = new Date(dd, mm, yy);
	}
	 */
	
	Date::Date(int dd, Month mm, int yy)
	{
		/*
		if (yy == 0) yy = Date::default_date->year();
		if (mm == 0) mm = Date::default_date->month();
		if (dd == 0) dd = Date::default_date->day();
		*/
		int max;
		switch (mm)
		{
			case feb:
				max = 28+leapyear(yy);
				break;
			case apr: case jun: case sep: case nov:
				max = 30;
				break;
			case jan: case mar: case may: case jul: case aug: case oct: case dec:
				max = 31;
				break;
			default:
				throw BadDate();
		}
		if (dd < 1 || max<dd) throw BadDate();
		
		y = yy;
		m = mm;
		d = dd;
	}
	
	inline int Date::day() const
	{
		return d;
	}
	
	inline Date::Month Date::month() const
	{
		return Month(m);
	}
	
	inline int Date::year() const
	{
		return y;
	}
	
	Date& Date::add_month(int n)
	{
		if (n==0) return *this;
		
		if (n>0)
		{
			int delta_y = n/12;
			int mm = m+n%12;
			if (12<mm)
			{
				delta_y++;
				mm -= 12;
			}
			
			y += delta_y;
			m = Month(mm);
			return *this;
		}
		return *this;
	}
	
	inline bool operator== (Date a, Date b)
	{
		return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
	}
	
	std::string Date::string_rep() const
	{
		
		char s[50];
		std::sprintf(s, "%d/%d/%d", d, m, y);
		return (std::string)s;
	}
	Date* Date::default_date = new Date(1, Chrono::Date::Month(1), 1970);
	
	
}; // namespace chrono
//int Chrono::Date::t = 5;
//void Chrono::Date::set_default(1, Chrono::Date::Month(1), 1970);
//Chrono::

using Chrono::Date;
int main()
{

	Date::set_default(1, Date::Month(1), 1970);

	1;
	//Chrono::Date::default_date = new Chrono::Date::Date(1, Chrono::Date::Month(1), 1970);
	//Chrono::Date::t = 5;
	
}
