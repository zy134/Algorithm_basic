#include"HeapSort.h"
#include<random>
#include<ctime>
#include<iostream>
using namespace std;
int * Heap::Rand_Seq(const int n)
{
	default_random_engine e(time(0));
	uniform_int_distribution<int> u(-100, 100);
	int *temp = new int[n];
	for (int i = 0; i != n; i++)
	{
		temp[i] = u(e);
	}
	return temp;
}

Heap::Heap(const Heap&rhs):length(rhs.length),size(rhs.size)
{
	data = new int[rhs.length];
	for (int i = 0; i != size; i++)
		data[i] = rhs.data[i];
}

Heap& Heap::operator=(const Heap&rhs)
{
    const int n=rhs.length;
	int *temp = new int[n];
	for (int i = 0; i !=n; i++)
	{
		temp[i] = rhs.data[i];
	}
	delete[]data;
	data = temp;
	temp = nullptr;
	size=rhs.size;
	length=rhs.length;
	return *this;
}

Heap::~Heap()
{
	delete[]data;
}

void Heap::Max_Heapify(int i)     //ά���ѵ�������ʣ�ʱ�临�Ӷ�ΪO(lgN)
{
	int l = left(i);
	int r = right(i);
	int largest;
	if (l < size&&data[i] < data[l])
		largest = l;
	else largest=i;
	if (r < size&&data[largest] < data[r])
		largest = r;

	if (largest != i)
	{
		swap(data[i],data[largest]);
        Max_Heapify(largest);
	}
}

void Heap::Build_Max_Heap()      //�Ե����Ͻ���,ʱ�临�Ӷ�ΪO(NlgN)
{
	for (int i = size / 2; i >= 0; --i)   //û�б�Ҫ��Ҷ�ӽڵ����Max_Heapify������û���ӽڵ�
		Max_Heapify(i);
}

void Heap::Print()
{
	for (int i = 0; i != length; i++)
	{
		cout << data[i] << "  ";
	}
}

void Heap::Sort()
{
	size=length;
	Build_Max_Heap();
	for (int i = length - 1; i!=0; i--)
	{
	    size--;
		swap(data[0],data[i]);
		Max_Heapify(0);

	}
}