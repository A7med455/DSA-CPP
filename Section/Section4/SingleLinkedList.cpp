#include<iostream>
using namespace std;

typedef int ElementType;

struct node
{
   ElementType element; 
   node* next;
};

typedef node* Position;

class List{

private:
    node* head; //points to the dummy node
    node* tail; // points to the last real node
    int counter;
public:

    List()
    {
        make_null();
    }

    void make_null()
    {
        head = new node;
        head->next = NULL;
        tail = head;
        counter = 0;
    } 

    Position end()
    {
        return tail;
    }

    void insert(ElementType x,Position p = NULL)
    {
        if(p==NULL)
        {
            p=end();
        }
        Position new_node= new node;
        new_node->element = x;
        new_node->next = p->next;
        p->next = new_node;
        if(new_node->next == NULL)
        {
            tail= new_node;
        }
        counter++;
    }

    void delete_after_pos(Position p)
    {
        if(p==end() || p==NULL)
        {
            cout<<"No element to be deleted";
            return ;
        }
        Position temp = p->next;
        p->next = p->next->next;
        if(p->next == NULL)
        {
            tail = p;
        }
        temp->next = NULL;
        delete temp;
        counter--;
    }

    Position Locate_before_X(ElementType x)
    {
        Position p = head;
        while(p->next != NULL)
        {
            if(p->next->element == x)
            {
                return p;
            }
            p = p->next;
        }
        return p; // if not found return p of the dummy node
    }

    Position Locate_in_range(ElementType x,Position pos,Position end_pos)
    {
        Position p = pos;
        while(p->next != end_pos && p->next != NULL)
        {
            if(p->next->element == x)
            {
                return p;
            }
            p = p->next;
        }
        return p; // if not found 
    }

    ElementType retrieve_after_p(Position pos)
    {
        if(pos == tail || pos == NULL)
        {
            cout<<"No element to retrieve";
            return 0;
        }
        return pos->next->element;
    }

    void print_list()
    {
        cout<<"List is: ";
        Position p = head->next;
        while(p != NULL)
        {
            cout<<p->element<<" ";
            p = p->next;
        }
        cout<<endl;
    }

    Position first()
    {
        return head; // return dummy 
    }

    Position next(Position pos)
    {
        if(pos == tail)
        {
            return NULL;
        }
        return pos->next;
    }

    Position previous(Position pos)
    {
        if(pos == head)
        {
            return head;
        }
        Position q=head;
        while(q != NULL && q->next != pos)
        {
            q = q->next;
        }
        return q;
    }

    int size()
    {
        return counter;
    }
};
    List reverse(List l1)
    {
        List l2;
        Position pos = l1.previous(l1.end());
        while(pos != l1.first())
        {
           int x = l1.retrieve_after_p(pos);
           l2.insert(x,l2.end());
           pos = l1.previous(pos); 
        }
        l2.insert(l1.retrieve_after_p(l1.first()),l2.end());
        return l2;
    }
    
    List reverse_modified(List l1)
    {
        List l2;
        Position pos = l1.first();
        while(pos != l1.end())
        {
            int x = l1.retrieve_after_p(pos);
            l2.insert(x,l2.first());
            pos = l1.next(pos);
        }
        return l2;
    }

    void insert_x_after_y(ElementType x,ElementType y,List &l)
    {
        l.insert(x,l.next(l.Locate_before_X(y)));
    }

    void purge(List &l)
    {
        Position pos = l.first();
        while(pos != l.end())
        {
            Position q = l.next(pos);
            while(q != l.end())
            {
                if(l.retrieve_after_p(pos) == l.retrieve_after_p(q))
                {
                    l.delete_after_pos(q);
                }
                else
                {
                    q = l.next(q);
                }
            }
            pos = l.next(pos);
        }
    }

    void remove_occurrences(List &l , int x)
    {
        Position pos = l.first();
        while(1)
        {
            pos = l.Locate_in_range(x,pos,l.previous(l.end()));
            if(pos == l.end())
                break;
            else
                l.delete_after_pos(pos);
        }
    }
    
    void split(List L,List &odd,List &even)
    {
        Position curr = L.first();
        while(curr != L.end())
        {
            int x = L.retrieve_after_p(curr);
            if(x%2==0)//even 
                even.insert(x,even.end());
            else // odd
                odd.insert(x,odd.end());
            curr = L.next(curr);
        }
    }

    List concatenate(List l1, List l2)
    {
        List l3;
        Position curr = l1.first();
        while(curr != l1.end())
        {
            l3.insert(l1.retrieve_after_p(curr),l3.end());
            curr = l1.next(curr);
        }
        curr = l2.first();
        while(curr != l2.end())
        {
            l3.insert(l2.retrieve_after_p(curr),l3.end());
            curr = l2.next(curr);
        }
        return l3;
    }

    ElementType sum(List l)
    {
        Position curr = l.first();
        ElementType total=0;
        while(curr != l.end())
        {
            total += l.retrieve_after_p(curr);
            curr = l.next(curr);
        }
        return total;
    }

    ElementType max_val(List l)
    {
        Position curr = l.first();
        ElementType x = l.retrieve_after_p(l.first());
        while(curr != l.end())
        {
            if(x < l.retrieve_after_p(curr))
                x = l.retrieve_after_p(curr);
                curr = l.next(curr);
        }
        return x;
    }

    List sort(List l)
    {
        List new_list;
        while(l.size() != 0 )
        {
            ElementType x = max_val(l);
            new_list.insert(x,new_list.first());
            l.delete_after_pos(l.Locate_before_X(x));
        }
        return new_list;
    }

    double average(List l)
    {
        if(l.size() == 0) //list is empty
            return 0;
        double avg = 0;
        Position curr = l.first();
        while(curr != l.end())
        {
            avg += l.retrieve_after_p(curr);
            curr = l.next(curr);
        }
        return avg/l.size();
    }

