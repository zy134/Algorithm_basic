#include<iostream>
#include<random>
#include<ctime>
#include<windows.h>
//随机化理论上可以避免坏的界，但是求随机数本身就需要一定时间，故需斟酌使用
using namespace std;
int parttion(int A[],const int beg,const int end)
{
    const int target=A[end];
    int i=beg-1,j=beg;
    for(;j!=end;++j)
    {

        if(A[j]<=target)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[++i],A[end]);
    return i;
}

int random_parttion(int A[],const int beg,const int end)
{
    default_random_engine e(time(0));
    uniform_int_distribution<unsigned> u(beg,end);
    int i=u(e);
    swap(A[i],A[end]);
    return parttion(A,beg,end);
}


int fast_sort(int A[],const int beg,const int end)
{
    if(beg<end)
    {
        int p=random_parttion(A,beg,end);
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