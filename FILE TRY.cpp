#include<iostream>
#include<fstream>

using namespace std;
void write()
{
	ofstream outfile;
    outfile.open("KJ.txt",ios::out|ios::app);
    if(!outfile)
    {
        cerr<<"error while opening";
        exit(1);
    }
    int entries;
    cout<<"enter the number of entries";
    cin>>entries;
    string name;
        int age;
    for(int i=0; i<entries; i++)
    {
        
        cout<<"enter name";
        cin>>name;
        cout<<"enter age";
        cin>>age;
        outfile<<name<<age;
    }
    outfile.close();
}

void read()
{
	ifstream infile;
    infile.open("KJ.txt",ios::in);
    if(!infile)
    {
        cerr<<"error for reading";
        exit(1);
    }
    int age;
    string name;
    cout<<"data in the file"<<endl;
    while(getline(infile,name))
    {
        cout<<name<<age;
    }
    infile.close();
}

int main()
{
	write();
	read();
	
}