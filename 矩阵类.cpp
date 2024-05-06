#include <iostream>

using namespace std;
class matrix {

public:

	int r, c; //r行c列的矩阵
	int** mem;//矩阵数据

	matrix(int a, int b)
	{
		r = a;
		c = b;
		mem = new int* [r];
		for (int i = 0; i < r; i++)
		{
			mem[i] = new int[c];
		}
	}//二参构造函数,分配a行b列的mem动态数组存放数据
	~matrix()
	{
		for (int i = 0; i < r; i++)
		{
			delete[] mem[i];
		}
		delete[]mem;

	}//析构函数,释放mem动态数组

	matrix operator+(matrix& m);//矩阵加
	matrix operator-(matrix& m);//矩阵减
	matrix operator*(matrix& m);//矩阵乘
	matrix operator~();//矩阵转置
	void display()
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << mem[i][j]<<" ";
			}
			cout << endl;
		}
		cout << endl;
	}//输出矩阵
};

int main()
{
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	matrix x(r1, c1);
	matrix y(r2, c2);
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			cin >> x.mem[i][j];
		}
	}

	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			cin >> y.mem[i][j];
		}
	}
	if (r1 == r2 && c1 == c2)
	{
		(x + y).display();
		(x - y).display();
	}
	else
	{
		cout << "err" << endl << "err"<<endl;
	}

	if (c1 == r2)
	{
		(x * y).display();
	}
	else
	{
		cout << "err"<<endl;
	}
	(~x).display();

	return 0;
}

matrix matrix::operator+(matrix& m)
{
	matrix result(r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			result.mem[i][j] = mem[i][j] + m.mem[i][j];
		}
	}
	return result;
}

matrix matrix:: operator-(matrix& m)
{
	matrix result(r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			result.mem[i][j] = mem[i][j] - m.mem[i][j];
		}
	}
	return result;
}

matrix matrix:: operator*(matrix& m)
{
	matrix result(r,m.c);
	for (int i = 0;i < r; i++)
	{
		for (int j = 0; j < m.c; j++)
		{
			int sum = 0;
			for (int w=0;w<c;w++)
			{
				sum += mem[i][w] * m.mem[w][j];
			}
			result.mem[i][j] = sum;
		}
	}
	return result;
}

matrix matrix::operator~()
{
	matrix result(c, r);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			result.mem[j][i] = mem[i][j];
		}
	}
	return result;
}