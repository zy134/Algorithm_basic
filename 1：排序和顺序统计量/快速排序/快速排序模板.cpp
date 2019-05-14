#include<iostream>
#include<utility>
#include<random>
#include<ctime>
using namespace std;
/*
模板参数需支持：自增，小于，不等于操作
*/
template <typename T,typename Y>
auto parttion(Y A[],const T beg,const T end)->decltype(beg)
{
   T i,j;
   Y key=A[end];
   for(i=beg-1,j=beg;j!=end;++j)
   {
       if(A[j]<=key)
       {
           i++;
           swap(A[i],A[j]);
       }
   }
   swap(A[++i],A[end]);
   return i;
}

template <typename T,typename Y>
void quick_sort(Y A[],const T beg,const T end)
{
    if(!(beg<end))                  //只要求定义<号
        return ;
    const T center=parttion(A,beg,end);
    quick_sort(A,beg,center-1);
    quick_sort(A,center+1,end);
}

int main()
{
    const int length=20;
    int *A=new int [length];
    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0,200);
    for(int i=0;i!=length;++i)
        A[i]=u(e);
    quick_sort(A,0,length-1);
    for(int i=0;i!=length;++i)
        cout<<A[i]<<"  ";
    delete []A;
}