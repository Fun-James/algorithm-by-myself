#include <iostream>

using namespace std;
template <class T> void Print(T* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(p + i) << " ";
	}
	cout << endl;
}
template <class T> void Gtlever(T* p, int n, T lever)
{
	int count = 0;
	T after[1000];
	for (int i = 0; i < n; i++)
	{
		if (*(p + i) > lever)
		{
			after[count++] = *(p + i);
		}
	}
	Print(after, count);
	
}

int main()
{
	string op;
	cin >> op;
	if (op == "int")
	{
		int length;
		int n;
		cin >> length >> n;
		int a[1000];
		for (int i = 0; i < length; i++)
		{
			cin >> a[i];
		}
		int lever;
		cin >> lever;
		Gtlever<int>(a, n, lever);
		

	}
	else if (op == "float")
	{
		int length;
		int n;
		cin >> length >> n;
		float a[1000];
		for (int i = 0; i < length; i++)
		{
			cin >> a[i];
		}
		float lever;
		cin >> lever;
		Gtlever<float>(a, n, lever);
		

	}
	else if (op == "char")
	{
		int length;
		int n;
		cin >> length >> n;
		char a[1000];
		for (int i = 0; i < length; i++)
		{
			cin >> a[i];
		}
		char lever;
		cin >> lever;
		Gtlever<char>(a, n, lever);
	
	}

	
	return 0;
}
