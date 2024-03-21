#include<iostream>

using namespace std;

const int maxcard = 20;

class Set {
	int elems[maxcard];
	int card;//数目
public:
	Set(void) {
		card = 0;
	}
	void print()
	{
		cout << "{";
		for (int i = 0; i < card; i++)
		{
			cout << elems[i];
			if (i != card - 1)
			{
				cout << ", ";
			}
		}
		cout << "}"<<endl;
	}

	friend bool operator ==(Set s1, Set s2);
	friend bool operator !=(Set, Set);
	friend Set operator +(Set, int);
	friend Set operator +(Set, Set);
	friend Set operator -(Set, int);
	friend Set operator *(Set, Set);
	friend bool operator<(Set, Set);
	friend bool operator<=(Set, Set);
};

bool operator<=(Set a, Set b)
{
	if (a < b)
	{
		return true;
	}
	if (a == b)
	{
		return true;
	}
	return false;
}
bool operator<(Set a, Set b)
{
	for (int i = 0; i < a.card; i++)
	{
		bool have = false;
		for (int j = 0; j < b.card; j++)
		{
			if (a.elems[i] == b.elems[j])
			{
				have = true;
			}
		}
		if (have == false)
		{
			return false;
		}
		
	}
	if (a != b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(Set a, Set b)
{
	if (a == b)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool operator ==(Set s1, Set s2)
{
	if (s1.card != s2.card)
	{
		return false;
	}
	for (int i = 0; i < s1.card; i++)
	{
		if (s1.elems[i] != s2.elems[i])
		{
			return false;
		}
	}
	return true;
}

Set operator +(Set a, Set b)
{
	Set temp=b;
	for (int i = 0; i < a.card; i++)
	{
		bool have = false;
		for (int j = 0; j < b.card; j++)
		{
			if (a.elems[i] == b.elems[j])
			{
				have = true;
			}
		}
		if (have == false)
		{
			temp.elems[temp.card++] = a.elems[i];
		}
	}
	for (int i = 0; i < temp.card; i++)
	{
		for (int j = temp.card - 1; j > i; j--)
		{
			if (temp.elems[j] < temp.elems[j - 1])
			{
				int tempn = temp.elems[j];
				temp.elems[j] = temp.elems[j - 1];
				temp.elems[j - 1] = tempn;
			}
		}
	}
	return temp;
}
Set operator +(Set a, int i)
{
	a.elems[a.card++] = i;
	return a;
}
Set operator -(Set a, int b)
{
	for (int i = 0; i < a.card; i++)
	{
		if (b == a.elems[i])
		{
			for (int j = i; j < a.card-1; j++)
			{
				a.elems[j] = a.elems[j + 1];
			}
			a.card--;
		}
	}
	return a;
	
}
Set operator *(Set a, Set b)
{
	Set temp;
	for (int i = 0; i < a.card; i++)
	{
		bool have = false;
		for (int j = 0; j < b.card; j++)
		{
			if (a.elems[i] == b.elems[j])
			{
				have = true;
			}
		}
		if (have == true)
		{
			temp.elems[temp.card++] = a.elems[i];
		}
	}
	return temp;
}
int main() {
	Set s, s1, s2, s3, s4;
	for (int i = 0; i < 10; i++) {
		s = s + i;
		s1 = s1 + 2 * i;
		s2 = s2 + 3 * i;
	}
	cout << "s="; s.print();
	cout << "s1="; s1.print();
	cout << "s2="; s2.print();
	for (int i = 0; i < 5; i++) {
		s = s - i;
		s1 = s1 - i;
		s2 = s2 - i;
	}
	cout << "After RmvElem(0->4), s=";
	s.print();
	cout << "After RmvElem(0->4), s1=";
	s1.print();
	cout << "After RmvElem(0->4), s2=";
	s2.print();
	s3 = s * s1;
	s4 = s + s2;
	cout << "s3=s*s1="; s3.print();
	cout << "s4=s+s2="; s4.print();
	if (s3 == s4)
		cout << "SET s3=s4 " << endl;
	else
		cout << "SET s3 != s4 " << endl;
	if (s3 == s3)
		cout << "SET s3=s3 " << endl;
	else
		cout << "SET s3 != s3 " << endl;

	if (s4 <= s3)
		cout << "SET s3 contains s4 " << endl;
	else
		cout << "SET s3 do not contains s4 " << endl;

	if (s2 <= s4)
		cout << "SET s4 contains s2 " << endl;
	else
		cout << "SET s4 do not contains s2 " << endl;
	
	return 0;
}

