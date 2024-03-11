#include <iostream>
using namespace std ;

struct Node 
{
	char name[25];
	struct Node *link1;
	struct Node *link2;
	struct Node *link3;		
} *root , *Ch ;

void create_tree()
{
	struct Node *temp ;
	temp = new struct Node ;
	
	cout<<"Enter the name for the BOOK :: ";
	cin>>temp->name;
	
	temp->link1=NULL;
	temp->link2=NULL;
	temp->link3=NULL;
	
	if(root==NULL)
		root=temp;
}

void insert_CH()
{
	struct Node *temp ;
	temp = new struct Node ;
	
	cout<<"Enter the name of CHAPTER :: ";
	cin>>temp->name;
	
	temp->link1=NULL;
	temp->link2=NULL;
	temp->link3=NULL;
	
	if (root->link1==NULL)
		root->link1=temp;
	else if (root->link2==NULL)
		root->link2=temp;
	else if (root->link3==NULL)
		root->link3=temp;
	else 
		cout<<"N0 more Chapters can be added!!";
}

void insert_SEC()
{
	struct Node *temp ;
	temp = new struct Node ;
	
	cout<<"Enter the name of SECTION :: ";
	cin>>temp->name;
	
	temp->link1=NULL;
	temp->link2=NULL;
	temp->link3=NULL;
	
	if (Ch->link1==NULL)
		Ch->link1=temp;
	else if (Ch->link2==NULL)
		Ch->link2=temp;
	else if (Ch->link3==NULL)
		Ch->link3=temp;
	else 
		cout<<"N0 more Sections can be added!!";
}

void insert_section()
{
	int ch ;
	
	cout<<"Enter the Chapter No. ::";
	cin>>ch;
	
	switch (ch)
	{
		case 1 : 
				Ch = root->link1;
				insert_SEC();
				insert_SEC();
				break ;
		case 2 :
				Ch = root->link2;
				insert_SEC();
				insert_SEC();
				break ;
		case 3 :
				Ch = root->link3;
				insert_SEC();
				insert_SEC();
				break ;
		default :
				cout<<"YOU HAVE ENTERED THE WRONG CHOICE !!";
	}
}

void display ()
{
	struct Node *temp ;
	temp = new struct Node ;
	
	if (root)
		cout<<"BOOK NAME ::"<<root->name<<endl;
		
	Ch=root->link1;
	if(Ch)
	{
		cout<<"Chapter 1::"<<endl;
		if(Ch->link1)
			cout<<"SECTION 1 ::"<<Ch->link1->name<<endl;
		if(Ch->link2)
			cout<<"SECTION 2 ::"<<Ch->link2->name<<endl;
		if(Ch->link3)
			cout<<"SECTION 3 ::"<<Ch->link3->name<<endl;
	}
	
	Ch=root->link2;
	if(Ch)
	{
		cout<<"Chapter 2::"<<endl;
		if(Ch->link1)
			cout<<"SECTION 1 ::"<<Ch->link1->name<<endl;
		if(Ch->link2)
			cout<<"SECTION 2 ::"<<Ch->link2->name<<endl;
		if(Ch->link3)
			cout<<"SECTION 3 ::"<<Ch->link3->name<<endl;
	}
	
	Ch=root->link3;
	if(Ch)
	{
		cout<<"Chapter 3::"<<endl;
		if(Ch->link1)
			cout<<"SECTION 1 ::"<<Ch->link1->name<<endl;
		if(Ch->link2)
			cout<<"SECTION 2 ::"<<Ch->link2->name<<endl;
		if(Ch->link3)
			cout<<"SECTION 3 ::"<<Ch->link3->name<<endl;
	}
}

int main ()
{
	root=NULL ;
	create_tree () ;
	/*int ch ;
	do 
	{
	cout<<"(TO STOP PRESS -1)"<<endl;
	cout<<"1.Enter Chapter \n 2.Enter Section \n 3.Display "<<endl;
	cout<<"Enter the operation you want to perform ::";
	cin>>ch;
	switch (ch)
	{
		case 1 :
			insert_CH();
		case 2 :
			insert_section();
		case 3 :
			display();
		default :
			cout<<"Wrong CHoice!!";
	}
	}
	while (1);*/
	
	insert_CH();
	insert_CH();
	insert_CH();
	
	insert_section();
	insert_section();
	insert_section();
	
	display();
return 0;
}
