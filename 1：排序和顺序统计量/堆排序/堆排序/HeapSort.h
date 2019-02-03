#pragma once
#include<iostream>
#include<memory>
#include<initializer_list>
class Heap
{
public:
	Heap() :data(nullptr), size(0) ,length(0){}
	Heap(std::initializer_list<int> li):size(li.size()),length(li.size())
	{
	    int n=li.size();
		data = new int[n];
		int i = 0;
		for (auto elem : li)
		{
			data[i] = elem;
			i++;
		}
	}
	Heap(int *data_list):length(sizeof(data_list)/sizeof(int)),size(sizeof(data_list) / sizeof(int))
	{
		data = data_list;
		data_list = nullptr;
	}
	Heap(const int n) :data(Rand_Seq(n)), size(n),length(n) {}
	Heap(const Heap&);
	Heap& operator=(const Heap&);
	~Heap();

	void Build_Max_Heap();
	void Print();
	void Sort();
private:
	int *data;
	int size;
	int length;
	int *Rand_Seq(const int n);
	void Max_Heapify(int i);
	inline int left(int i) { return i*2; }
	inline int right(int i) { return i * 2+1; }
};

