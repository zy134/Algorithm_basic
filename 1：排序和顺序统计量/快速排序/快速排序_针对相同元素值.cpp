#include<iostream>
#include<random>
#include<ctime>
#include<Windows.h>

using namespace std;
void partition(int A[], int beg, int end, int &left, int &right)
{
	// A[left..right]中所有元素都等于主元素------（1）
	// A[beg..left-1]中每个元素都小于主元素------（2）
	// A[right+1..end]中每个元素都大于主元素-----（3）
	//省去排序重复元素的损耗
	int target = A[end];
	left = beg-1, right = end;
	for (int i = beg; i < end; i++)
	{
		if (i >= right)
			break;
		while (A[i] > target && i < right)
			swap(A[--right], A[i]);
		if (A[i] < target)
			swap(A[++left], A[i]);
	}
	/*
	A[i]有三种情况 1：A[i]>target  2：A[i]<target  3：A[i]=target
	我们用一个循环解决情况1，然后只剩下两种情况
	对于情况2，我们将它与A[++left]交换一次即可，因为i会前进，这样保证了A[beg~left]中的每个元素都小于主元素
	对于情况3，不用做处理，这样使A[left+1,right-1]皆等于target
	*/

	swap(A[right], A[end]);     //保持性质（3）
	left++;                     //保持性质（2）

}
void quick_sort(int A[], int beg, int end)
{
	if (beg < end)
	{
		int left, right;
		partition(A, beg, end, left, right);
		quick_sort(A, beg, left - 1);
		quick_sort(A, right + 1, end);
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
