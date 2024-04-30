#include <iostream>
using namespace std ;

struct Node 
{
	int data;
	Node* left;
	Node* right;
	
	Node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};


Node* insertBST(Node* root , int val)
{
	if (root==NULL)
		return new Node(val);
	
	if(val < root->data)
	{
		root->left = insertBST(root->left,val);
	}
	else
	{
		root->right = insertBST(root->right,val);
	}
	
	return root;
}

Node* searchBST(Node* root , int val)
{
	if (root->data==val)
		return root;
	
	if (val<root->data)
	{
		return searchBST(root->left,val);
	}
		return searchBST(root->right,val);
}

Node* inorderSucc(Node* root)
{
	Node* curr=root;
	while(curr && curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}

Node* deleteBST(Node* root , int val)
{
	if(val<root->data)
	{
		root->left=deleteBST(root->left,val);
	}
	else if (val>root->data)
	{
		root->right=deleteBST(root->right,val);
	}
	
	else{
		if (root->left==NULL)
		{
			Node* temp=root->right;
			free(root);
			return temp;
		}
		
		else if(root->right==NULL)
		{
			Node* temp=root->left;
			free(root);
			return temp;
		}
		
		else
		{
			Node* temp=inorderSucc(root->right);
			root->data=temp->data;
			root->right=deleteBST(root->right,temp->data);
		}
	}
	return root;
}

Node* Inorder(Node *root)
{
 if(root != NULL)
 {
 Inorder(root->left);
 cout<<" "<<root->data;
 Inorder(root->right);
 }
}
int main()
{
	Node* root=NULL;
	root=insertBST(root,6);
	insertBST(root,3);
	insertBST(root,9);
	insertBST(root,1);
	insertBST(root,2);
	insertBST(root,8);
	insertBST(root,10);
	
	Inorder(root);
	
	if(searchBST(root,8)==NULL)
		cout<<"NOT FOUND!!";
	else
		cout<<"FOUND";
		
	root=deleteBST(root,2);
	
	Inorder(root);
	
}