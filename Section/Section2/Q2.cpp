#include<iostream>
using namespace std;

int count(int *arr,int size)
{
    int count_Even=0;
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]%2==0)
        {
            count_Even++;
        }
    }
    return count_Even;
}


int main()
{
int size;
cin>>size;
int arr[size];
for(int i=0;i<size-1;i++)
{
    cin>>arr[i];
}
for(int i=0;i<size-1;i++)
{

}

cout<<"Even:"<<count(arr,size);
//int *ptr=arr;




    return 0;
}