#include<iostream>
#include<windows.h>
#include<random>
#include<ctime>
using namespace std;

/*
k排序即对于数组A[0~n]，A[i...i+k]/k <= A[i+1...i+k+1]/k
当数组每个元素都有A[i]<=A[i+k]时，即可保证k排序性质
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

/*
    for(int i=0;i!=left_length;++i)
        cout<<L[i]<<"  ";
    for(int i=0;i!=right_length;++i)
        cout<<R[i]<<"  ";
    cout<<endl;
*/