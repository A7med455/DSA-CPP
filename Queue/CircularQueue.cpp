#include<iostream>
using namespace std;
typedef int ElementType;

class Queue
{
private:

    int rear;
    int front;
    int max_size;
    int counter;
    ElementType* arr;

public:

    Queue(ElementType size)
    {
        max_size = size;
        arr = new ElementType[max_size];
        rear = -1;
        front = -1;
        counter = 0;
    }

    bool isFull()
    {
        return counter == max_size;
    }

    bool isEmpty()
    {
        return counter == 0;
    }

    int size()
    {
        return counter;
    }
    void enqueue(ElementType x)
    {
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        if(isEmpty)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % max_size;
        }

        arr[rear] = x;
        counter++;
    }

    ElementType dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -999;
        }

        ElementType temp = arr[front];

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % max_size;
        }

        counter--;
        return temp;
    }

};

int main()
{




    return 0;
}
