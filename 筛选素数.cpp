#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const int n = 1000;
    int i = 2, j, count = 0;
    int sieve[n + 1];
    for (j = 1; j < n + 1; j++)
        sieve[j] = j;
    while (i < n + 1)
    {
        cout << setw(5) << sieve[i];
        count++;
        if (count % 15 == 0)
            cout << endl;
        for (j = i; j < n + 1; j += i)
            sieve[j] = 0;
        while (sieve[i] == 0)
            i++;
    }
    return 0;

}