#include<iostream>
#include<memory>
#include<random>
#include<ctime>
#include<windows.h>
using namespace std;
void Max_Heapify(int *A,const int size,int i)
{
    int left=2*i;
    int right =2*i+1;
    int largest;
    if(left<size&&A[left]>A[i])
        largest=left;
    else
        largest=i;
    
    if(right<size&&A[right]>A[largest])
        largest=right;
    if(i!=largest)
    {
        swap(A[i],A[largest]);
        Max_Heapify(A,size,largest);
    }       
}
void Build_Max_Heap(int *A,const int size)
{
    for(int i=size/2;i>=0;--i)
        Max_Heapify(A,size,i);
}
void Heap_Sort(int *A,int size)
{
    Build_Max_Heap(A,size);

    for(int i=size-1;i!=0;--i)
    {
        swap(A[0],A[i]);
        size--;
        Max_Heapify(A,size,0);
    }
    
}

int main()
{
    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0,50);
    int size=11;
    int *A=new int[size];
    for(int i=0;i!=size;i++)
        A[i]=u(e);
    Heap_Sort(A,size);
    for(int i=0;i!=size;i++)
        cout<<A[i]<<"  ";
    system("pause");
    return 0;
}