#include <iostream>

using namespace std;
int main() 
{   
    int n,b,sum=0,count=0;
    cin >> n;
    for (int i = 0;n>0; i++)
    {
        b = n % 2;
        n /= 2;
        sum = 10 * sum + b;
        count++;
    }
    for (int i = 0; i <count; i++)
    {
        cout << sum % 10;
        sum /= 10;
    }
    return 0;
}

