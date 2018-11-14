#include<iostream>
using namespace std;

int main(){
	int ele,i,in,k,arr[20],front=-1,rear=-1,a=10,b;
	
	cout<<"Array size is 10"<<endl;
	cout<<"How many elements do you want to enter! ";
	cin>>b;
	
	
	if(a!=0){
	
	cout<<"Enter 1 to insert, 2 to delete and 3 to exit"<<endl;
	cin>>k;
	
	while(k!=3){
		
		if(k==1){
		cout<<"Enter 1 to insert right, 2 to left"<<endl;
		cin>>in;
		
		for(i=0;i<b;i++){
		cout<<"Enter element: ";
		cin>>ele;
		
		if(in==1){
			if(front==-1 && rear==-1){
			front=0;
			rear=0;
			}
			else if(rear==a-1){
				rear=0;
			}
			else{
				rear=rear+1;
			}
			arr[rear]=ele;
		}
		else if(in==2){
			if(front==-1 && rear==-1){
				front=0;
				rear=0;
			}
			else if(rear==0){
				rear=a-1;
			}
			else{
				rear=rear-1;
			}
			
			arr[rear]=ele;
		}
		else{
			cout<<"Enter valid number!"<<endl;
		}
	}
}
		
		else if(k==2){
		cout<<"Enter 1 to delete from right, 2 from left"<<endl;
		cin>>in;
		
		cout<<"How many elements you want to delete ?: ";
		cin>>ele;
		
		for(i=0;i<ele;i++){
		if(in==1){
			if(front==-1 && rear==-1){
				cout<<"Sorry, there are no elements to delete"<<endl;
			}
			else if(front==a-1){
				front=0;
			}
			else{
				front=front+1;
			}
		}
		else if(in==2){
			if(front==-1 && rear==-1){
				cout<<"Sorry, there are no elements to delete";
			}
			else if(front==0){
				front=a-1;
			}
			else{
				front=front-1;
			}
		}
		
		else{
			cout<<"Enter a valid number!"<<endl;
		}
		
	}
}
	
		else if(k==3){
			break;
		}
		else{
			cout<<"Enter a valid number bro!"<<endl;
		}
		
	cout<<"Enter 1 to insert, 2 to delete and 3 to exit"<<endl;
	cin>>k;
	
}
	
	cout<<"Your desired array is: "<<" ";
	
	if(rear==front+1){
		cout<<arr[front]<<" ";
	//	cout<<"1";
		front=a-1;
		for(i=rear;i<=front;i++){
			cout<<arr[i]<<" ";
		}	
	}
	
	else if(rear<front){
	//	cout<<"2";
		for(i=rear;i<=front;i++){
			cout<<arr[i]<<" ";
		}
	}
		
	else
	for(i=front;i<=rear;i++){
		cout<<arr[i]<<" ";
	}
	
}
}
