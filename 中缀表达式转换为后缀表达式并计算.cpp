#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;
class MyCalcu2 {
public:
    string expression; 
    MyCalcu2(string exp)
    {
        expression = exp;
    }
    void process(); 
};
int getPriority(string ch)
{
    int res = 0;
    if (ch == "+" || ch == "-")
    {
        res = 1;
    }
    if (ch == "*" || ch == "/")
    {
        res = 2;
    }
    return res;
}


bool isNumber(string s)
{
    int sign = 0;//符号数
    int dot = 0;//小数点数目
    int num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '+' || ch == '-')
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
    MyCalcu2 cal(s1);

    cal.process();

    return 0;
}

void MyCalcu2::process()
{
    
    vector<string> vec1;

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
                vec1.push_back(temp);
                temp = "";
            }
        }
    }//完成储存中缀表达式

    //中缀表达式转化为后缀表达式
    vector<string> vec;
    stack<string> sign;
    for (int i = 0; i < vec1.size();i++)
    {
        if (vec1[i] >= "0" && vec1[i] <= "9")
        {
            vec.push_back(vec1[i]);//是数就直接放入后缀表达式的容器中
        }
        else if (vec1[i] == "(")
        {
            sign.push(vec1[i]);
        }
        else if (vec1[i] == ")")
        {
            while(sign.empty()==false&&sign.top() != "(")
            {
                vec.push_back(sign.top());
                sign.pop();
            }
            sign.pop();

        }
        else if (vec1[i] == "+" || vec1[i] == "-" || vec1[i] == "*" || vec1[i] == "/")
        {
            if (sign.empty() == true || getPriority(vec1[i]) > getPriority(sign.top()))//top小，先入栈
            {
                sign.push(vec1[i]);
                continue;
            }
            if (getPriority(vec1[i]) <= getPriority(sign.top()))
            {
                while (sign.empty()==false && getPriority(sign.top()) >= getPriority(vec1[i]))//top大或等于，的全部pop
                {
                    vec.push_back(sign.top());
                    sign.pop();
                }
            }
            sign.push(vec1[i]);
        }
    }
    while (sign.empty()==false)
    {
        vec.push_back(sign.top());
        sign.pop();
    }


    stack<double> stack;
    for (int i = 0; i < vec.size(); i++)//开始用后缀表达式计算
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
                a = b - a;
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