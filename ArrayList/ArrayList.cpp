#include<iostream>
using namespace std;

typedef int ELement;
typedef int Position;

class List
{
private:
    ELement *eLement;
    int capacity;
    Position last;
public:
    List(int n)
    {
        eLement = new ELement[n];
        capacity=n;
        last = -1;
    }
    void make_null()
    {
        last =-1;
    }
    Position end()
    {
        return last+1;
    }
    void insert(ELement x,Position pos)
    {
        if(last == capacity-1)
        {
            cout<<"List is full";
        }else if(pos>last+1 || pos<0)
        {
            cout<<"out of boundaries";
        }else
        {
            for(int i=last ;i>=pos;i--)
            {
                eLement[i+1]=eLement[i];
            }
            last++;
            eLement[pos] = x ;
        }
    }
    void delete_at(Position pos)
    {
        if(pos<0 || pos>last)
        {
            cout<<"pos out of range";
        }else
        {
            for(int i=pos+1;i<=last;i++)
            {
                eLement[i-1]=eLement[i];
            }
            last--;
        }
    }
    Position Locate(ELement x)
    {
       for(int i=0;i<=last;i++)
       {
        if(eLement[i]==x)
        {
            return i;
        }
       }
       return -1;
    }
    Position Locate_in_range(ELement x,Position pos , Position Last_pos)
    {
        for(int i=pos;i<=Last_pos;i++)
        {
            if(eLement[i]==x) return i;
        }
        return -1;
    }
    ELement retrieve(Position pos)
    {
        if(pos>last||pos<0)
        {
            cout<<"out of boundaries";
            return -1;
        }
        return eLement[pos];
    }
    void print_list()
    {
        for(int i=0;i<=last;i++)
        {
            cout<<eLement[i]<<endl;
        }
    }
    Position first()
    {
        return 0;
    }
    Position next(Position pos)
    {
        return pos+1;
    }
    Position previous(Position pos)
    {
        return pos-1;
    }
    int size()
    {
        return last + 1;
    }

};

List reverse(List l1)
{
    List l2(l1.end());
    Position pos=l1.previous(l1.end());
    while(pos != l1.previous(l1.first()))
    {
        l2.insert(l1.retrieve(pos),l2.end());
        pos = l1.previous(pos);
    }
    return l2;
}
List reverse_modified(List l1)
{
    List l2(l1.end());
    Position pos=l1.first();
    while(pos!=l1.end())
    {
        l2.insert(l1.retrieve(pos),l2.first());
        pos=l1.next(pos);
    }
    return l2;
}
void insert_x_after_y(ELement x,ELement y,List &l1)
{
    Position pos=l1.Locate(y);
    if(pos!=l1.end())
    {
        l1.insert(x,l1.next(pos));
    }else
    {
        cout<<"y not found";
    }
}
void purge(List &l)
{
    Position pos=l.first();
    while(pos != l.end())
    {
        Position q=l.next(pos);
        while(q != l.end())
        {
            if(l.retrieve(pos)==l.retrieve(q))
            {
                l.delete_at(q);
            }else
            {
                q = l.next(q);
            }
        }
        pos=l.next(pos);
    }
}
void remove_occurence(List &l,ELement x)
{
    Position pos=l.first();
    while(true)
    {
        pos = l.Locate_in_range(x,pos,l.previous(l.end()));
        if(pos==-1) break;
        else l.delete_at(pos);
    }
}
void split(List l,List &odd,List&even)
{
    Position pos=l.first();
    while(pos!=l.end())
    {
        ELement x=l.retrieve(pos);
        if(x%2==0)
        {
            even.insert(x,even.end());
        }else odd.insert(x,odd.end());
        pos = l.next(pos);
    }
}
List concatenate(List l1, List l2)
{
    List l3(l1.end()+l2.end());
    Position pos=l1.first();
    while(pos != l1.end())
    {
        l3.insert(l1.retrieve(pos),l3.end());
        pos = l1.next(pos);
    }
    pos=l2.first();
    while(pos!=l2.end())
    {
        l3.insert(l2.retrieve(pos),l3.end());
        pos = l2.next(pos);
    }
    return l3;
}
ELement sum(List l)
{
    Position pos =l.first();
    ELement total=0;
    while(pos!=l.end())
    {
        total+=l.retrieve(pos);
        pos = l.next(pos);
    }
    return total;
}
ELement max(List l)
{
    Position pos = l.first();
    ELement x =l.retrieve(l.first());
    while(pos!= l.end())
    {
        if(x<l.retrieve(pos)) x=l.retrieve(pos);
        pos = l.next(pos);
    }
    return x;
}


int main()
{


    return 0;
}





