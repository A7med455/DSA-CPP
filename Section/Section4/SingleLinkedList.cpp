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
            return ;
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

    








int main()
{




    return 0;
}