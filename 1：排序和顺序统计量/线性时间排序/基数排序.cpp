//基数排序从最低有效位进行排序
//要求一位数排序算法必须是稳定的

//利用计数排序。从地位排序至高位
#include<random>
#include<ctime>
#include<iostream>
#include<windows.h>
using namespace std;

inline int units_digit(const int i)
{
    return (i/1)%10;
}
inline int ten_digit(const int i)
{
    return (i/10)%10;
}
inline int hundred_digit(const int i)
{
    return (i/100)%10;
}

void count_sort(int A[],int B[],const int k,const int length,const int bit)
{
    int (*p)(const int);
    if(bit==1)
        p=units_digit;
    else if(bit==2)
        p=ten_digit;
    else if(bit==3)
        p=hundred_digit;


    int *C=new int[k];         //k为10,只排序一个位

    for(int i=0;i!=k;++i)
        C[i]=0;

    for(int i=0;i!=length;++i)
        C[(*p)(A[i])]++;
    
    for(int i=1;i!=k;++i)
        C[i]+=C[i-1];

    for(int i=length-1;i>=0;--i)
    {
        B[C[(*p)(A[i])]]=A[i];
        C[(*p)(A[i])]--;
    }

    for(int i=0;i!=length;++i)
        A[i]=B[i];
    delete []C;
}

void radix_sort(int A[],int B[],const int length)
{
    const int k=10;
    for(int bit=1;bit<=3;++bit)
    {
        count_sort(A,B,k,length,bit);
    }
}


int main()
{
    default_random_engine e(time(0));
    uniform_int_distribution<unsigned> u(100,999);
    
    const int length=30;
    const int bit=1;
    int *A=new int[length];
    int *B=new int[length];
    for(int i=0;i!=length;++i)
        *(A+i)=u(e);
    
    radix_sort(A,B,length);

    for(int i=0;i!=length;++i)
        cout<<"  "<<B[i];

    delete []B;
    delete []A;
    system("pause");
    return 0;
}