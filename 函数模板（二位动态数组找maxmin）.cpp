#include <iostream>
#include <string>
using namespace std;

template<class Type>
void maxMin(Type** A, int m, int n)
{
	Type max = A[0][0];
	Type min = A[0][0];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] > max)
			{
				max = A[i][j];
			}
			if (A[i][j] < min)
			{
				min = A[i][j];
			}
		
		}
	}
	cout << max << " " << min;
	return;
}



int main()
{
	string a;
	cin >> a;
	int m, n;
	cin >> m >> n;
	if (a == "int")
	{
		int **matrix=new int*[m];
		for (int i = 0; i < m; i++)
		{
			matrix[i] = new int[n];
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
			}
		}
		maxMin(matrix, m, n);
		
	}
	else if (a == "char")
	{
		char** matrix = new char* [m];
		for (int i = 0; i < m; i++)
		{
			matrix[i] = new char[n];
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
			}
		}
		maxMin(matrix, m, n);
	}

	return 0;
}