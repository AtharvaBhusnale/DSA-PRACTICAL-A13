#include <iostream>
using namespace std;

char postfix[10];

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
}*Root;

struct Node* stack[5];
int top= -1;

void push(struct Node* newnode)
{
	top++;
	stack[top]=newnode;
}

struct Node* pop()
{
	struct Node *temp;
	
	temp=stack[top];
	top--;
	
	return temp;
}

struct Node* create(char value)
{
	struct Node* newnode;
	
	newnode = new struct Node;
	
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	
	return newnode;
}

void expressiontree()
{
	struct Node* newnode;
	
	cout<<"Enter the postfix Expression::";
	cin>>postfix;
	
	for(int i=0 ; postfix[i]!='\0' ; i++)
	{
	if( (postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z') )

		{
			newnode = create(postfix[i]);
			
			push(newnode);
		}
		
		if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
		{
			newnode = create(postfix[i]);
			
			newnode->right=pop();
			newnode->left=pop();
			
			push(newnode);
		}
		
	}
	if (Root==NULL)
	{
		Root=pop();
		cout<<"DONE!!";
	}
}

void inorder(struct Node *Root)
{
	if (Root)
	{
		inorder(Root->left);
		cout<<" "<<Root->data;
		inorder(Root->right);
	}
}

void preorder(struct Node *Root)
{
	if (Root)
	{
		cout<<" "<<Root->data;
		preorder(Root->left);
		preorder(Root->right);
	}
}

void postorder(struct Node *Root)
{
	if (Root)
	{
		postorder(Root->left);
		postorder(Root->right);
		cout<<" "<<Root->data;
	}
}

int main()
{

	
	Root=NULL;
	
	expressiontree();
	
	cout<<"Inorder::";
	inorder(Root);
	cout<<endl;
	
	cout<<"preorder::";
	preorder(Root);
	cout<<endl;
	
	cout<<"Postorder::";
	postorder(Root);
	cout<<endl;
return 0;
}

