#include <iostream>
using namespace std;

class A
{
	private:
		char expr[20];
		char stack[20];
		int top;
	public:
		A()
		{
			top=-1;
		}
		void get();
		void display();
		void push(char x);
		char pop();
		void check();
};

void A::get()
{
	cout<<"Enter the Expression : ";
	cin>>expr;
}

void A::display()
{
	cout<<"Expression : "<<expr<<endl;
}

void A::push(char x)
{
	top++;
	stack[top]=x;
}

char A::pop()
{
	top--;
}

void A::check()
{
	bool valid=1;
	for (int i=0; expr[i]!='\0';i++)
	{
		if(expr[i]=='{' or expr[i]=='[' or expr[i]=='(')
		{
			push(expr[i]);
		}
		else if(expr[i]=='}' and stack[top]=='{')
		{
			pop();
		}
		else if(expr[i]==']' and stack[top]=='[')
		{
			pop();
		}
		else if(expr[i]==')' and stack[top]=='(')
		{
			pop();
		}
		else
		{
			valid=0;
		}
	}
	if (top==-1 and valid)
	{
		cout<<"Valid Expression"<<endl;
	}
	else
	{
		cout<<"Invalid Expression"<<endl;
	}
}

int main()
{
	A obj;
	obj.get();
	obj.display();
	obj.check();
	return 0;
}