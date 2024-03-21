#include <iostream>

using namespace std;
int main() 
{   
    int y, m;
    cin >> y >> m;
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
    {//是闰年
        switch (m)
        {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            cout << "31";
            break;
        case 2:
            cout << "29";
            break;
        default:
            cout << "30";
        }

    }
    else
    {//不是闰年
        switch (m)
        {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            cout << "31";
            break;
        case 2:
            cout << "28";
            break;
        default:
            cout << "30";
        }


    }
    return 0;
}