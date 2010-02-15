#include <iostream>

//int n, a[n];

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void qs(int* s_arr, int first, int last)
{
	int i=first, j=last, x=s_arr[(first+last) / 2];
	
	do {
		while (s_arr[i] < x) i++;
		while (s_arr[j] > x) j--;
		
		if (i <= j) 
		{
			if (i < j) swap(s_arr[i], s_arr[j]);
			i++;
			j--;
		}
	}
	while (i <= j);
	
	if (i < last)
		qs(s_arr, i, last);
	if (first < j)
		qs(s_arr, first, j);
}


int main()
{
	int arr[] = {5,3,77,2,6,8,3,4,7,36,4,12,2,4,56};
	int a_size = sizeof(arr)/sizeof(int);
	std::cout << a_size << "!\n";
	qs(arr, 0, a_size-1);
	std::cout << a_size << "!\n";
	for (int i=0; i<a_size; i++)
		std::cout << i  << ": " << arr[i] << ' ';
	
}

