#include<iostream>
#include<ctime>
#include<random>
#include<Windows.h>
using namespace std;

int devide(int A[],const int beg,const int end)
{
    const int target=A[end];

    int i,j;
    for(i=beg-1,j=beg;j!=end;++j)
    {
        if(A[j]<target)
        {
            i++;
            swap(A[j],A[i]);
        }
    }
    ++i;
    swap(A[i],A[end]);
    return i;
}
void fast_sort(int A[],const int beg,const int end)
{
    if(beg<end)
    {
        int flag=devide(A,beg,end);
        fast_sort(A,beg,flag-1);
        fast_sort(A,flag+1,end);
    }
}

int main()
{
    default_random_engine e(time(0));
    uniform_int_distribution<unsigned> u(0,200);
    int *a=new int[10];
    for(int i=0;i!=10;++i)
        *(a+i)=u(e);
    
    fast_sort(a,0,9);

    for(int i=0;i!=10;++i)
        cout<<*(a+i)<<"  ";

    delete []a;
    system("pause");
    return 0;
}