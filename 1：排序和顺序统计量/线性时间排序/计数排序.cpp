#include<iostream>
#include<random>
#include<ctime>
#include<ctime>
#include<windows.h>
using namespace std;
//计数排序耗时O（k+length）
//非比较排序，稳定性排序
void count_sort(int A[],int B[],const int length,const int k)
{
    int *C=new int[k];
    for(int i=0;i!=k;++i)
        C[i]=0;
    for(int i=0;i!=length;++i)
        C[A[i]]++;
    for(int i=1;i!=k;++i)
        C[i]+=C[i-1];
    for(int i=length-1;i>=0;--i)       //逆序，用以保证算法的稳定性
    {
        B[C[A[i]]-1]=A[i];             //与伪代码中的不同，由于数组从0开始，故须-0
        C[A[i]]--;
    }
    delete []C;
}

int main()
{
    const int k=20;
    const int length=20;
    int *A=new int[length];
    int *B=new int[length];

    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0,k);
    for(int i=0;i!=length;++i)
        A[i]=u(e);


    count_sort(A,B,length,k+1);

    for(int i=0;i!=length;++i)
        cout<<A[i]<<"  ";
    cout<<endl;

    for(int i=0;i!=length;++i)
        cout<<B[i]<<"  ";
    cout<<endl;

    delete []A;
    delete []B;
    system("pause");
    return 0;
}