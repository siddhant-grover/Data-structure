#include<iostream>
using namespace std;
struct node{
int data;
struct node* next;
};
struct node *head='\0';
struct node* createnode(int dta)
{
   struct node *temp;
   temp=(struct node *)malloc(sizeof(node));
   temp->data=dta;
   temp->next='\0';
   return temp;
   	
}
// insertion functions
void insert(int data)
{
	struct node *temp;
	temp=createnode(data);
	if(head=='\0')
	{
		head=temp;
		
	}
	else
	{  
	 	struct node *trav;
	 	trav=head;
		while(trav->next!='\0')
		{ 
			
		 	trav=trav->next;	
		}
		trav->next=temp;
	}
}
void insert_begin(int data)
{
	struct node *temp;
	temp=createnode(data);
	temp->next=head;
	head=temp;
	
	
}
void display()
{
	cout<<endl;
	struct node *temp;
	temp=head;
	while(temp!='\0')
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	
}
void insert_atpos(int pos ,int data)
{
	int counter=0;
	struct node* temp,*trav,*pre;
	temp=createnode(data);
	trav=head;
	int flag=0;
	while(trav->next!='\0')
	{
	
		counter++;
		//cout<<counter;
		
		if(counter==pos)
	{
			flag=1;
		break;}
		pre=trav;
	
	trav=trav->next;	
	}
		
	if(pos==1)
	{
		insert_begin(data);
		
	}
	else if(trav->next=='\0')
	{
		insert(data);
	}
	else if(flag==1)
	{
		temp->next=trav;
		pre->next=temp;
	}
	else if(pos>counter)
	{
		cout<<"no position exist"<<endl;
	}
	
}
void insert_before(int data,int info)
{
	struct node *temp;
	temp=head;
	int count=0;
	while(temp!='\0' && temp->data!=data)
	{
	
	temp=temp->next;
	count++;	
		
	}
	if(temp==head)
	{
		
		insert_begin(info);
	}
	else if(temp=='\0')
	{
		
		cout<<"no element exist";
	}
	else 
	{
		insert_atpos(count,info);
	}
	
}
void insert_after(int data,int info)
{
	struct node* temp;
	temp=head;
	int count=0;
	while(temp!=0 && temp->data!=data)
	{
	temp=temp->next;  
	count++; 	
	}
	if(temp==head)
	{
		insert_begin(info);
	}
	else if(temp->next=='\0' && temp->data==data)
	{
		insert(info);
	}
	else if(temp->next='\0')
	{
		
		cout<<"no element exist";
	}
	else{
	cout<<"last else";	
	insert_atpos(count+1,info);	
	}
}
int main()
{
	struct node *temp;
	insert(5);
	insert(4);
	insert(9);
	insert_begin(6);
	insert_atpos(3,44);
	display();
	cout<<"add 8 before 9"<<endl;
	insert_before(9,8);
	display();
	cout<<"insert 55 after 4"<<endl;
	insert_after(4,55);
	display();
	return (0);
}