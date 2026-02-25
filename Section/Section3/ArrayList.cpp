#include<iostream>
using namespace std;
class List
{
private:
    int *elements; 
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
        if(last==capacity-1) // check if full or not 
        {
            cout<<"List is full";
            return ;
        }
        else if(pos > last + 1|| pos<0) // out of range or not 
        {
            cout<<pos<<"Position out of range";
            return ;
        }else
        {
            for(int i = last ;i>=pos;i--)
            {
                elements[i+1] = elements[i];
            }
            //insert the new element
            elements[pos]=x;
            last++; //update the last index to the new one 
        }
   }

   void delete_at(int pos)
   {
        if(pos>last || pos<0)
        {
            cout<<"Position out of range";
        }
        for(int i = pos + 1 ;i<=last;i++) // start from the element after the position 
        {
            elements[i-1]=elements[i]; //shifting towards leftside 
        }
        last--; // change last index to the new one 
   }

   int locate(int x)
   {
        for(int i=0;i<=last;i++)
        {
            if(x==elements[i])
            {
                return  i;
            }
        }
        return -1;
   }

   int locate_in_range(int x,int pos,int last)
   {
        if(pos<0 || pos>last)
        {
            return -1; //out of range
        }
        for(int i=pos;i<=last;i++)
        {
            if(x==elements[i])
            {
                return i;
            }
        }
        return -1;
   }

   int retrieve(int pos)
   {
        if(pos<0 || pos>last)
        {
            return -1; //out of range
        }
        return elements[pos];
   }

   void print_list()
   {
        for(int i=0;i<=last;i++)
        {
            cout<<elements[i]<<"-"<<endl;
        }
   }

   int Position_first()
   {
        if(last==-1)
        {
            return -1;
        }
        return 0;
   }

   int Position_next(int pos)
   {
        if(pos<0||pos>=last)
        {
            return -1;
        }
        return pos+1;
   }

   int Position_previous(int pos)
   {
        if(pos<=0||pos>last)
        {
            return -1;
        }
        return pos-1;
   }

   int size()
   {
        return last+1;
   }

   //list reverse function
   List reverse(List l1) //O(n)
   {
        List l2(l1.size()); // create new list with same capacity as L1
        int pos = l1.size()-1; // start from last valid index

        while(pos>=0)
        {
            l2.insert(l1.retrieve(pos) , l2.end());
            //pos=l1.Position_previous(pos);
            pos--;//another way 
        }
        return l2;
   }

   List reverse_modified(List l1) //O(n^2)
   {
        List l2(l1.size());
        int pos = l1.Position_first();
        while(pos!=l1.end())
        {
            l2.insert(l1.retrieve(pos),l2.Position_first());
            //pos=l1.Position_next();
            pos++;
        }
        return l2;
   }

   void insert_x_after_y(int x,int y,List &l) //O(n)
   {
        int pos = l.locate(y);
        if(pos!=-1)
        {
            l.insert(x,l.Position_next(pos));
        }
        else
        {
            cout<<"Y not found"<<endl;
        }
   }

   void purge(List &l)
   {
        int pos=l.Position_first();
        while(pos!=l.end())
        {
            int q=l.Position_next(pos); //start checking elements after pos
            while(q!=l.end())
            {
                if(l.retrieve(pos) == l.retrieve(q)) //duplicate found
                {
                    l.delete_at(q); // remove it 
                }
                else
                {
                    //q = l.Position_next(q);
                    q++; // move forward 
                }
                pos = l.Position_next(pos); //move to next element 
            }
        }
   }

  /*
  1)void remove_occurrences...later
  2)void split...later
  3)List concatenate...later
  4)ElmenetType sum...later
  5)ElmenetType max...later
  */
};

int main()
{


    return 0;
}