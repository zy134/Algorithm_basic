#include<iostream>
#include<windows.h>
#include<random>
#include<ctime>
using namespace std;
//以三叉堆为例

void Heap_Inseert(int *A,int key,int* size);
void Build_Heap(int *A,const int length);
void Heap_Increase_Key(int*A,int key,int i);
//对于用插入方式建立的堆来说，只要改动parent函数就行
int Parent(int i){
    if(i==1)
        return 0;
    else
        return i/3;
}
int main()
{

    int *A;
    const int length=10;
    A=new int[length];
    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0,500);

    for(int i=0;i!=length;++i)
        A[i]=u(e);

    for(int i=0;i!=length;++i)
        cout<<"  "<<A[i];
    cout<<endl;

    Build_Heap(A,length);
    for(int i=0;i!=length;++i)
        cout<<"  "<<A[i];
    delete []A;
    system("pause");
    return 0;
}

void Heap_Increase_Key(int*A,int key,int i)   //提高A[i]的关键字，并使A[i]上浮
{
    if(key<A[i])
        return ;
    A[i]=key;
    while(i>0&&A[Parent(i)]<A[i])
    {
        swap(A[Parent(i)],A[i]);
        i=Parent(i);
    }
}

void Heap_Inseert(int *A,int key,int *size)
{
    (*size)++;
    int new_elem=*size-1;             //new_elem表示新插入元素的下标
    A[new_elem]=-99999;              //扩容，并在堆的尾部插入新元素
    Heap_Increase_Key(A,key,new_elem); //然后是新插入的元素上浮，以保持堆序性
}

void Build_Heap(int *A,const int length)
{
    int *size=new int(1);                    //size表示已排序的元素数量
    for(int i=1;i!=length;i++)
        Heap_Inseert(A,A[i],size); //A[0~i]为已排序的堆，A[i+1~length-1]为未排序的部分
    delete size;

}