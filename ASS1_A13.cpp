#include <iostream>
#include <cstring>
using namespace std;

int tablesize=10;

struct Hashtable 
{
	char key[10];
	int val;
} HT1[10],HT2[20];

void init ()
{
	int i;
	
	for(i=0;i<tablesize;i++)
	{
		strcpy(HT1[i].key,"....");
		HT1[i].val=0;
	}
	
	for(i=0;i<tablesize;i++)
	{
		strcpy(HT2[i].key,"....");
		HT2[i].val=0;	
	}
}

int Hashfun(char key[] )
{
	int i,index,sum=0;
	
	for(i=0;key[i]!='\0';i++)
	{
		sum=sum+key[i];
	}
	
	index=sum % tablesize;
	
	return index;
}

void insert_ht1(char Cname[] , int tele)
{
	int i,index;
	index=Hashfun(Cname);
	
	if (strcmp(HT1[index].key,"....")==0)
	{
		strcpy(HT1[index].key,Cname);
		HT1[index].val=tele;
	}
	
	else 
	{
		while(strcmp(HT1[index].key,"....")!=0)
		{
			index=(index+i)%tablesize;
		}
		
		
		strcpy(HT1[index].key,Cname);
		HT1[index].val=tele;
	}
}

void insert_ht2(char Cname[] , int tele)
{
	int i,id,index;
	index=Hashfun(Cname);
	
	if (strcmp(HT2[index].key,"....")==0)
	{
		strcpy(HT2[index].key,Cname);
		HT1[index].val=tele;
	}
	
	else 
	{
		id=index;
		while(strcmp(HT1[index].key,"....")!=0)
		{
			id=(index+(i*i))%tablesize;
			i++;
		}
		
		strcpy(HT2[index].key,Cname);
		HT2[index].val=tele;
	}
}

void display()
{
	for(int i=0;i<tablesize;i++)
	{
		cout<<"Name::"<<HT1[i].key<<" Phone No.::"<<HT1[i].val<<endl;
	}
}


int main()
{
	init();
		char name[] = "prasad";
	insert_ht1 (name,9834);
		char name1[] = "Home";
	insert_ht1 (name1,94233);
		char name2[] = "Atharva";
	insert_ht1 (name2,6689);
//	inssert_ht1("");
//	inssert_ht1();
	init();
		char name3[] = "prasad";
	insert_ht2 (name3,9834);
		char name4[] = "Home";
	insert_ht2 (name4,94233);
		char name5[] = "Atharva";
	insert_h2 (name5,6689);
	disp+lay();
}





















