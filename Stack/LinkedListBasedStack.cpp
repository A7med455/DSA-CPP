#include<iostream>
using namespace std;
typedef int Element;
// LIFO--> Last in First out
//stack is built using nodes 
/* each node consists of 
    1-Value to be stored in the node
    2- pointer(next) points to the next node
*/
/*
   1- Linked List Bases Stack has a dyynamic size 
   2-uses more memory due to pointers in each node
   3-it's efficient in insertion & deletion as pointers only modify the top pointer
   4-no overflow unless the system itself ran out of memeory
*/
/* Basic Operations:
    1-Initialize Stack
    2-Push : add an element to the top of stack
    3-Pop : delete the element at the top of stack
    4-top : return the element at the top of  stack
    5-isEmpty : boolean function , returns true (1) if empty and false(0) if not empty
Attributs of Stack:
    1-Node Data
    2-Node Pointer
    3-StackTop
    4-Initialize the Stack
*/

struct Node
{
    Element Data;
    Node* next;   

    //constructor 
    Node(Element value)
    {
        Data=value;
        next = nullptr;
    }
};
class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top=nullptr;
    }
    bool isEmpty() //O(1)
    {
    /*
        if(top==nullptr)
        {
            cout<<"Stack Underflow"<<endl;
            return true;
        }
        else
        {
            return false;
        }
    */
        return top == nullptr;
    }

    void push(Element value) //O(1)
    {
        Node* newnode = new Node(value);
        newnode->next = top;
        top = newnode;
        cout<<"Pushed:"<<value<<endl;
    }
    
    void pop() //O(1)
    {
        if(isEmpty())
        {
            cout<<"Stack is empty, cannot pop"<<endl;
            return;
        }

        Node* temp=top;
        top = top->next;
        cout<<"Popped:"<<temp->Data<<endl;
        delete temp;
    }

    void peek() //O(1)
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return;
        }

        cout<<"Top Element:"<<top->Data<<endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    s.pop();
    s.pop(); // this one to try the condition is empty 
}



