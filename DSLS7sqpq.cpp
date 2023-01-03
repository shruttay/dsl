#include <iostream>
#define max 5
using namespace std;

class Queue
{
	private:
		int f,r,job;
		int sq[max];
		int pq[max];
	public:
		Queue()
		{
			f=r=-1;
			job=0;
		}
		
		int isFull()
		{
			if(r==(max-1))
				return 1;
			else
				return 0;
		}
		
		int isEmpty()
		{
			if((f==-1) || (f>r))
				return 1;
			else
				return 0;
		}
		void insert_sq();
		void del_sq();
		void display_sq();
		void insert_pq();
		void del_pq();
		void display_pq();
};

void Queue::insert_sq()
{
	cout<<"Enter job : ";
	cin>>job;
	if(isFull())
	{
		cout<<"Queue is Full";
		return;
	}
	else
	{
		r++;
		sq[r]=job;
	}
	if(f==-1)
		f=0;
}

void Queue::del_sq()
{
	if(isEmpty())
	{
		cout<<"Queue is Empty";
		return;
	}
	else
	{
		cout<<"Deleted Job : "<<sq[f];
		f++;
		
	}
}

void Queue::display_sq()
{
	if(isEmpty())
	{
		cout<<"Queue is Empty";
		return;
	}
	else
	{
		for(int i=f; i<=r; i++)
			cout<<"\t"<<sq[i];
	}
}
void Queue::insert_pq()
{
	int temp=0;
	cout<<"Enter Job : ";
	cin>>job;
	if (isFull())
	{
		cout<<"Queue is Full";
		return;
	}
	else
	{
		if(f==-1)
		{
			f=r=0;
			pq[r]=job;
		}
		else if(job<pq[r])
		{
			temp=r;
			while (job<pq[temp])
			{
				pq[temp+1]=pq[temp];
				temp--;
			}
			temp++;
			pq[temp]=job;
			r++;
		}
		else
		{
			r++;
			pq[r]=job;
		}
	}
}

void Queue::del_pq()
{
	if(isEmpty())
	{
		cout<<"Queue is Empty";
		return;
	}
	else
	{
		cout<<"Deleted Job : "<<pq[f];
		f++;
		
	}
}

void Queue::display_pq()
{
	if(isEmpty())
	{
		cout<<"Queue is Empty";
		return;
	}
	else
	{
		for(int i=f; i<=r; i++)
			cout<<"\t"<<pq[i];
	}
}

int main()
{
	Queue obj1, obj2;
	int ch;
	do
	{
		cout<<endl;
		cout<<"\n1. Insert job in Simple Queue";
		cout<<"\n2. Delete job in Simple Queue";
		cout<<"\n3. Diplay job in Simple Queue";
		cout<<"\n4. Insert job in Priority Queue";
		cout<<"\n5. Delete job in Priority Queue";
		cout<<"\n6. Diplay job in Priority Queue";
		cout<<"\n7. Exit";
		cout<<"\nEnter your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj1.insert_sq();
				break;
			case 2:
				obj1.del_sq();
				break;
			case 3:
				obj1.display_sq();
				break;
			case 4:
				obj2.insert_pq();
				break;
			case 5:
				obj2.del_pq();
				break;
			case 6:
				obj2.display_pq();
				break;
			case 7:
				exit(0);
		}
	}while(true);
	return 0;
}
