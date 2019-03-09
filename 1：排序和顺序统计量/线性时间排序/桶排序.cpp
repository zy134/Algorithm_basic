#include<iostream>
#include<windows.h>
#include<random>
#include<ctime>
using namespace std;


class list_node  //node没有析构函数，它将释放空间的功能交由list实现
{
public:
	list_node(double i = 0.0) :data(i), next(nullptr) {};

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

	double data;
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

	void push_back(const double i)
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
		double key;
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
					double x = temp->data;
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
//桶排序
//A[]中的值必须在[0~1]范围内
//将不同区间的值放在对应的桶中，然后分桶排序
//线性排序，分桶类似于分治，但它利用数组的有序性，从而减少了分治排序算法中合的过程，因而速度要快
//但是浪费空间，算法较复杂（需要链表），且对输入有很大限制
void bucket_sort(double A[], const int length)
{
	list* B = new list[length];   //new分配空间同时也进行了默认初始化
	for (int i = 0; i != length; ++i)
	{
		int p = static_cast<int>(A[i] * length);//先乘再进行转化
		B[p].push_back(A[i]);
	}
	for (int i = 0; i != length; ++i)
		B[i].insert_sort();
//bug
//排序无法结束
//
	for (int i = 0; i != length; ++i)
	{
		if (!B[i].is_empty())
			B[i].print();
	}
	delete[]B;
}

int main()
{
	const int length = 10;
	double *A = new double[length];
	default_random_engine e(time(0));
	uniform_real_distribution<double> u(0, 1);

	for (int i = 0; i != length; ++i)
		A[i] = u(e);
	cout << endl;
	bucket_sort(A, length);

	system("pause");
	return 0;
}
/*


*/