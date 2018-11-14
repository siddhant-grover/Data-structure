#include<iostream>
using namespace std;
char stack[100];
int top=-1;
int maximum=100;
void push(char j)
{
	
	if(top==maximum-1)
	{
		cout<<"Stack Overflow"<<endl;
	}
	else
	{
		top=top+1;
		stack[top]=j;
	}
	
}
void pop()
{
	if(top==-1)
	{
		cout<<"no stack exist"<<endl;
	}
	else
	{
		top=top-1;
	}
}
char peek()
{
	return stack[top];
}
int prec(char c)
{
	if(c == '^')
	return 3;
	else if(c == '*' || c == '/')
	return 2;
	else if(c == '+' || c == '-')
	return 1;
	else
	return -1;
}
void decide(char c)
{
	string s="";
	if(c>='a'&&c<='z' || c>='A'&&c<='Z')
	{
	 s=s+c;	
	}
	else if(c=='(' || c=='{' || c=='[')
	{
		push(c);
	}
	else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^')
	{
	    while(prec(peek())>prec(c))
		{
			char x=peek();
			s=s+x;
			pop();
		}	
		push(c);
	}
	else if(c==')' || c==']' || c==']')
	{
		while(peek()!=char(c-1))
		{
			char v=peek();
			s=s+v;
			pop();
		}
	}
cout<<s;	
}
int main()
{
	string s="(a+(b*c)-d)";
	int i=0;
	for(i=0;s[i]!='\0';i++)
	{
		decide(s[i]);
	}
	cout<<endl;
	return(0);
}