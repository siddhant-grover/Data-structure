#include<iostream>
using namespace std;
int stack[8];
int top=-1;
int maximum=8;
void push(int j)
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
void peek()
{
	if(top!=-1){
	cout<<"peek:: "<<stack[top]<<endl;}
}
int main()
{
 push(5);
 
 peek();
 pop();
 pop();
 peek();	
}