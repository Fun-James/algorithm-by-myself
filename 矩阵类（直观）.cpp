#include <iostream>

using namespace std;
class Matrix {
	int m[3][3];

public:
	void setMatrix()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> m[i][j];
			}
		}
	}
	Matrix operator +(Matrix& other)
	{
		Matrix res;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				res.m[i][j] = m[i][j] + other.m[i][j];
			}
		}
		return res;
	}
	Matrix operator -(Matrix& other)
	{
		Matrix res;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				res.m[i][j] = m[i][j] - other.m[i][j];
			}
		}
		return res;
	}
	Matrix operator *(Matrix& other)
	{
		Matrix result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int sum = 0;
				for (int w = 0; w < 3; w++)
				{
					sum += m[i][w] * other.m[w][j];
				}
				result.m[i][j] = sum;
			}
		}
		return result;
	}
	friend ostream& operator<<(ostream& out, Matrix ma);
};

ostream& operator<<(ostream& out,Matrix ma)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			out << ma.m[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

int main() {
	Matrix a, b;
	a.setMatrix();
	b.setMatrix();
	cout << a + b;
	cout << a - b;
	cout << a * b;


	return 0;
}