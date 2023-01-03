#include <iostream>
#include <string>
using namespace std;

class sll
{
    private:
        struct node
        {
            string name;
            int PRN;
            node *next;
        }*start;
    public:
        sll()
        {
            start=NULL;
        }
        void create();
        void insert_begin(); 
        void insert_end();
        void insert_pos();
        void display();
        void del_begin();
        void del_end();
        void del_pos();
        void count();
        void concatanate(node*a, node *b);
        void getstart();
};

void sll::create()
{
    node *curr, *temp;
    int ans;
    do
    {
        temp=new node;
        temp->next=NULL;
        cout<<"Enter Name : ";
        cin>>temp->name;
        cout<<"Enter PRN : ";
        cin>>temp->PRN;
        if(start==NULL)
        {
            start=temp;
            curr=temp;
        }
        else
        {
            curr->next=temp;
            curr=curr->next;
        }
        cout<<"To add more press 1"<<endl;
        cin>>ans;
    }while(ans==1);
}

void sll::insert_begin()
{
    node *temp;
    temp = new node;
    temp->next=NULL;
    cout<<"Enter Name : ";
    cin>>temp->name;
    cout<<"Enter PRN : ";
    cin>>temp->PRN;
    temp->next=start;
    start=temp;
}

void sll::insert_end()
{
    node *temp;
    temp=new node;
    temp->next=NULL;
    cout<<"Enter Secretary Name : ";
    cin>>temp->name;
    cout<<"Enter Secretary PRN : ";
    cin>>temp->PRN;
    node *t=start;
    while (t->next!=NULL)
    {
        t=t->next;
    }
    t->next=temp;
}

void sll::insert_pos()
{
    node *temp;
    temp=new node;
    temp->next=NULL;
    cout<<"Enter Secretary Name : ";
    cin>>temp->name;
    cout<<"Enter Secretary PRN : ";
    cin>>temp->PRN;
    node *t=start;
    int pos;
    cout<<"Enter the Position where the member is to be inserted : ";
    cin>>pos;
    for (int i=1; i<=pos-1; i++)
    {
        t=t->next;
    }
    temp->next=t->next;
    t->next=temp;
}

void sll::display()
{
    if(start==NULL)
    {
        cout<<"Linked List is Empty";
    }
    else
    {
        node *t=start;
        while(t->next!=NULL)
        {
            cout<<"Name : "<<t->name<<"PRN : "<<t->PRN<<"-->";
        }
        cout<<"NULL";
    }
}

void sll::del_begin()
{
    node *t=start;
    start=start->next;
    cout<<t->name<<"'s data has been deleted";
    delete t;
}

void sll::del_end()
{
    node *t=start;
    node *back=start;
    while(t->next!=NULL)
    {
        back=t;
        t=t->next;
    }
    cout<<t->name<<"'s data has been deleted";
    delete t;
    back->next=NULL;
}

void sll::del_pos()
{
    node *t=start;
    node *back=start;
    int pos;
    cout<<"Enter the Position where the member is to be inserted : ";
    cin>>pos;
    for (int i=1; i<=pos; i++)
    {
        back=t;
        t=t->next;
    }
    back->next=t->next;
    cout<<t->name<<"'s data has been deleted";
    delete t;
}

void sll::count()
{
    node *t=start;
    int count=0;
    while (t->next!=NULL)
    {
        t=t->next;
        count++;
    }
    cout<<"Total members of Club : "<<count-2;
}

// void sll::concatanate(node *a, node*b)
// {
//     if(a!=NULL && b!=NULL)
//     {
//         if(a->next==NULL)
//             a->next=b;
//         else
//             concatanate(a->next,b);
//     }
//     else
//     {
//         cout<<"Either of two Linked List is NULL";
//     }
// }

int main()
{
    sll obj;
    sll a,b;
    int ch;
    do
    {
        cout<<"\n1 : Create";
        cout<<"\n2 : Display";
        cout<<"\n3 : Insert President";
        cout<<"\n4 : Insert Member";
        cout<<"\n5 : Insert Secretary";
        cout<<"\n6 : Delete President";
        cout<<"\n7 : Delete Member";
        cout<<"\n8 : Delete Secretary";
        cout<<"\n9 : Total Members in Club";
        cout<<"\n10 : Merge Two Clubs";
        cout<<"\n11 : Exit";
        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.insert_begin();
            break;
        case 4:
            obj.insert_pos();
            break;
        case 5:
            obj.insert_end();
            break;
        case 6:
            obj.del_begin();
            break;
        case 7:
            obj.del_pos();
            break;
        case 8:
            obj.del_end();
            break;
        case 9:
            obj.count();
            break;
        case 10:
            a.create();
            a.display();
            b.create();
            b.display();
            
            break;
        case 11:
            exit(0);
        }
    } while (true);
    return 0;
}