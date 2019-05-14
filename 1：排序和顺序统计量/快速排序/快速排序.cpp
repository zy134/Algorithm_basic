#include<iostream>
#include<ctime>
#include<random>
using namespace std;
/*
quick_sort的核心思想同样为分治，与归并排序不同的是，快速排序先治再分
devide将数组分成两部分：一部分小于target，一部分大于target
然后再对分成的子数组继续进行devide，分成小于target与大于target的两个子数组，直至不能再分，排序完毕

*/
int devide(int A[],const int beg,const int end)
{
    //A[0~i]为小于target的部分，A[i+1~j]为大于target的部分，A[j+1~end]为未排序部分

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
    //i为分割点，A[i]此时等于target
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