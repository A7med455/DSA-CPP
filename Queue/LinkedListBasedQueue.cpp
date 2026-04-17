/*
Linked List Queue:
    FIFO: First in First out
Node:
    Data: Value stored in the node
    Next: pointer to the next node


*/

#include<iostream>
using namespace std;
typedef int ElementType;

struct Node
{
    ElementType data;
    Node* next;
    
    Node(ElementType value)
    {
        data=value;
        next=nullptr;
    }
};
class Queue
{
private:

    Node* front;
    Node* rear;

public:

    Queue()
    {
        front=nullptr;
        rear=nullptr;
    }
    bool isEmpty() // O(1)
    {
        return front == nullptr;
    }
    void enqueue(ElementType value) // O(1)
    {
        Node* newnode= new Node(value);
        if(rear == nullptr)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        cout<<"Enqueued:"<<value<<endl;
    }

    void dequeue() // O(1)
    {
        if(isEmpty())
        {
            cout<<"Queue is empty. Cannot Dequeue"<<endl;
            return;
        }

        Node* temp=front;
        front = front->next;
        if(front == nullptr) // check if the Queue became empty after dequeuing or not 
        {
            rear = nullptr;
        }
        cout<<"Dequeued: "<<temp->data<<endl;
        delete temp;
    }

    void peek() // O(1)
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        else
        {
            cout<<"Front element: "<<front->data<<endl;
        }
    }

    void display() // O(n)
    {
        if(isEmpty())
        {
             cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout<<"Queue: ";
        while(temp != nullptr)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // triggers isEmpty function

    return 0;
}