int main()
{
    //Task 1: Build a List
    cout<<"Task 1:"<<endl;
    List l;
    l.insert(10,l.end());
    l.insert(20,l.end());
    l.insert(30,l.end());
    l.insert(40,l.end());
    l.insert(50,l.end());
    l.print_list();

    // Task 2: Delete & Locate
    cout<<"Task 2:"<<endl;
    Position pos = l.Locate_before_X(10);
    cout << "Locate pos value in the List: " << l.retrieve_after_p(pos) << endl; 
    l.delete_after_pos(pos); // delte 10 from the list
    l.print_list();
    l.delete_after_pos(l.first()); //delete first element
    l.print_list();

    //Task 3: Insert After a Value
    cout<<"Task 3:"<<endl;
    List l3;
    for(int i=0;i<=5;i++)
    {
        l3.insert(i,l3.end());
    }
    l3.print_list();
    insert_x_after_y(99,3,l3);
    l3.print_list();
    insert_x_after_y(77, 5, l3);
    l3.print_list();          
    insert_x_after_y(88, 1, l3);
    l3.print_list(); 

    //Task 4: Purge Duplicates
    cout<<"Task 4:"<<endl;
    List l4;
    int val[] = {3, 5, 6, 5 ,4 ,2};
    for(int i=0;i<6;i++)
    {
        l4.insert(val[i],l4.end());
   }
   l4.print_list();
   purge(l4);
   l4.print_list();

   //Task 5: Build and Print
   cout<<"Task 5:"<<endl;
   List l5;
   int val2[] = {10,20,30,40,50};
   for(int i=0;i<5;i++)
   {
    l5.insert(val2[i],l5.end());
   }
   l5.print_list();
   l5.insert(99,l5.first());
   l5.print_list();
   cout<<"Size: "<<l5.size()<<endl;

   //Task 6: get average 
   List l6;
   int val3[] = {10,20,30,40};
   for(int i=0;i<4;i++)
   {
    l6.insert(val3[i],l6.end());
   }
   cout<<"Average of the List: "<<average(l6)<<endl;

   //Task 7: Reverse and compare
   List l7;
   for(int i=0;i<=5;i++)
   {
    l7.insert(i,l7.end());
   }
   l7.print_list();
   List r1 = reverse(l7);
   r1.print_list();
   List r2 = reverse_modified(l7);
   r2.print_list();

   //Task 8: Split & Concatenate
   cout<<"Task 8:"<<endl;
   List l8;
   for(int i=0;i<10;i++)
   {
    l8.insert(i,l8.end());
   }
   l8.print_list();
   List even,odd;
   split(l8,odd,even);
   cout<<"Even: ";
   even.print_list();
   cout<<"Odd:";
   odd.print_list();
   List merged = concatenate(even,odd);
   cout<<"Concatenated List:";
   merged.print_list();

   //Task 9: Sort the List (will use merged list from the previous task(8))
   cout<<"Task 9:"<<endl;
   List sorted = sort(merged);
   cout<<"Sorted List:";
   sorted.print_list();

   //Task 10: Remove Occurrences & Purge
   cout<<"Task 10:"<<endl;
   List l9;
   int val4[] = {5, 3, 4, 3, 5, 4, 3, 5};
   for(int i=0;i<8;i++)
   {
    l9.insert(val4[i],l9.end());
   }
   l9.print_list();
   remove_occurrences(l9,3);
   l9.print_list();

   purge(l9);
   cout<<"Purge:";
   l9.print_list();

    return 0;
}