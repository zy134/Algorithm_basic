#include<iostream>
#include<windows.h>
#include<random>
#include<ctime>
using namespace std;


class list_node
{
    public:
    list_node(int i=0):data(i),next(nullptr){};
    ~list_node()
    {
        if(next==nullptr)
            return ;
        if(next->next==nullptr)
        {
            delete next;
            next=nullptr;
        }
        else
            next->~list_node();
    }
    list_node& operator==(const list_node&rhs)
    {
        if(this==&rhs)
            return *this;
        else
        {
            auto p=this->next;
            delete p;

            this->data=rhs.data;
            this->next=rhs.next;
            return *this;
        }
    }

    int data;
    list_node* next;

};


class list
{
    public:

    list():head(new list_node(-99999)),begin(nullptr),rear(nullptr),length(0){}

    void push_back(const int i)
    {
        if(begin==nullptr)
        {
            begin=new list_node(i);
            head->next=begin;
            rear=begin;
            ++length;       
        }
        else
        {
            rear->next=new list_node(i);
            ++length;
            rear=rear->next; 
        }
    }


    void insert_sort()
    {
        auto p=begin->next;
        if(begin==nullptr)
            return ;
        int key;
        while(true)
        {
            if(p==nullptr)
                break;
            key=p->data;
            auto temp=begin;
            while(temp!=p)
            {
                if(temp->data>key)
                {
                   swap(temp->data,p->data);
                }
                temp=temp->next;
            }
            p=p->next;
        }
    }

    void print()
    {
        auto p=begin;
        for(auto i=0;i!=length;++i)
        {
            cout<<p->data<<"  ";
            p=p->next;
        }
    }

    ~list()
    {
        list_node* p=head;
        for(int i=0;i!=length+1;++i)
        {
            list_node* temp=p;
            p=p->next;
            delete temp;
        }
    }
    private:
    list_node* const  head;   //head不储存任何值，且位置固定，为链表头
    list_node* begin;
    list_node* rear;
    int length;

};
int main()
{
    list li;
    default_random_engine e(time(0));
    uniform_int_distribution<int> u(0,200);
    for(int i=20;i!=0;--i)
        li.push_back(u(e));
    li.print();
    cout<<endl;

    li.insert_sort();
    li.print();
    system("pause");
    return 0;
}
