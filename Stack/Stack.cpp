#include<iostream>
using namespace std;

class Stack
{
private:

    int* arr;
    int top;
    int capacity;
    int counter;

public:
    Stack(int size) // Initialized an empty Stack
    {
        capacity = size;
        top = -1; // start with -1 bec no elements yet
        arr = new int[capacity];
        counter = 0;
    }
    ~Stack()
    {
        delete[] arr;
        cout<<"Stack is Destroyed "<<endl;
    }

     bool isEmpty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
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
        counter++;
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
        counter--;
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

Stack reverse(Stack s1,int size)
{
    Stack s2(size);
    while(!s1.isEmpty())
    {  
        s2.push(s1.pop());
    }
    return s2;
}
  

Stack merge(Stack s1,Stack s2,int size1,int size2)
{
    Stack s3(size1 + size2);

    while(!s1.isEmpty())
    {
        s3.push(s1.pop());
    }
    while(!s2.isEmpty())
    {
        s3.push(s2.pop());
    }
    
    Stack s4(size1 + size2);

    while(!s3.isEmpty())
    {
        s4.push(s3.pop());
    }
    return s4;
}

int main()
{
    
Stack s1(5);
s1.push(10);
s1.push(20);
s1.push(30);
s1.push(40);
s1.push(50);
Stack s2(5);

s2=reverse(s1,5);


    return 0;
}