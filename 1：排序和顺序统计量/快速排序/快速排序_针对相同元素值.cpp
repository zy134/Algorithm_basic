#include<iostream>
#include<random>
#include<ctime>
#include<Windows.h>

using namespace std;
void partition(int A[], int p, int r, int &q, int &t)
{
	// A[q..t]中所有元素都等于主元素
	// A[p..q-1]中每个元素都小于主元素
	// A[t+1..r]中每个元素都大于主元素
	int x = A[r];
	q = p-1, t = r;
	for (int i = p; i < r; i++)
	{
		if (i >= t)
			break;
		while (A[i] > x && i < t)
			swap(A[--t], A[i]);
		if (A[i] < x)
			swap(A[++q], A[i]);
	}
	swap(A[t], A[r]);
	q++;

}
void quick_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int q, t;
		partition(A, p, r, q, t);
		quick_sort(A, p, q - 1);
		quick_sort(A, t + 1, r);
	}
}
int main()
{
	default_random_engine e(time(0));
    uniform_int_distribution<unsigned> u(0,200);
    int *a=new int[10];
    for(int i=0;i!=10;++i)
        *(a+i)=u(e);
    
    quick_sort(a,0,9);

    for(int i=0;i!=10;++i)
        cout<<*(a+i)<<"  ";

    delete []a;
    system("pause");
    return 0;
}
