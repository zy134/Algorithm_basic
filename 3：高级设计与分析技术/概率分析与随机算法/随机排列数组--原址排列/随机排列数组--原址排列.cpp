#include<iostream>
#include<Windows.h>
#include<random>
#include<ctime>
using namespace std;
//原址排列随机数组

int main()
{
    default_random_engine e(time(0));
	
	const int n=10;
	int A[]={2,1,3,6,8,5,87,89,36,45};
	for (int i = 0; i != n; ++i)
	{
	    uniform_int_distribution<unsigned> u(i,9);
		swap(A[i],A[u(e)]);
	}
	    
}