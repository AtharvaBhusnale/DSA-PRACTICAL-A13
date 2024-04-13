#include<iostream>
using namespace std;

int adjmat[4][4];
int Row=4;
int col=4;

struct Node
{	char data;
	struct Node *down, *next;
}*Head;

char vertex(int val)
{	if(val==0)
		return 'A';
	else if(val==1)
		return 'B';
	else if(val==2)
		return 'C';
	else if(val==3)
		return 'D';
}

void CREATE_ADJMAT()
{	int i,j;
	for(i=0;i<Row;i++)
	{	for(j=0;j<col;j++)
		{	cout<<"Is edge from vertex "<<vertex(i)<<" to vertex "<<vertex(j)<<" : ";
			cin>>adjmat[i][j];
		}
	}
}

void DISP_ADJMAT()
	int i,j;
	for(i=0;i<Row;i++)
	{	cout<<"\n";
		for(j=0;j<col;j++)
		{	cout<<"\t"<<adjmat[i][j];
		}
	}	
}

void CREATE_LIST()
{	struct Node *Newnode, *move, *p;
	int i;
 	int nodes;
 	int edges;
	cout<<"\n\n How many Vertices in Graph: ";
 	cin>>nodes;
	for(i=0; i<nodes; i++)
	{	Newnode = new struct Node;
		Newnode->data = vertex(i);
		Newnode->down = NULL;
		Newnode->next = NULL;
		if(Head == NULL)
		{	Head = Newnode;
			move = Head;
		}
		else
		{	move->down = Newnode;	
			move = move->down;
 		}

	}

 	move = Head;
 	p = Head;
 	while(move != NULL)
 	{	cout<<"\n How many adjacent vertices for "<<move->data<<" : ";
 		cin>>edges;
		for(i=0; i<edges; i++)
		{	Newnode = new struct Node;
			cout<<"\n\t Enter An Adjacent Vertex: ";
 			cin>>Newnode->data;
 			Newnode->down = NULL;
 			Newnode->next = NULL;
			p->next = Newnode;
			p = p->next;
 		}
		move = move->down;
	 	p = move;
 	}

}

void D()
{
 	struct Node *move, *p;
	cout<<"\n\t -Head-";
	move = Head;
 	while(move != NULL)
 	{	cout<<"\n\t | "<<move->data<<" |--> ";
 		p = move->next;
		 while(p != NULL)
 		{
 			cout<<p->data<<" --> ";
 			p = p->next;
 		}
 		cout<<"NULL";
		move = move->down;
 		p = move;
 	}
}

void check_con()
{
	int i,j;
	int Nonzero;
	
	i=0;
	
	do 
	{
		Nonzero=0;
		
		for(j=0;j<col;j++)
		{
			if(adjmat[i][j]!=0)
				Nonzero++;
		}
		i++;
	}while(i<Row && Nonzero>0);
	
	if(i==Row)
	cout<<"Graphs COnnected";
	else
	cout<<"NOT CONNECTED!!";
}


int main()
{	cout<<"\n 1.Creating Adjacency Matrix";
	create_adjMtx();
	
	cout<<"\n2.Display Adjacency matrix";
	display_adjMtx();
	
	cout<<"\n 3. Create Adjacency List\n";
 	Head = NULL;
 	create_adjList();
 	cout<<"\n Adjacency List is created Successfull";
	
	cout<<"\n 4. Display Adjacency List";
 	display_adjList();

 	cout<<"\n 5. Check Connected Grap";
 	check_con();
	return 0;
}




