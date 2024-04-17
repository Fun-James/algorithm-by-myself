#include <iostream>
#include <string>
using namespace std;
class Clock {
	int H, M, S;
public:
	void SetTime(int h, int m, int s)
	{
		H = h;
		M = m;
		S = s;
	}
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
};
class AlarmClock :public Clock
{
	int AH, AM;
public:
	void SetAlarm(int ah, int am)
	{
		AH = ah;
		AM = am;
	}
	void ShowAlarm()
	{
		cout << AH << ":" << AM << endl;
	}
};
int main()
{
	AlarmClock A;
	int n;
	cin >> n;
	string functionName;
	while (n--) {
		cin >> functionName;
		if (functionName == "SetTime") {
			int a, b, c;
			cin >> a >> b >> c;
			A.SetTime(a, b, c);
		}
		else if (functionName == "ShowTime") {
			A.ShowTime();
		}
		else if (functionName == "SetAlarm") {
			int a, b;
			cin >> a >> b;
			A.SetAlarm(a, b);
		}
		else if (functionName == "ShowAlarm") {
			A.ShowAlarm();
		}
		else {
			cout << "没有这个函数!" << endl;
		}
	}
	return 0;
}