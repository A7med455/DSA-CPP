#include<iostream>
using namespace std;

typedef int ElmenetType;
struct node{
	ElmenetType element;
	node* next; 
	node* prev; 
};
typedef node* Position;
//Very important note, position p always points to the previous node to the current node to be processed  
class List{
	public:
		node* head;//points to the first dummy node
		node* tail;//points to the last node
		int counter;
	public:
		//this code doesn't create dummy node for efficiently insertion and deleteion
		List(){
			MakeNull();
		}
		void MakeNull(){
			head=NULL; 
			tail=NULL;
			counter=0;
		}
	//returns a pointer to the last node of L
	Position END(){
		return NULL;// tail->next;
	}
	Position end(){
		return tail;
	}
	void InsertAtEnd(ElmenetType x){
			Position newNode=new node;
			newNode->element=x;
			newNode->prev=tail;
			newNode->next=NULL;
			if(tail!=NULL)
				tail->next=newNode;
			tail=newNode;
			if (head==NULL)head=tail;
			counter++;
	}
	void InsertAtStart(ElmenetType x){ 
		Position newNode=new node;
		newNode->element=x;
		newNode->prev=NULL;
		newNode->next=head;
		if(head!=NULL)
			head->prev=newNode;
		head=newNode;
		if (tail==NULL)tail=head;
		counter++;
	}
	//	INSERT(x, p, L). Insert x at position p in list L,  If list L has no position p, the result is undefined.
	void Insert(ElmenetType x,Position p=NULL){
		if(p==NULL){
			InsertAtEnd(x);
		}
		else if(p==head){  //p!=NULL
			InsertAtStart(x);
		}
		else	
			{
				Position newNode=new node;
				newNode->element=x;
				newNode->next=p;
				newNode->prev=p->prev;
				p->prev->next=newNode;
				p->prev=newNode;
				counter++;
			}		
	} 
//	Delete the element at position p of list L. If L is a0, a1, a2, . . . ,an-1, then L becomes a0, a1, a2, . . . ,ap- 1, ap+1, . . . ,an-1. The result is undefined if L has no position p or if p = END(L). 
	void Delete(Position p)
	{
		if(p==NULL){
			cout<<"No Element to be deleted";
			return;
		}
		if(p==tail)
			tail=p->prev;
		Position tmp=p;
		if(p->prev!=NULL)
			p->prev->next=p->next;
		if (p->next!=NULL)
			p->next->prev=p->prev;
		p->next=NULL;
		p->prev=NULL;
		delete tmp;
		counter--;
		if(counter==0)
			head=tail=NULL;
	}
 //returns the position of x on list L. If x appears more than once, then the position of the first occurrence is returned. If x does not appear at all, then END(L) is returned.
	Position Locate(ElmenetType x){
		Position p=head;
		while(p!=NULL){
			if(p->element==x)
				return p;
			 p=p->next;
		} 
		return p; //equivalent to return END();	
	}
	//locate x in the range pos to endPos
	Position LocateInRange(ElmenetType x,Position pos,Position endPos)
		{
			Position p=pos;
			while(p!=endPos){
				if(p->element==x)
					return p;
				p=p->next;
			} 
		return NULL; //equivalent to return END();	
		}

	//This function returns the element at position p on list L. The result is undefined if p = END(L) or if L has no position p. Note that the elements must be of a type that can be returned by a function if RETRIEVE is used. In practice, however, we can always modify RETRIEVE to return a pointer to an object of type elementtype. 
	ElmenetType Retrieve(Position pos){
		if (pos==NULL){
			cout<<"ERROR in reterive";
			return NULL;
		}
		return pos->element;
	}

	void PrintList(){
		if(head==NULL){
			cout<<"List is Empty";
			return;
		}

		cout<<"List is:";
		Position p=head;
		while(p!=NULL){ 
			cout<<p->element<<" ";
			p=p->next;
		}
		cout<<endl;
	}
	//This function returns the first position on list L. If L is empty, the position returned is END(L
	Position First()
		{
			return head;
		}
	// return the positions following and preceding position p on list L. If p is the last position on L, then NEXT(p, L) = END(L). NEXT is undefined if p is END(L). PREVIOUS is undefined if p is 0. Both functions are undefined if L has no position p.
	Position Next(Position pos){//you must write constrains here
		if(pos==NULL)return NULL;
		return pos->next;}
	Position Previous(Position pos){//you must write constrains here
		if(pos==NULL)return NULL;
		return pos->prev;
	}

