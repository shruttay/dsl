#include<iostream>
using namespace std;

void linear()
{
    int n, i, key;
    cout<<"Enter the Total Number of Students : ";
    cin>>n;
    int list[n];
    for (i=0; i<n; i++)
    {
        cout<<"Enter Element : ";
        cin>>list[i];
    }
    cout<<"Enter the Searching Element : ";
    cin>>key;
    for (i=0; i<n; i++)
    {
        if(list[i]==key)
        {
            cout<<"Key is Present";
            break;
        }
    }
    if(i==n)
        cout<<"Key is Absent";
}

void binary()
{
    int i, n, key;
    cout<<"Enter the Total Number of Students : ";
    cin>>n;
    int list[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter Element";
        cin>>list[i];
    }
    cout<<"Enter the Searching Element";
    cin>>key;
    int low=0;
    int high=(n-1);
    int mid=(low+high)/2;
    while (low<=high && list[mid]!=key)
    {
        if(list[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        mid=(low+high)/2;
    }
    if(low>high)
    {
        cout<<"Key is Absent";
    }
    else
    {
        cout<<"Key is Present";
    }
}

int main()
{
    int ch;
    cout<<"\n1 : Use linear Search";
    cout<<"\n2 : Use Binary Search";
    cout<<"\nEnter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            linear();
            break;
        case 2:
            binary();
            break;
    }
    return 0;
}