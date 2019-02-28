#include<iostream>
#include<windows.h>
#include<random>
#include<ctime>
using namespace std;

int devide(int A[],const int beg,const int end)
{
    int target=A[end];
    int i,j;
    for(i=beg-1,j=beg;j!=end;++j)
    {
        if(A[j]<target)
        {
            ++i;
            swap(A[j],A[i]);
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
        int q=devide(A,beg,end);
        quick_sort(A,beg,q-1);
        quick_sort(A,q+1,end);
    }
}
//普通的快速排序

void tail_recursive_quick_sort(int A[],int beg,int end)
{
    while(beg<end)
    {
        int q=devide(A,beg,end);
        tail_recursive_quick_sort(A,beg,q-1);
        beg=q+1;
    }
}
//用一个循环结构代替一个递归，从而节省对栈空间的使用

void tail_recursive_quick_sort_2(int A[],int beg,int end)
{
    int left,right;
    while(beg<end)
    {
        int q=devide(A,beg,end);
        left=q-beg;
        right=end-q;
        if(right>left)
        {
            tail_recursive_quick_sort_2(A,beg,q-1);
            beg=q+1;
        }
        else
        {
            tail_recursive_quick_sort_2(A,q+1,end);
            end=q-1;
        }        
    }
}
//改进后的尾递归
//分割后，小数组进入递归，大数组进入循环
//这样就能避免最坏情况，保证栈深度始终<n/2

 int main()
 {
    default_random_engine e(time(0));
    uniform_int_distribution<unsigned> u(0,500);
    const int size=20;
    int *A=new int[size];
    
    for(int i=0;i!=size;++i)
        *(A+i)=u(e);

    tail_recursive_quick_sort_2(A,0,size-1);

    for(int i=0;i!=size;++i)
        cout<<"   "<<*(A+i);

    delete []A;

    system("pause");
    return 0;
 }