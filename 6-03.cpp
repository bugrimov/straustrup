#include <iostream>
#include <map>

enum {PAIR_DELIM = '&', NAME_DELIM = '='};

std::multimap<std::string,double> data;
std::map<std::string,double> umap;
std::map<std::string,size_t> unique_count;

void store(std::string name, std::string value)
{
	data.insert(std::pair<std::string,double>(name, atof(value.c_str())));
}

void show()
{
	std::multimap<std::string,double>::iterator it;
	for (it=data.begin(); it!=data.end(); it++)
		std::cout << (*it).first << " => " << (*it).second << '\n';
}


double get_summ()
{
	double summ = 0;
	std::multimap<std::string,double>::iterator it;
	for (it=data.begin(); it!=data.end(); it++)
		summ += (*it).second;
	return summ; 
}

double get_average()
{
	return get_summ()/data.size();
}

void show_value_for_unique()
{
	std::cout << "= Summ for every element\n";
	std::multimap<std::string,double>::iterator it;
	std::multimap<std::string,double>::iterator it2;
	std::pair<std::multimap<std::string,double>::iterator,
	          std::multimap<std::string,double>::iterator> ret;
	for (it=data.begin(); it!=data.end(); it++)
	{
		umap[it->first] += (double)(*it).second;
		unique_count[it->first]++;	
	}
	for (std::map<std::string,double>::iterator u_it=umap.begin(); u_it!=umap.end(); u_it++)
		std::cout << (*u_it).first << " => " << (*u_it).second << '\n';
}

void show_average_for_unique()
{
	std::cout << "= Average values\n";
	for (std::map<std::string,double>::iterator u_it=umap.begin(); u_it!=umap.end(); u_it++)
		std::cout << (*u_it).first << " => " << (*u_it).second/unique_count[(*u_it).first] << '\n';
}


int main()
{
	char inp[256] = "qwer=123.35&asd=567.45&xv=7.009&qwer=1.5&xv=100.0&xv=1000.0";
	//std::cout << "Enter data: ";
	//std::cin.getline(inp, 256);
	
	std::string s_inp(inp);
	bool now_store_name = true;
	std::string name = "", value = "";
	for (int i=0; i<s_inp.size(); i++)
	{
		switch (s_inp[i])
		{
			case PAIR_DELIM:
				store(name, value);
				name = "";
				value = "";
				now_store_name = true;
				break;
			case NAME_DELIM:
				now_store_name = false;
				break;
			default:
				if (now_store_name)
					name += s_inp[i];
				else
					value += s_inp[i];
		}
	}
	store(name, value);
	show();
	std::cout << "Summ: " << get_summ() << "\n";
	std::cout << "Avg: " << get_average() << "\n";
	show_value_for_unique();
	show_average_for_unique();
}



				

