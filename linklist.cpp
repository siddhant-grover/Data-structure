#include<iostream>
using namespace std;
struct node{
int data;

struct node* next;
	
	};
	struct node* head='\0';
struct node* createnode()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	return temp;
}
void insertbegin(int dat)
{
	struct node *temp;
	temp=createnode();
	
	temp->data=dat;
	
    if(head!='\0'){
    	
	temp->next=head;
    }
    else
    {
    	temp->next='\0';
    }
	head=temp;
	//cout<<head<<endl;
	
}
void display()
{
	struct node *temp;
	temp=head;
	while(temp!='\0')
	{  	
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	
}
void insertend(int dat)
{
	struct node* temp;
	struct node* add;
	add=createnode();
	temp=head;
	if(head!='\0'){
		
	
	while(temp->next!='\0')
	{
		temp=temp->next;
	}
	add->data=dat;
	add->next='\0';
	temp->next=add;
	}
	else
	{
		insertbegin(dat);
	}
}
void insertbefore(int dat,int data)
{
 struct node *temp;
 struct node *pre;
 struct node *add;
  add=createnode();
  temp=head;
  pre=head;
  
  while(temp->data!=dat)
  {
  	
  	pre=temp;
  	temp=temp->next;
  }
  if(temp!='\0'){
  	
  
  if(pre!=head && temp->next!='\0')
  {
  	
 add->data=data;
 add->next=temp;
 pre->next=add;	
  }
  else{
  	if(pre==head)
  	{
	  	insertbegin(data);
	  }
	  else
	  insertend(data);
  }
}
else
{
	cout<<"node doesnt exist"<<endl;
}
}
void repeat(){
	struct node *temp;
	temp=head;
	int a[100]={0};
	while(temp!='\0')
	{
		a[temp->data]++;
		temp=temp->next;
	}
	int i;
	cout<<"list of repeating :"<<endl;
	for(i=0;i<100;i++)
	{
		if(a[i]>1)
		{
			cout<<i<<endl;
		}
	} 
	
}
void repeatfreq(){
	struct node *temp;
	temp=head;
	int a[100]={0};
	while(temp!='\0')
	{
		a[temp->data]++;
		temp=temp->next;
	}
	int i;
	cout<<"list of repeating :"<<endl;
	for(i=0;i<100;i++)
	{
		if(a[i]>1)
		{
			cout<<i<<"\tfrequency::"<<a[i]<<endl;
		}
	}
}
int main()
{ 
   
   insertbegin(5);	
   insertbegin(6);
   insertbegin(9);
   insertbegin(7);
   insertbegin(4);
   insertbegin(9);
   insertbegin(7);
   insertbegin(6);
   insertend(7);
   insertbefore(7,10);
   //insertbefore(9,11);
   //insertbefore(7,12);
   
   display();
   repeatfreq();
	return (0);
}