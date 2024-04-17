#include <iostream>
using namespace std;
int days_in_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool isLeapYear(int n)
{
	if (n % 400 == 0)
	{
		return true;
	}
	if (n % 4 == 0 && n % 100 != 0)
	{
		return true;
	}
	return false;
}
int daysInMonth(int year, int month)
{
	if (month != 2)
	{
		return days_in_month[month];
	}
	else
	{
		if (isLeapYear(year) == true)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
}

class Date {
public:
	int year,month,day;
	Date() {
		year = month = day = 0;
	}
	void SetDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void PrintDate() {
		cout << year << "/" << month << "/" << day;
	}

};

class Time {
public:
	int hour, minute, second;
	Time() {
		hour = minute = second = 0;
	}
	void SetTime(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}
	void PrintTime() {
		cout << hour << ":" << minute << ":" << second;
	}
};

class DateTime :public Date, public Time {
public:
	void incrementSeconds(int s) {
		second += s;
		while (second >= 60)
		{
			minute++;
			second -= 60;
		}
		while (minute >= 60)
		{
			hour++;
			minute -= 60;
		}
		while (hour >= 24)
		{
			day++;
			hour -= 24;
		}
		while (day > daysInMonth(year, month))
		{
			day -= daysInMonth(year, month);
			month++;
			
			while (month > 12)
			{
				year++;
				month -= 12;
			}
		}
	}
	void PrintDateTime()
	{
		PrintDate();
		cout << " ";
		PrintTime() ;
		cout << endl;
	}

};


int main()
{
	int n;
	cin >> n;
	DateTime a;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "PrintDateTime")
		{
			a.PrintDateTime();
		}
		if (s == "incrementSeconds")
		{
			int sec;
			cin >> sec;
			a.incrementSeconds(sec);
		}
		if (s == "SetTime")
		{
			int h, m, s;
			cin >> h >> m >> s;
			a.SetTime(h, m, s);
		}
		if (s == "SetDate")
		{
			int y, m, d;
			cin >> y >> m >> d;
			a.SetDate(y, m, d);
		}
	}
	return 0;
}