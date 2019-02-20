#include"Rand_Seq.h"
#include<iostream>
#include<Windows.h>
using namespace std;

int partition(int A[],const int left,const int right);  //����Ԫ�ط����ұߣ�СԪ�ط������
void fast_sort(int A[],const int left,const int right);  //leftΪ��ʼλ�ã�rightΪĩλ��

int main()
{
	Random_Sequence r(10);
	int *a=r.return_seq();
	fast_sort(a,0,9);
	for(int i=0;i!=10;++i)
	    cout<<*(a+i)<<"  ";

	delete a;
	system("pause");
	return 0;
}

int partition(int A[],const int left,const int right)
{
	int target=A[right];
	int i=left-1,j=left;
	//A[i~j]��ʾһ�����䣬������Ԫ�ش���x���������Ԫ��С��x�������ұ�Ԫ��δ����
	for (; j <= right - 1; j++)
	{
		if (A[j] <= target)
		{
			++i;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[right]);
	return i+1;
}

void fast_sort(int A[], const int left, const int right)
{
	if (left < right)
	{
		int p = partition(A, left, right);
		fast_sort(A, left, p-1);
		fast_sort(A, p + 1, right);
	}
	
}