#include<iostream>
#include<random>
#include<ctime>
#include<windows.h>
using namespace std;
/*
由计数排序修改而来的原址排序，只耗用O(k)多余空间，运行时间为O(N)，但该排序不具有稳定性

原理：检查每一个位置上是否摆放了正确的元素，若是则++j，检查下一个格子；
	若不是，则将现元素摆放到它该去的格子中，再检查当前格子中是否摆放了
	正确的元素，如此循环
*/
void count_sort(int A[],const int length, const int k)
{
	int *C = new int[k+1];
	for (int i = 0; i <= k; ++i)
		C[i] = 0;
	for (int i = 0; i != length; ++i)
		C[A[i]]++;
	for (int i = 1; i <=k; ++i)
		C[i] += C[i - 1];
	for(int i=0;i!=length;++i)
	    A[i]=0;
	for (int i = k; i != 0; --i)
	{
		while (C[i] != C[i - 1])    //当C[i]==C[i-1]时，说明C[i]中已经没有元素了
		{
			A[C[i] - 1] = i;        //这里-1，因数组从0开始，与伪代码略不同
			C[i]--;
		}
	}
}

int main()
{
	const int k = 20;
	const int length = 20;
	int *A = new int[length];
	
	default_random_engine e(time(0));
	uniform_int_distribution<int> u(0, k);
	for (int i = 0; i != length; ++i)
		A[i] = u(e);
	count_sort(A,length, k);

	for (int i = 0; i != length; ++i)
		cout << A[i] << "  ";
	cout << endl;

	delete[]A;
	system("pause");
	return 0;
}