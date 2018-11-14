#include<iostream>
using namespace std;
int queue[8];
int maximum=8;
int rear=-1;
int front=-1;
void push(int n)
{
if(front==-1 && rear==-1)
{
	front=rear=0;
	queue[rear]=n;
}	
else if(front==(rear+1)%8)
{
	cout<<n<<"::overflow"<<endl;
}
else 
{
	rear=(rear+1)%8;
	queue[rear]=n;
}
}
void pop()
{
	if(front==-1)
	{
		cout<<"underflow"<<endl;
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else{
		
	front=(front+1)%8;}
}
void peek_front()
{
	cout<<queue[front]<<endl;
}
void peek_rear()
{
	cout<<queue[rear]<<endl;
}
void display()
{
	int i;
	cout<<"queue ::";
	for(i=0;i<8;i++)
	{
	  cout<<queue[i]<<" ";	
	}
	cout<<endl;
}
int main()
{
	int i;
	for(i=0;i<8;i++)
	{
		push(i);
	}
	display();
	push(9);
	pop();
	push(8);
	display();
	pop();
	push(9);
	display();
	push(10);
	for(i=0;i<8;i++)
	{
		pop();
	}	
	pop();
	return(0);
}