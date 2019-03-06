#include<iostream>
#include<random>
#include<ctime>
#include<ctime>
#include<windows.h>
using namespace std;

void count_sort(int A[],int B[],const int length,const int k)
{
    int *C=new int[k];
    for(int i=0;i!=k;++i)
        C[i]=0;
    for(int i=0;i!=length;++i)
        C[A[i]]++;
    for(int i=1;i!=k;++i)
        C[i]+=C[i-1];
    for(int i=length-1;i>=0;--i)
    {
        B[C[A[i]]]=A[i];
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