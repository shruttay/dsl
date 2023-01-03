#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
bool Operator(char);
bool Operand(char);
bool eqlOrHigher(char, char);
string convert(string);

int Postfix(string post_exp)
{
	stack <int> stack1;
	int len =post_exp.length();
	for (int i=0; i<len; i++)
	{
		if(post_exp[i]>='0' && post_exp[i]<='9')
		{
			stack1.push(post_exp[i] - '0');
		}
		else
		{
			int a=stack1.top();
			stack1.pop();
			int b=stack1.top();
			stack1.pop();
			switch(post_exp[i])
			{
				case '+':
					stack1.push(b+a);
					break;
				case '-':
					stack1.push(b-a);
					break;
				case '*':
					stack1.push(b*a);
					break;
				case '/':
					stack1.push(b/a);
					break;
				case '^':
					stack1.push(pow(b,a));
					break;
			}
		}
	}
	return stack1.top();
}

int main()
{
	string infix_exp, postfix_exp;
	int ch;
	do
	{
		cout<<"Enter an infix expression : ";
		cin>>infix_exp;
		postfix_exp=convert(infix_exp);
		cout<<"\nYour Infix Expression is : "<<infix_exp;
		cout<<"\nPosfix Expression is : "<<postfix_exp;
		cout<<"\nThe answer after calculating the postfix expression is : ";
		cout<<Postfix(postfix_exp);
		cout<<"\n \t Do you want to enter infix Expression (1/0)?";
		cin>>ch;
	}while(ch==1);
	return 0;
}

bool Operator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
		return true;
	return false;
}

bool Operand(char c)
{
	if(c>='A' && c<='Z')
		return true;
	if(c>='a' && c<='z')
		return true;
	if(c>='0' && c<='9')
		return true;
	return false;
}

int precedence(char op)
{
	if(op=='+' || op=='-')
		return 1;
	if(op=='*' || op=='/')
		return 2;
	if(op=='^')
		return 3;
	return 0;
}

bool eqlOrHigher(char op1, char op2)
{
	int p1=precedence(op1);
	int p2=precedence(op2);
	if(p1==p2)
	{
		if(op1=='^')
			return false;
		return true;
	}
	return(p1>p2 ?true:false);
}

string convert(string infix)
{
	stack <char> S;
	string postfix="";
	char ch;
	S.push('(');
	infix+=')';
	for(int i=0; i<infix.length(); i++)
	{
		ch=infix[i];
		if(ch==' ')
			continue;
		else if(ch=='(')
			S.push(ch);
		else if(Operand(ch))
			postfix+=ch;
		else if(Operator(ch))
		{
			while(!S.empty() && eqlOrHigher(S.top(), ch))
			{
				postfix+=S.top();
				S.pop();
			}
			S.push(ch);
		} 
		else if(ch==')')
		{
			while(!S.empty() && S.top()!='(')
			{
				postfix+=S.top();
				S.pop();
			}
			S.pop();
		}
	}
	return postfix;
}