	int Size()
	{
		return counter;
	}
};
//reverses list.
List Reverse(List l1)
{
	List l2;
	Position pos=l1.end();
	while (pos!=NULL)
	{
		int x=l1.Retrieve(pos); 
		l2.Insert(x,l2.END()); 
		pos=l1.Previous(pos);
	}
	return l2;
}
List ReverseModified(List l1)
{
	List l2;
	Position pos=l1.First();
	while (pos!=l1.END())
	{
		int x=l1.Retrieve(pos); 
		l2.Insert(x,l2.First());
		pos=l1.Next(pos);
	}
	return l2;
}
//inserts a given value x after the value y in the list. If y doesn't exist in the list, add x at the end of the list.
void InsertXAfterY(ElmenetType x, ElmenetType y, List &l)
{
	l.Insert(x,l.Next(l.Locate(y)));
}
//eliminates duplicates from list.
void Purge ( List &L)
{//PURGE removes duplicate elements from list L 
	Position p, q; 
    p = L.First();
	while (p!=NULL ) {
		q = L.Next(p);
		while (q !=NULL){
			if (L.Retrieve(p)== L.Retrieve(q)) {
				Position tmp=q;
				L.Delete(tmp);
			}
            else
            {
                q = L.Next(q);
            }
		} 
		p = L.Next(p);
	}
}

int max(List L){

	
	int m=L.Retrieve(L.First());
	Position p=L.Next(L.First());
	while(p!=L.END()){
		int curr=L.Retrieve(p);
		if(curr>m)
			m=curr;
		p=L.Next(p);
	}
	return m;
}





void RemoveOccurences1(List&L,int x)
{
	Position pos=L.First();
	while(pos!=L.END())
	{
			//if(pos==NULL)break;
		    pos=L.LocateInRange(x,pos,L.END());
			if (pos==NULL)
				break;
			else{
				Position q=pos;
				pos=L.Next(pos);
				L.Delete(q);
			}
	}
}
//splits the linked to two lists, one for odd numbers and one for even numbers
void Split(List L,List& lEven ,List& lOdd)
{
	Position curr=L.First();
	while(curr!=L.END())
	//while(curr!=NULL)
	{
		int x=L.Retrieve(curr);
		if (x%2==0)
			lEven.Insert(x);
		else
			lOdd.Insert(x);

		curr=L.Next(curr);
	}
}
// concatenates two lists.
List concatenate(List l1,List l2)
{
	List l;
	Position curr=l1.First();
	while(curr!=l1.END())
	//while(curr!=NULL)
	{
		ElmenetType x=l1.Retrieve(curr);
		l.Insert(x); 
		curr=l1.Next(curr);
	}
	curr=l2.First();
	while(curr!=l2.END())
	{
		ElmenetType x=l2.Retrieve(curr);
		l.Insert(x); 
		curr=l2.Next(curr);
	}
	return l;
}
 //calculates the summation of all values in the list.
ElmenetType Sum(List L)
{
	Position curr=L.First();
	ElmenetType s=0;
	while(curr!=L.END())
	{
		ElmenetType x=L.Retrieve(curr);
		s+=x;
		curr=L.Next(curr);
	}
	return s;
}

void swap(List &l, ElmenetType x, ElmenetType y)
{
    if(x==y)
    {
        return;
    }
    Position currX=l.Locate(x);
    Position currY=l.Locate(y);

    if(currX==NULL || currY==NULL)
    {
        cout<<"one or both values not found"<<endl;
        return;
    }

    Position prevX=currX->prev;
    Position prevY=currY->prev;
    Position nextX=currX->next;
    Position nextY=currY->next;

    if(prevX!=NULL)
    {
        prevX->next=currY;
    }else
    {
        l.head=currY;
    }
    if(prevY!=NULL)
    {
        prevY->next=currX;
    }else
    {
        l.head=currX;
    }
    currX->prev=prevY;
    currY->prev=prevX;

    currX->next=nextY;
    currY->next=nextX;
    if(nextX!=NULL)
    {
        nextX->prev=currY;
    }else
    {
        l.tail=currY;
    }
    if(nextY!=NULL)
    {
        nextY->prev=currX;
    }else
    {
        l.tail=currX;
    }
}
/*
List sort(List L){
	int size=L.Size();
	List newL;
	int counter=1;
	while(counter<=size)
	{
		int m=max(L);
		newL.Insert(m,newL.First());
		L.Delete(L.Locate(m));
		L.PrintList();
		counter++;
	}
	return newL;
}*/

