#include <iostream>
#include<string>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;
class MyCalcu1 {
public:
    string expression; //后缀表达式
    MyCalcu1(string exp)
    {
        expression = exp;
    }
    void process(); // 内部计算并输出后缀表达式的计算结果
};

bool isNumber(string s)
{
    int sign = 0;//符号数
    int dot = 0;//小数点数目
    int num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '+' || ch == '-' )
        {
            if (i != 0)
            {
                return false;
            }
            sign++;

        }
        else if (ch == '.')
        {
            dot++;
        }
        else if (ch >= '0' && ch <= '9')
        {
            num++;
        }
        else
        {
            return false;
        }
    }
    if (dot > 1)
    {
        return false;
    }
    if (num == 0)
    {
        return false;
    }

    return true;
}


int main()
{
    string s1;
    getline(cin, s1);
    MyCalcu1 cal(s1);

    cal.process();

	return 0;
}

void MyCalcu1::process()
{
    stack<double> stack;
    vector<string> vec;
    
    string temp = "";
    expression += " ";
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] != ' ')
        {
            temp += expression[i];
        }
        else
        {
            if (temp != "")
            {
                vec.push_back(temp);
                temp = "";
            }
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        string str = vec[i];
        if (isNumber(str) == true)//是数
        {
            stack.push(stod(str));
        }
        else if (str == "+" || str == "-" || str == "*" || str == "/")//是运算符
        {
            if (stack.size() < 2)
            {
                cout << "err" << endl;
                return;
            }
            double a = stack.top();//右数
            stack.pop();
            double b = stack.top();//左数
            stack.pop();

            if (str == "+")
            {
                a += b;
            }
            else if (str == "-")
            {
                a =b-a;
            }
            else if (str == "*")
            {
                a *= b;
            }
            else if (str == "/")
            {
                if (a == 0)
                {
                    cout << "err" << endl;
                    return;
                }
                a = b / a;
            }
            stack.push(a);
        }
        else//出现其他内容
        {
            cout << "err" << endl;
            return;
        }
    }
    if (stack.size() == 1)
    {
        cout << stack.top() << endl;
        return;
    }
    else
    {
        cout << "err" << endl;
        return;
    }



}