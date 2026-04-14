#include<iostream>
using namespace std;

class Stack
{
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) // Initialized an empty Stack
    {
        capacity=size;
        top= -1; // start with -1 bec no elements yet
        arr=new int[capacity];
    }
    ~Stack()
    {
        delete[] arr;
        cout<<"Stack is Destroyed "<<endl;
    }
    void push(int newItem)
    {
        if(top== capacity-1) //is full or not 
        {
            cout<<"Stack OverFlow!"<<endl;
            return;
        }
        top++;
        arr[top]=newItem;
        cout<<"Pushed:"<<newItem<<endl;
    }

    int pop()
    {
        if(top<0) // means stack is empty
        {
            cout<<"Stack UnderFlow! "<<endl;
            return -1;
        }
        int poppedValue = arr[top];
        top--; 
        return poppedValue;
    }
    int peek()
    {
        if(top==-1) //check if empty or not
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return arr[top];
    }

};

int main()
{
    



    return 0;
}