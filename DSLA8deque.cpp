# include <iostream>
using namespace std;

class deque
{
	private:
		struct node
		{
			int data;
			node *next;
		}*f,*r;
		
	public:
		deque()
		{
			f=NULL;
			r=NULL;
		}
		void insert_front();
		void insert_rear();
		void del_front();
		void del_rear();
		void display();
};

void deque::insert_front()
{
	node *temp;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"Deque is Full";
	}
	else
	{

		temp->next=NULL;
		cout<<"Enter data : ";
		cin>>temp->data;
		if(f==NULL)
		{
			f=temp;
			r=temp;
		}
		else
		{
			temp->next=f;
			f=temp;
		}
	}
}

void deque::insert_rear()
{
	node *temp;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"Deque is Full";
	}
	else
	{
		temp->next=NULL;
		cout<<"Enter data : ";
		cin>>temp->data;
		if(f==NULL)
		{
			f=temp;
			r=temp;
		}
		else
		{
			r->next=temp;
			r=temp;
		}
	}
}

void deque::del_front()
{
	node *t;
	if(f==NULL)
	{
		cout<<"Queue is Empty";
	}
	else
	{
		t=f;
		cout<<t->data<<" has been deleted";
		f=f->next;
		delete t;
	}
}

void deque::del_rear()
{
	node *t;
	if(f==NULL)
	{
		cout<<"Queue is Empty";
	}
	else
	{
		while(t->next!=r)
		{
			t->next=NULL;
			cout<<r->data<<" has been deleted";
			r=t;
		}
	}
}

void deque::display()
{
	node *t;
	t=f;
	if(f==NULL)
	{
		cout<<"Deque is Empty";
	}
	else
	{
		while(t!=NULL)
		{
			cout<<t->data<<"-->";
			t=t->next;
		}
		cout<<"NULL";
	}
	cout<<endl<<endl;
}

int main()
{
	int ch;
	deque obj;
	do
	{
		cout<<"\n1 : To insert node at front";
		cout<<"\n2 : To insert node at rear";
		cout<<"\n3 : To delete node from front";
		cout<<"\n4 : To delete node from rear";
		cout<<"\n5 : To display";
		cout<<"\n6 : Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.insert_front();
				break;
			case 2:
				obj.insert_rear();
				break;
			case 3:
				obj.del_front();
				break;
			case 4:
				obj.del_rear();
				break;
			case 5:
				obj.display();
				break;
			case 6:
				exit(1);
		}
	}while(ch!=6);
	return 0;
}
