#include<iostream>
#include<random>
#include<ctime>
#include<windows.h>
using namespace std;

int hoare_parttion(int A[],const int beg,const int end)
{
    int key=A[beg];
    int i=beg;
    int j=end;
    while(i<j)
    {
        while(j>beg&&A[j]>=key)
            --j;
        while(i<end&&A[i]<=key)
            ++i;
        if(i<j)
            
            swap(A[i],A[j]);
    }
    swap(A[beg],A[j]);
    return j;
    //关键点在于分割点为j
}


void fast_sort(int A[],const int beg,const int end)
{
    if(beg<end)
    {
        int p=hoare_parttion(A,beg,end);
        fast_sort(A,beg,p-1);
        fast_sort(A,p+1,end);
    }
}

int main()
{
    default_random_engine e(time(0));
    uniform_int_distribution<unsigned> u(0,500);
    int *A=new int[10];
    for(int i=0;i!=10;++i)
        *(A+i)=u(e);

    fast_sort(A,0,9);

    for(int i=0;i!=10;++i)
        cout<<"  "<<*(A+i);


    delete []A;
    system("pause");
    return 0;
}