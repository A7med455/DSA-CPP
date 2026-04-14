/*
Queue is a linear data strucutre
Queue == FIFO (First in First Out)
first element added will be 
    .first to be processed or removed
Ex: line of people 

Basics for Queue:
    1-Front: Postition of element ready to be served or removed
        known as the head of the queue
    2-Rear: Postition of the last element in queue 
        known to as the tail of the queue
    3-Size: Maximum number of elements the queue can hold

Queue Basic Operations
    1-initialize Queue
    2-isEmptyQueue: Check if empty or not
    3-isFullQueue: check if full or not 
    4-Front: returns front element(First element)
    5-Back: returns last element of the queue
    6-Enqueue: adds a new element to the rear of the queue
            .queue must exist and not full
    7-Dequeue: removes the front element from the queue
            .queue must exist and not empty

Attributes of Array Based Queue
    1-Front Pointer
    2-Rear Pointer
    3-Size
    4-Initialize the stack
*/
#include<iostream>
using namespace std;
typedef int ElementType;

class Queue
{
private:

    ElementType front;
    ElementType rear;
    ElementType capacity;
    ElementType* arr;

public:

    Queue(ElementType size)
    {
        arr = new ElementType[size];
        capacity = size;
        front = -1;
        rear = -1;
    }

    ~Queue()
    {
        delete[] arr;
        cout<<"Queue is Destroyed"<<endl;
    }

    bool isFull()//O(1)
    {
        return rear == capacity-1;
    }

    bool isEmpty() //O(1)
    {
        return rear == -1;
    }

    void reset()
    {
        front = -1;
        rear = -1;
    }

    void Enqueue(ElementType x) //O(1)
    {
        if(isFull()) // means Queue is full
        {
            return;
        }
        if(front == -1)
              front = 0;

        rear++;
        arr[rear]=x;
        cout<<"Inserted: "<<x<<endl;
    }
    
    int Dequeue() // O(1)
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        ElementType element= arr[front];
        
        if(front == rear)
        {
            reset();   
        }else
        {
            front++;
        }

        cout<<"Dequeued: "<<element<<endl;
        return element;
    }

    ElementType peekFront() //O(1)
    {
        if(isEmpty())
        {
            return -1;
        }
        ElementType value=arr[front];
        cout<<"Front Element:"<<value<<endl;
        return value;
    }

    ElementType peekRear() //O(1)
    {
        if(isEmpty())
        {
            return -1;
        }
        ElementType value=arr[rear];
        cout<<"Rear Element: "<<value<<endl;
        return value;
    }




};

int main()
{
    Queue q(5);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.Enqueue(60);//should trigger queue is full message

    q.peekRear();
    q.peekFront();

    q.Dequeue();
    q.Dequeue();

    q.peekFront();
    q.peekRear();

    cout<<"Is the Queue Empty?"<<(q.isEmpty() ? "Yes":"No") <<endl;
    cout<<"Is the Queue Full?"<<(q.isFull() ? "Yes":"No")<<endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    q.Dequeue();//should trigger Queue is empty message

    return 0;
}
