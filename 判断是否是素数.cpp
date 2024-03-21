#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

bool sushu(int n)
{
	if (n <= 1)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
