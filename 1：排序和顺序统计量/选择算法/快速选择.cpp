#include<iostream>
#include<random>
#include<ctime>
#include<windows.h>
using namespace std;

int random(const int a,const int b)
{
    default_random_engine e(time(0));
    uniform_int_distribution<int> u(a,b);
    return u(e);
}

int parttion(int A[],const int beg,const int end)
{
    const int center=random(beg,end);
    swap(A[center],A[end]);
    int key=A[end];
    int i,j;
    for(i=beg-1,j=beg;j!=end;++j)
    {
        if(A[j]<=key)
        {
            ++i;
            swap(A[i],A[j]);
        }
    }
    swap(A[++i],A[end]);
    return i;
}

//利用快速排序，选择第i大的元素
//只对几乎一半的数组进行处理，由parttion返回的位置k即为数组中第k大的数，将k与i作比较直到k=i
int select(int A[],const int beg,const int end,const int i)
{
    if(beg==end)
        return A[beg];
    const int center=parttion(A,beg,end);
    int k=center-beg+1;
    if(k==i)          
        return A[center];
    else if(i<k)
        return select(A,beg,center-1,i);
    else
        return select(A,center+1,end,i-k);
}

int main()
{
    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0,100);
    const int length=20;
    int *A=new int[length];
    for(int i=0;i!=length;++i)
        A[i]=u(e);
    int i=6;
    cout<<"The "<<i<<"th"<<" bigger number in the array is: "<<select(A,0,length-1,i)<<endl;
    for(int i=0;i!=length;++i)
        cout<<A[i]<<"  ";
    delete []A;
    return 0;
}