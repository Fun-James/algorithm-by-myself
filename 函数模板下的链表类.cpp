#include <iostream>
#include <string>
using namespace std;

template <class T>
class list { 		//类模板 list，使用类型形参 T
	struct node { 			//结构体 node 类型用来定义链表表项（的具体数据项）
		T data; 		//每一表项的 data 数据域的类型由类型形参 T 所指定
		node* next; 		//通过指针 next，将多个表项“链接”成一个链表
	};		//数据成员 head 与 tail，为链表的首尾指针
	node* head;
	node* tail;
public:
	list()
	{
		head = nullptr;
		tail = nullptr;
	}//构造函数，创建“空链表”
	void Insert(T item)
	{
		node* temp = new node;
		temp->next = nullptr;
		temp->data = item;
		if (head == nullptr)//list为空
		{
			head = temp;
			tail = temp;
			return;
		}
		else
		{
			temp->next = head;
			head = temp;
			return;
		}
	}		//生成链表项插入到原链的链首
	void Append(T item)
	{
		node* temp = new node;
		temp->next = nullptr;
		temp->data = item;
		if (head == nullptr)
		{
			head = tail = temp;
			return;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}


	}//生成链表项附加到原链的链尾
	int count()
	{
		node* temp = head;
		int count = 0;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}//返回当前链表的项数
	void htot()
	{
		if (count() == 1 || count() == 0)
		{
			return;
		}
		node* temp = head;
		head = head->next;
		temp->next = nullptr;
		
		tail->next = temp;
		tail = temp;
	}//把链表首项移到链尾
	void ttoh()
	{
		if (count() == 1 || count() == 0)
		{
			return;
		}
		node* temp = tail;

		//寻找tail的上一个
		node* tp = head;
		node* uptp = nullptr;
		while (tp->next != nullptr)
		{
			uptp = tp;
			tp = tp->next;
		}
		uptp->next = nullptr;

		temp->next = head;
		head = temp;
	}//把链表尾项移到链首
	void display()
	{
		if (count() == 0)
		{
			cout << "emptylist";
		}
		node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}//将各链表项数据 data 显示在屏幕上
};

int main()
{
	string type;
	cin >> type;
	int length;
	cin >> length;
	if (type == "int")
	{
		list<int> ls1;
		list<int> ls2;
		for (int i = 0; i < length; i++)
		{
			int temp;
			cin >> temp;
			ls1.Append(temp);
			ls2.Insert(temp);
		}

		cout << ls1.count() << endl;

		ls1.display();

		ls1.ttoh();
		ls1.display();

		cout << ls2.count() << endl;

		ls2.display();

		ls2.htot();
		ls2.display();
	}
	else if (type == "char")
	{
		list<char> ls1;
		list<char> ls2;
		for (int i = 0; i < length; i++)
		{
			char temp;
			cin >> temp;
			ls1.Append(temp);
			ls2.Insert(temp);
		}

		cout << ls1.count() << endl;

		ls1.display();

		ls1.ttoh();
		ls1.display();

		cout << ls2.count() << endl;

		ls2.display();

		ls2.htot();
		ls2.display();
	}
	return 0;
}

