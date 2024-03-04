#include <iostream>
using namespace std ;

int HT1[10];
int HT2[10];
int size=10 ;

void init()
{
	for (int i=0 ; i<size ; i++)
	{
		HT1[i]=0;
		HT2[i]=0;
	}
}

void display()
{
	int i ;
	cout << "HASH TABLE 1::"<<endl;
	cout<<"Index \t Key"<<endl;
	for (int i=0 ; i<size ; i++)
	{
		cout<<i<<"\t"<<HT1[i]<<endl;
	}
	
	cout << "HASH TABLE 2::"<<endl;
	cout<<"Index \t Key"<<endl;
	for (int i=0 ; i<size ; i++)
	{
		cout<<i<<"\t"<<HT2[i]<<endl;
	}
}

void insert_seta(int key)
{
	int index=key%size;
	HT1[index]=key;
}

void insert_setb(int key)
{
	int index=key%size;
	HT2[index]=key;
}

void search_seta(int key)
{
	 int index;
	 index=key%size;
	 if(HT1[index] == key)
	 	cout<<"\n\t Key"<<key<<" Found at "<<index<<endl;
	 else
	 	cout<<"\n\t Key"<<key<<" Not Found....!!!"<<endl;
}

void search_setb(int key)
{
	 int index;
	 index=key%size;
	 if(HT2[index] == key)
	 	cout<<"\n\t Key"<<key<<" Found at "<<index<<endl;
	 else
	 	cout<<"\n\t Key"<<key<<" Not Found....!!!"<<endl;
}

void delete_seta(int key)
{
	int index=key%size ;
	
	if (HT1[index]==key)
	{
		HT1[index]=0;
		cout<<"Element DELETED!!"<<endl;
	}
	
	else 
	{
		cout<<"Element Not Found!!"<<endl;
	}
}

void delete_setb(int key)
{
	int index=key%size ;
	
	if (HT2[index]==key)
	{
		HT2[index]=0;
		cout<<"Element DELETED!!"<<endl;
	}
	
	else 
	{
		cout<<"Element Not Found!!"<<endl;
	}
}

int duplicate(int value)
{
	int dupe = 0 ; 
	
	for (int i=0 ; i<size ; i++)
	{
		if (value == HT1[i])
			dupe = 1;
	}
	
	return dupe ;
}

void union_ab()
{
	int HT3[20] , j=0;
	
	for (int i=0 ; i < size ; i++)
	{
		if (HT1[i]!=0)
		{
			HT3[j]=HT1[i];
			j++;
		}
	}
	
	for (int i=0 ; i < size ; i++)
	{
		if (HT2[i]!=0)
		{
			HT3[j]=HT2[i];
			j++;
		}
	}
	cout<<"Uninon table ::" <<endl ;
	for (int i=0 ; i<20 ; i++)
	{
		cout<<HT3[i]<<endl ;
	}
}

int main()
{
	init();
	
	insert_seta(1);
	insert_seta(2);
	insert_seta(3);
	insert_seta(4);
	insert_seta(5);
	insert_seta(6);
	insert_seta(7);
	insert_seta(8);
	insert_seta(9);
	
	insert_setb(10);
	insert_setb(11);
	insert_setb(12);
	insert_setb(13);
	insert_setb(14);
	insert_setb(15);
	insert_setb(16);
	insert_setb(17);
	insert_setb(18);
	
	display();
	search_seta(3);
	search_setb(10);
	
	delete_seta(3);
	search_setb(10);
	union_ab();
	
}
