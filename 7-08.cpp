#include <iostream>

using namespace std;

enum {
	ROWS = 5,
	COLS = 3,
};

//# 0  1  2
//----------
//  0  1  2  |0
//  3  4  5  |1
//  6  7  8  |2
//  9 10 11  |3
// 12 13 14  |4

/*
  0  1  2  3  4
  5  6  7  8  9
 10 11 12 13 14
*/

void transpone(const int* a, int rows, int cols, int* dest)
{
	for(int i=0; i<rows; i++)
		for( int j=0; j<cols; j++)
			//cout << (i + j*rows) << '=' << (i*cols + j) << '\n';
			*(dest + i + j*rows) = *(a + i*cols + j);

}

void print_arr(const int* a, int rows, int cols)
{
	for(int i=0; i<rows; i++)
	{
		for( int j=0; j<cols; j++)
			//cout << a[i][j] << ' ';
			cout << *(a + i*cols + j) << ' ';
		cout << '\n';
	}
}

int main()
{
	
	int arr[ROWS][COLS] = {
		{11, 12, 13},
		{43, 44, 45},
		{51, 52, 53},
		{36, 37, 38},
		{77, 78, 79}
	};
	print_arr(&arr[0][0], ROWS, COLS);
	int a2[COLS][ROWS];
	transpone(&arr[0][0], ROWS, COLS, &a2[0][0]);
	print_arr(&a2[0][0], COLS, ROWS);
}



