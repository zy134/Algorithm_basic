#include<iostream>
#include<windows.h>
#include<random>
#include<ctime>
using namespace std;



//从三个元素中取中位数为主元
int devide(int A[],const int beg,const int end)
{
    int center=(beg+end)/2;
    int pos;
    if(A[beg]>=A[center]&&A[beg]>=A[end])
    {
        if(A[center]>=A[end])
            pos=center;
        else
            pos=end;
    }
    else if(A[center]>=A[beg]&&A[center]>=A[end])
    {
        if(A[beg]>=A[end])
            pos=beg;
        else
            pos=end;
    }
    else
    {
        if(A[beg]>=A[center])
            pos=beg;
        else
            pos=center;
    }

    int target=A[pos];
    swap(A[pos],A[end]);

    int i,j;
    for(i=beg-1,j=beg;j!=end;++j)
    {
        if(A[j]<=target)
        {
            ++i;
            swap(A[i],A[j]);
        }
    }
    ++i;
    swap(A[i],A[end]);
    return i;   
}


//从三个随机选定的元素中选取中位数为主元
int random_devide(int A[],const int beg,const int end)
{
    default_random_engine e(time(0));
    uniform_int_distribution <unsigned> u(beg,end);
    int a=u(e),b=u(e),c=u(e);
    int pos;
    if(A[a]>=A[b]&&A[a]>=A[c])
    {
        if(A[b]>=A[c])
            pos=b;
        else
            pos=c;
    }
    else if(A[b]>=A[a]&&A[b]>=A[c])
    {
        if(A[a]>=A[c])
            pos=a;
        else
            pos=c;
    }
    else
    {
        if(A[a]>=A[b])
            pos=a;
        else
            pos=b;
    }

    int target=A[pos];
    swap(A[pos],A[end]);

    int i,j;
    for(i=beg-1,j=beg;j!=end;++j)
    {
        if(A[j]<=target)
        {
            ++i;
            swap(A[i],A[j]);
        }
    }
    ++i;
    swap(A[i],A[end]);
    return i;   
}

void quick_sort(int A[],const int beg,const int end)
{
    if(beg<end)
    {
        int flag=devide(A,beg,end);
        quick_sort(A,beg,flag-1);
        quick_sort(A,flag+1,end);
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