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
void count_sort(int A[],const int length,const int k)
{
    int *C=new int[k];
    int *P=new int[k];
    for(int i=0;i!=k;++i)
        C[i]=A[i];
    for(int i=0;i!=length;++i)
        C[A[i]]++;
    for(int i=1;i!=k;++i)
        C[i]+=C[i-1];
    for(int i=0;i!=k;++i)
        P[i]=C[i];
    
    int j=0;
    while(j!=length)
    {
        bool placed;
        if(A[j]==0)
            placed=(j<=P[A[j]]);
        else
            placed=(j>=P[A[j]-1]&&j<P[A[j]]);

        if(placed)
            ++j;
        else
        {
            swap(A[j],A[C[A[j]]]);
            C[A[j]]--;
        }
        
    }

    delete []C;
    delete []P;
}
int main()
{
    const int length=50;
    const int k=20;
    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0,k);
    int *A=new int[length];
    for(int i=0;i!=length;++i)
        A[i]=u(e);
    count_sort(A,length,k+1);

    for(int i=0;i!=length;++i)
        cout<<A[i]<<"   ";
    system("pause");
    return 0;
}