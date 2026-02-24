#include<iostream>
using namespace std;
class List
{
private:
    int *elements; //
    int capacity;
    int last;
public:
    List(int n)
    {
        elements= new int[n];
        capacity = n;
        last = -1;
    }
    ~List() // we do this for any dynamic structure 
    {
        delete [] elements;
    }
    void makeNull() // clear the array O(1)
    {
        last=-1;
    }
    int end() // return the last index
    {
        return last+1;
    }
    void insert(int x,int pos)
    {
         if(end()==pos)
        {
            cout<<"List is full";
            return ;
        }
        else if(pos<0 && pos>end())
        {
            cout<<"Position Invalid , Last Index is:"<<last;
        }else
        {
            for(int i=last;i>=pos;i--)
            {
                elements[i+1] = elements[i];
                last++;
                elements[pos] = x;
            }
        }
    }
    void delete_at(int pos)
    {
        if(pos>last+1 || pos<0)
        {
            cout<<"Out of Range";
        }
    }








};

int main()
{


    return 0;
}