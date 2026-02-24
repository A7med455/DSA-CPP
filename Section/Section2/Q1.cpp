#include<iostream>
using namespace std;
void swap(int *ptr , int *ptr2)
{
    int temp;
   temp=*ptr;
    *ptr=*ptr2;
    *ptr2=temp;
}

int main()
{
  int x,y;
  cin>>x>>y;
  swap(&x,&y);
  cout<<x<<endl<<y;



    return 0;
}