#include<iostream>
using namespace std;
struct queue{
int data;
struct queue* next= '\0';	
};
struct queue *front='\0';
struct queue *rear='\0';
struct queue* createnode(int dat)
{
	struct queue *q1;
	q1=(struct queue*)malloc(sizeof(struct queue));
	q1->data=dat;
	q1->next='\0';
	return q1;	
}
void insertnode(int dat)
{
	struct queue *q1;
	q1=createnode(dat);
		
}
int main()
{
	return(0);
}