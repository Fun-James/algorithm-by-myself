#include <iostream>
using namespace std;

int main()
{	
	int n;
	cin>>n;
	char map[17]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	string re16="";
	while(n!=0)
	{
		re16+=map[n%16];
		n/=16;
	}
	string _16="";
	for(int i=re16.length()-1;i>=0;i--)
	{
		_16+=re16[i];
	}
	cout<<_16;
}
