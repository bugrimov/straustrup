

void f(char*, int&);
typedef void (*fp)(char*, int&);
void f2(fp);
fp f3();

fp f4(fp f_example)
{
	return f_example;
}

int main()
{
	
}
