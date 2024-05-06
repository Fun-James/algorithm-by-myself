#include <iostream>
#include <string>
using namespace std;

template <typename T> 
class Example {
	T* content;
	int num;
public:
	Example() {
		content = nullptr;
		num = 0;
	}
	~Example() {
		delete[]content;
	}
	void getContent(int n)
	{
		num = n;
		content = new T[n];
		for (int i = 0; i < n; i++)
		{
			cin >> content[i];
		}
	}
	void sort()
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = num - 1; j > i; j--)
			{
				if (content[j] < content[j - 1])
				{
					T temp = content[j];
					content[j] = content[j - 1];
					content[j - 1] = temp;
				}
			}
		}
	}
	void print()
	{
		for (int i = 0; i < num; i++)
		{
			cout << content[i]<<" ";
		}
		cout << endl;
	}

};

int main()
{
	int n;
	cin >> n;
	Example<int> a;
	a.getContent(n);
	a.sort();
	a.print();
	
	int m;
	cin >> m;
	Example<char> b;
	b.getContent(m);
	b.sort();
	b.print();

	int x;
	cin >> x;
	Example<string> c;
	c.getContent(x);
	c.sort();
	c.print();
	
	return 0;
}
