#include<iostream>
#include<random>
#include<ctime>

using namespace std;
constexpr int none=-99999;
int main()
{
    const int length=20;
    int *A=new int[length];
    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0,200);
    for(int i=0;i!=length;++i)
        A[i]=u(e);
    int max=0,min=0;
    int a=0,b=0;
    for(int i=0;i!=length;i+=2)
    {
        a=A[i];
        if(i<length)
        {
            b=A[i+1];
            if(a>=b)
            {
                if(a>=max)
                    max=a;
                if(b<=min)
                    min=b;
            }
            else
            {
                if(b>=max)
                    max=b;
                if(a<=min)
                    min=a;
            }
        }
        else
        {
            if(a>=max)
                max=a;
            if(a<min)
                min=a;
        }
    }
    delete []A;
    return 0;
}