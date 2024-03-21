#include <iostream>
using namespace std;
int main() 
{   
    int n[5], max, second;
    for (int i = 0; i < 5; i++)
        cin >> n[i];
   if (n[0] >= n[1])
        {
            max = n[0];
            second = n[1];
        }
        else
        {
            max = n[1];
            second = n[0];
        }
    for (int i = 2; i < 5; i++)
    {
        if (n[i]>max)
        {
            second = max;
            max = n[i];
        }
        else if(n[i]<=max&&n[i]>second)
        {
            second = n[i];
        }
        else
        {
            max = max;
            second = second;
        }
    }
    cout << second;
    return 0;
}