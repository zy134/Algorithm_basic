#include<iostream>
#include<windows.h>
#include<random>
#include<ctime>
using namespace std;


class list_node  //node没有析构函数，它将释放空间的功能交由list实现
{
public:
	list_node(long i = 0) :data(i), next(nullptr) {};

	list_node& operator==(const list_node&rhs)
	{
		if (this == &rhs)
			return *this;
		else
		{
			auto p = this->next;
			delete p;

			this->data = rhs.data;
			this->next = rhs.next;
			return *this;
		}
	}

	long data;
	list_node* next;

};


class list
{
public:

	list() :head(new list_node(-99999)), begin(nullptr), rear(nullptr), length(0) {}

	bool is_empty()
	{
		if (begin == nullptr)
			return true;
		else
			return false;
	}

	void push_back(const int i)
	{
		if (begin == nullptr)
		{
			begin = new list_node(i);
			head->next = begin;
			rear = begin;
			++length;
		}
		else
		{
			rear->next = new list_node(i);
			++length;
			rear = rear->next;
		}
	}


	void insert_sort()
	{

		if (begin == nullptr||begin->next==nullptr)
			return;
		auto p = begin->next;
		int key;
		while (true)
		{   
		    if(p==nullptr)
			    break;
			key = p->data;
			auto temp = begin;
			while (temp != p)
			{
	
				if (temp->data > key)
				{
					int x = temp->data;
					temp->data = p->data;
					p->data = x;
				}
				temp = temp->next;
			}
			p = p->next;
		}
	}

	void print()
	{
		auto p = begin;
		for (auto i = 0; i != length; ++i)
		{
			cout << p->data << "  ";
			p = p->next;
		}
	}

	~list()
	{
		list_node* p = head;
		for (int i = 0; i != length + 1; ++i)
		{
			list_node* temp = p;
			p = p->next;
			delete temp;
		}
	}
private:
	list_node* const  head;   //head不储存任何值，且位置固定，为链表头
	list_node* begin;
	list_node* rear;
	int length;

};

inline int getbit(const int num)
{
	int i=num;
    int bit=1;
	while(true)
	{
		if(i<10)
		    return bit;
		else
		{
			++bit;
			i/=10;
		}
	}
}
//按位分组放入桶中

void bucket_sort(long A[],const int length,const int highest_bit)
{
    list* list_table=new list[highest_bit+1];
	for(int i=0;i!=length;++i)
	{
		int bit=getbit(A[i]);
		list_table[bit].push_back(A[i]);
	}
	for(int i=1;i<=highest_bit;++i)
	{
        list_table[i].insert_sort();
		list_table[i].print();
	}

	delete []list_table;
}

int main()
{
    const int highest=6;
	const int length=20;
	default_random_engine e(time(0));
	uniform_int_distribution<long> u(0,999999);
	long *A=new long[length];
	for(int i=0;i!=length;++i)
	    A[i]=u(e);

	bucket_sort(A,length,highest);
    delete []A;
    system("pause");
    return 0;
}