#include<iostream>
#include<deque>
#include<Windows.h>
using namespace std;
int main()
{
    /*
	cout<<"排序序列数目为：";
	int n;
	cin>>n;
	cout<<'\n'<<"输入排序序列:";
	deque<int> deq;
	while (deq.size()<=n)
	{
	    int temp;
		cin>>temp;
		deq.push_back(temp);
	}
	*/

	/*
	for j=2 to A.length
	    key=A[j]
		i=j-1
		while i>0 and A[i]>key
		    A[i+1]=A[i]
			i=i-1
		A[i+1]=key
	*/

	int A[]={56,1,2,32,45,988,65,3,23,9};
	int i,j;

	for (j = 1; j != 10; j++)
	{
		i=j-1;
		int key=A[j];
		while (i >= 0 && A[i] > key)
		{
			A[i+1]=A[i];
			i=i-1;
		}
		A[i+1]=key;
	}

	for (auto temp : A)
		cout << "  " << temp;
	system("pause");
	return 0;
}