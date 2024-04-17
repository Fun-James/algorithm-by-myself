#include <iostream>
#include <cstring>
using namespace std;
const int max_size = 10;

class queue {
	float data[max_size];
	int front, rear;
	int num;
public:
	queue() {
		front = rear = -1;//数据存在front+1和rear中
		num = 0;
	}
	bool Empty() {
		if (num == 0)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	bool Full() {
		if (num == max_size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Add(float a) {
		num++;
		rear = (rear + 1) % max_size;//循环队列
		data[rear] = a;
		
	}
	float Delete() {
		num--;
		front = (front + 1) % max_size;
		return data[front];
	}
};

int main()
{
	int n;
	cin >> n;
	queue q;
	for (int i = 0; i < n; i++)
	{
		int act;
		cin >> act;
		if (act == 0)
		{
			float n;
			cin >> n;
			q.Add(n);
		}
		else if (act == 1)
		{
			cout<<q.Delete()<<endl;
		}
		else if (act == 2)
		{
			cout << q.Empty()<<endl;
		}
		else if (act == 3)
		{
			cout << q.Full()<<endl;
		}
	}
	return 0;
}