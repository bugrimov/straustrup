
struct SS
{
	int m;
}

int main()
{
	int* p;
	int i;
	int a;
	*(p++);
	*(--p);
	((++a)--);
	(int*)(p->m);
	(*p).m;
	(*a)[i];
}


