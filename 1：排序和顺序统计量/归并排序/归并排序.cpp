#include<iostream>
#include<random>
#include<ctime>
#include<windows.h>
using namespace std;


/*
MERGE(A,p,q,r)
    n1=q-p-1
	n2=r-q
	let L[1,2...n1+1] and R[1,2...n2+1] be new array
	for i=1 to n1
	    L[i]=A[p+i]
	for j=1 to n2
	    R[j]=A[q+j]
    L[n1+1]=unlimited
	R[n2+1]=unlimited
	i=1,j=1
	for k=p to r
	    if L[i]<=R[j]
		    A[k]=L[i]
		    i=i+1
	    else
		    A[k]=R[j]
			j=j+1

MERGE_SORT(A,p,r)
    q=(p+r)/2
	MERGE_SORT(A,p,q)
	MERGE_SORT(A,q+1,r)
	MERGE(A,p,q,r)
原理：
    就像两幅已排序的扑克牌，要将他们和成一副扑克牌。应当翻开两个牌顶，取小的那张扑克放入新牌堆。
	然后刚刚堆顶牌比较小的牌堆再翻开张新牌，再比较两个牌堆的堆顶牌。以此往复。

	归并排序先分后治再合，先将数组不断二分直至不能再分，然后将小数组按上诉规则不断合一，最后得出
	的合数组就是排序成功的
*/
void merge(int A[],const int beg,const int center,const int end)
{

    const int left_length=center-beg+1;
    const int right_length=end-center;
    int *L=new int[left_length+1];
    int *R=new int[right_length+1];
    L[left_length]=99999;
    R[right_length]=99999;
    int i,j,k;

    for(k=beg,i=0;k!=center+1;++k)
        L[i++]=A[k];
    for(k=center+1,j=0;k!=end+1;++k)
        R[j++]=A[k];

    
    for(i=0,j=0,k=beg;k!=end+1;++k)
    {
        if(L[i]<=R[j])
            A[k]=L[i++];
        else
            A[k]=R[j++];
    }
    delete []L;
    delete []R;
}

void merge_sort(int A[],const int beg,const int end)
{
    if(beg<end)
    {
        const int center=(beg+end)/2;
        merge_sort(A,beg,center);
        merge_sort(A,center+1,end);
        merge(A,beg,center,end);
    }
}

int main()
{

    const int length=20;
    int *A=new int[length];
    
    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0,200);
    for(int i=0;i!=length;++i)
        A[i]=u(e);
    merge_sort(A,0,length-1);
    for(int i=0;i!=length;++i)
        cout<<A[i]<<"  ";
    delete []A;
    system("pause");
    return 0;
}