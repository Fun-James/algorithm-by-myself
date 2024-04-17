#include <iostream>
#include <cmath>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

class Rational {
    int up, down;

public:
    Rational(int x, int y){
        up = x;
        down = y;
    }
    Rational() {
        up = 1;
        down = 2;
    };
    Rational operator+(Rational a) {
        Rational after;
        int newdown = down * a.down;
        int newup = up * a.down + a.up * down;
        after.up = newup;
        after.down = newdown;
        return after.simplify();
    }
    Rational operator-(Rational b) {
        Rational after;
        int newdown = down * b.down;
        int newup = up * b.down - b.up * down;
        after.up = newup;
        after.down = newdown;
        return after.simplify();
    }
    friend Rational operator*(Rational a, Rational b);
    friend Rational operator/(Rational a, Rational b);

    Rational operator++(int) {//后++
        int a = up + down;
        Rational after(a,down);
        return after.simplify();
    }
    Rational simplify()
    {
        //找到up和down的最大公约数
        int max = GCD(up, down);
        int a =up/ max;
        int b=down/ max;
        if (a * b < 0)
        {
            b = abs(b);
            a = -abs(a);
        }
        Rational after(a, b);
        return after;
    }
   friend ostream& operator<<(ostream& out, Rational a)
    {
       if (a.down == 1)
       {
           out << a.up;
           return out;
       }
       out << a.up << "/" << a.down;
       return out;
    }
   Rational& operator=(const Rational& a)
    {
       up = a.down;
       down = a.up;
        return *this;
    }
};

Rational operator*(Rational a, Rational b)
{
    int newup = a.up * b.up;
    int newdown = a.down * b.down;
    Rational after(newup, newdown);
    return after.simplify();
}

Rational operator/(Rational a, Rational b)
{
    int newup = a.up * b.down;
    int newdown = b.up * a.down;
    Rational after(newup, newdown);
    return after.simplify();
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Rational m(a, b);
    Rational n(c, d);
    
    
    cout << m + n << endl;
    cout << m - n << endl;
    cout << m * n << endl;
    cout << m / n << endl;
    cout << m++ << " "<<n++<<endl;
    Rational R1;
    R1 = m;
    Rational R2;
    R2 = n;
    cout<<R1<<" "<<R2;
    
    return 0;
}


