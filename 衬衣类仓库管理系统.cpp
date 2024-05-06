#include <iostream>
#include <string>
using namespace std;

class Base {
	double price;
	string place;
public:
	void setBase(double pr, string pl)
	{
		price = pr;
		place = pl;
	}
	Base() {
		price = 0;
		place = "";
	}
	double getPrice() {
		return price;
	}
	string getPlace()
	{
		return place;
	}

};

class Shirt :public Base {
	string material;
	int number;
public:
	void setShirt(int n, double pr, string pl, string m)
	{
		material = m;
		number = n;
		setBase(pr, pl);
	}
	Shirt() :Base() {
		material = "";
		number = 0;
	}
	int getNum()
	{
		return number;
	}
	string getMaterial()
	{
		return material;
	}
	void numIncrease(int n)
	{
		number += n;
	}
	void numDecrease(int n)
	{
		number -= n;
	}
};
int main()
{
	string op;
	int count = 0;//种类的数量
	Shirt t[20];
	while (1)
	{
		cin >> op;
		if (op == "in")
		{
			int n;
			cin >> n;
			double price;
			string place;
			string material;
			cin >> price >> place >> material;
			if (n <= 0)
			{
				cout << "wrong"<<endl;
				continue;
			}
			bool find = false;
			for (int i = 0; i < count; i++)
			{
				if (t[i].getPlace() == place && t[i].getPrice() == price && t[i].getMaterial() == material)
				{
					t[i].numIncrease(n);
					find = true;
					break;
				}
			}
			if (find == true)
			{
				continue;
			}
			else
			{
				t[count++].setShirt(n, price, place, material);
			}
		}
		if (op == "out")
		{
			int n;
			cin >> n;
			double price;
			string place;
			string material;
			cin >> price >> place >> material;
			if (n <= 0)
			{
				cout << "wrong"<<endl;
				continue;
			}
			bool find = false;
			for (int i = 0; i < count; i++)
			{
				if (t[i].getPlace() == place && t[i].getPrice() == price && t[i].getMaterial() == material&&t[i].getNum()>0)
				{
					if (t[i].getNum() < n)
					{
						int remaining = t[i].getNum();
						t[i].numDecrease(t[i].getNum());
						cout << "out " << remaining<<endl;
					}
					else
					{
						t[i].numDecrease(n);
						cout << "next"<<endl;
					}

					find = true;
					break;
				}
			}
			if (find == true)
			{
				continue;
			}
			else
			{
				cout << "wrong"<<endl;
			}

		}
		if (op == "num")
		{
			double price;
			string place;
			string material;
			cin >> price >> place >> material;
			for (int i = 0; i < count; i++)
			{
				if (t[i].getPlace() == place && t[i].getPrice() == price && t[i].getMaterial() == material)
				{
					cout << t[i].getNum()<<endl;
					break;
				}
			}

		}
		if (op == "price")
		{
			double sum = 0;
			for (int i = 0; i < count; i++)
			{
				sum += t[i].getPrice() * t[i].getNum();
			}
			cout << sum;
			break;
		}
	}
	return 0;
}