void main()
{
	//List bigL;
	//for(int i=0;i<10000;i++)
	//	bigL.Insert(i,bigL.First());
	//bigL.PrintList();


	List l ;
	//l.InsertAtStart(1);
	//l.InsertAtStart(2);
//	l.InsertAtStart(3);
	//l.InsertAtStart(4);
	//l.PrintList();
    cout<<"sum "<<Sum(l)<<endl;


	//List l ;
	//------------------Test Insert---------------------
	l.InsertAtStart(1);
	l.InsertAtStart(2);
	l.InsertAtStart(3);
	l.InsertAtStart(4);
	l.Insert(10);
	l.Insert(-90,l.First());
	l.Insert(100);
	l.Insert(400);
	l.Insert(-200,l.First());
	l.Insert(534,NULL);
	l.PrintList();
	int m=max(l);
	cout<<"max="<<m;
	cout<<"\n*************\n";
	cout<<l.Size();
	//List L2=sort(l);
	//L2.PrintList();



	List ll;
	ll.InsertAtEnd(5);
	ll.InsertAtEnd(4);
	ll.InsertAtEnd(3);
	ll.InsertAtEnd(2);
	ll.PrintList();

	//----------------Split
	List lEven,lOdd;
	Split(l,lEven,lOdd);
	cout<<"all:";
	l.PrintList();
	cout<<"Even:";
	lEven.PrintList();
	cout<<"Odd:";
	lOdd.PrintList();
	
	List newL=concatenate(lEven,lOdd);
	cout<<"Concatenated List is:";
	newL.PrintList();
	//-------------------Test locate------------------
	ElmenetType x=2;
	Position pos=l.Locate(x);
	if (pos==l.END())
		cout<<x<<" does not exist"<<endl;
	else
		cout<<x<<" found at "<<pos<<endl;
	x=4;
    pos=l.Locate(x);
	if (pos==l.END())
		cout<<x<<" does not exist"<<endl;
	else
		cout<<x<<" found at "<<pos<<endl;
	x=100;
    pos=l.Locate(x);
	if (pos==l.END())
		cout<<x<<" does not exist"<<endl;
	else
		cout<<x<<" found at "<<pos<<endl;

	
	//-------------------End locate------------------
	//---------------------insert X after Y----------------
	l.PrintList();
	cout<<l.END()<<endl;
	InsertXAfterY(66,1,l); 
	cout<<l.END()<<endl;
	l.PrintList();
	//----------------------------------------------------------
	//----------------------reverse--------------
	List l2=ReverseModified(l);
	cout<<"List after reverse:";
	l2.PrintList();
	//-----------------------------------------
	//---------------Purge----------------
	List L3;
	L3.Insert(4,L3.First());
	L3.Insert(5,L3.First());
	L3.Insert(4,L3.First());
	L3.Insert(5,L3.First());
	L3.Insert(4,L3.First());
	L3.Insert(3,L3.First());
	L3.Insert(4,L3.First());
	L3.Insert(3,L3.First());
	L3.Insert(5,L3.First());
	L3.Insert(3,L3.First());
	L3.Insert(5,L3.First());

	cout<<"\nList before removing all 3: ";
	L3.PrintList();
	RemoveOccurences1(L3,3);
	cout<<"\nList afer removing 3:   ";
	L3.PrintList();
	//RemoveOccurences1(L3,4);
	//cout<<"\nList afer removing 4:   ";
	//L3.PrintList();
	//RemoveOccurences1(L3,5);
	//cout<<"\nList afer removing 5:   ";
	//L3.PrintList();


	cout<<"\nList before purge:   ";
	L3.PrintList();
	Purge(L3);
	cout<<"\nList after purge:   ";
	L3.PrintList();
	//--------------------------------------------------
	cout<<"#elements in list is "<< L3.Size()<<endl;
	cout<<"sum "<<Sum(L3)<<endl;

	

	system("pause");
} 