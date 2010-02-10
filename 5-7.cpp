#include <iostream>

struct Months {
	char* name;
	short days;
};

int main()
{
	char* month[] = {"Jan", "Feb", "Mar","Apr","May","June","July","August",
	"September", "October","November","December"};
	short days_in_month[] = {24, 35,67,24,51,34,56,22,11,54,67,63};
	const short MONTHS = 12;
	for (int i = 0; i<MONTHS; i++)
		std::cout << month[i] << ' ' << days_in_month[i] << std::endl;
	
	Months m[] = {
		{"Jan", 45},
		{"Feb",55}
	};
	for(int i=0; i<=1; i++)
		std::cout << m[i].name << ' ' << m[i].days << std::endl;
}


