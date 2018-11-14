#include<iostream>
using namespace std;
static int i=0;
	struct node{
	int data;
	struct node *left;
	struct node *right;
};
node *insertnode(node *root,int data)
{
	node *temp = new node();
temp->data=data;
temp->left='\0';
temp->right='\0';
	if(root==NULL)
	{
		return temp;
	}
	else if(data>root->data){
		root->right=insertnode(root->right,data);}
	else if(data<root->data)
		{
		root->left=insertnode(root->left,data);}

	return root;
	
	
}
node *root='\0';
node *createnode(int n)
{
	node *trav= new node;
trav->data=n;
trav->left='\0';
trav->right='\0';
return trav;
}
void insert(int n)
{
/*node *trav= new node;
trav=createnode(n);
if(root=='\0')
{
	root=trav;
}
else
{
	node *temp=new node;
	temp=root;
	while(temp!='\0')
	{
		if(temp->data>trav->data)
		{
			if(temp->left=='\0'){
				
			temp->left=trav;
			temp=temp->left->left;}
			else
			{
				temp=temp->left;
			}
		}
		else
		{
		if(temp->right=='\0')
		{
		temp->right=trav;
			temp=temp->right->right;
				
		}	
		else
		{
			temp=temp->right;
		}
		}
	}
}

*/
node *temp = new node();
temp->data=n;
temp->left='\0';
temp->right='\0';

if(root=='\0')
{
	root=temp;
}
else
{
	
	node *trav=new node();
	trav=root;
	while(trav!='\0')
	{
		if(temp->data<trav->data)
			{
			if(trav->left=='\0')
			{
				trav->left=temp;
				trav='\0';
			}
			else
			{
				trav=trav->left;
			}
		}
		else
		{
			if(trav->right=='\0')
			{
				trav->right=temp;
				trav='\0';
			}
			else
			{
				trav=trav->right;
			}
		}
	}
}

}

struct node*findmax(node *root)
{
	while(root->right!='\0')
	{
		root=root->right;
	}
	return root;
}
void printPostorder(struct node* n) 
{ 
    if (n == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(n->left); 
  
    // then recur on right subtree 
    printPostorder(n->right); 
  
    // now deal with the node 
    cout << n->data << " "; 
} 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<root->data<<" ";
        inorder(root->right); 
    } 
} 
void pre(node *root)
{
	if(root=='\0')
	return;
	
	cout<<root->data<<" ";
	pre(root->left);
	pre(root->right);
}
void ino(node *root)
{
	
	
	if(root=='\0')
	{	
	return;}
	
	ino(root->left);
	i++;
	ino(root->right);
	
	
}
void post(node *root)
{
	if(root=='\0')
	return;
	
	post(root->left);
	post(root->right);
	cout<<root->data<<" ";
}
/*void search(node *root,int n)
{
	if(root=='\0')
	return;
	
	search(root->left,n);
	search(root->right,n);
	if(root->data==n)
	{
	cout<<"found";
	return;
	}
	
}*/

// C function to search a given key in a given BST 
struct node* search(struct node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->data == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->data < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 
void print(node *root)
{
	
	cout<<"post ::::: ";
	post(root);
	cout<<endl;
	cout<<"pre ::::: ";
	pre(root);
	cout<<endl;
	//ino(root);
}

struct node* deletenode(node *root,int find)
{
	node *temp=new node();
	if(root=='\0')
	cout<<"no node exist";
	else if(find<root->data)
	root->left=deletenode(root->left,find);
	else if(find>root->data)
	root->right=deletenode(root->right,find);
	else
	{
	if(root->right && root->left)
		{
			temp=findmax(root->left);
			root->data=temp->data;
			root->left=deletenode(root->left,root->data);
		
	}	
	else
	{
		temp=root;
		if(root->left=='\0')
		{
			root=root->right;
		}	
		else if(root->right=='\0')
		{
			root=root->left;
		}
		free(temp);
	}
	}
	return root;
}
int maxDepth(struct node* root)  
{ 
   if (root==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(root->left,key); 
       int rDepth = maxDepth(root->right,key); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}
int main()
{
	root=insertnode(root,50); 
    root=insertnode(root,30); 
    root=insertnode(root,20); 
    root=insertnode(root,40); 
    root=insertnode(root,70); 
    root=insertnode(root,60); 
    root=insertnode(root,80); 
	/*if(search(root,40)=='\0')
	cout<<"not found";
	else
	cout<<"found";
	//cout<<"\ni:: "<<i/2;*/
	//print(root);
	//print(deletenode(root,30));
	//cout<<i;
	//cout<<maxDepth(root,70);
	inorder(root);
	return(0);
}