/* 
# PROGRAM FOR ADJACENCY LIST
# NAME : SHARVARI S. WAGH
# SE(A): 73
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#define SIZE 30
#define MAX 20

using namespace std;

class Gnode
{
	public:
		int iVertex;
		char cPort[SIZE];
		float fCost;
		float fTime;
		Gnode *next;
		Gnode()				//constructor
		{
			next=NULL;
		}
};

class graph
{
	private:
		Gnode *head[MAX];
		int n;
		
	public:
		graph()
		{
			for(int i=0;i<MAX;i++)
				head[i]=NULL;
		}
		void create();
		void display();	
};

void graph :: create()
{
	cout<<"\nEnter the total number of airports : ";
	cin>>n;
	int y;
	Gnode *curr,*prev;
	char cAns;
	//char cStr[SIZE]; //for case sensitivity
		cin.ignore();
	for(int i=0;i<n;i++)
	{
		head[i]=new Gnode;
		head[i]->iVertex=i+1;
		cout<<"\nEnter the name of port "<<i+1<<": ";
	
		cin.getline(head[i]->cPort,SIZE);
	}
	for(int i=0;i<n;i++)
	{
		prev=head[i];
		cout<<"\nDo any flights from "<<i+1<<"."<<head[i]->cPort<<"?(y/n) : ";
		cin>>cAns;
		if(cAns=='n'||cAns=='N')
			continue;
		for(int k=0;k<n-1;k++)
		{
			curr=new Gnode;
			for(int j=0;j<n;j++)
			{
				if(i!=j)
					cout<<"\n"<<j+1<<"."<<head[j]->cPort;
			}
			cout<<"\nEnter the destination airport : ";
			cin>>y;
			strcpy(curr->cPort,head[y-1]->cPort);
		//	cin.ignore();
		//	cin.getline(curr->cPort,SIZE);
			cout<<"\nEnter the duration of flight : ";
			cin>>curr->fTime;
			cout<<"\nEnter the fuel cost for flight : ";
			cin>>curr->fCost;
			prev->next=curr;
			prev=curr;
			if(k!=n-2)
			{
				cout<<"\nAdd more destination flights?(y/n)";
				cin>>cAns;
			}
			if(cAns=='n'||cAns=='N')
				break;
		}	
	}
}

void graph :: display()
{
	Gnode *curr;
	for(int i=0;i<n;i++)
	{
		curr=head[i];
		while(curr!=NULL)
		{
			if(curr==head[i])
			{	cout<<"\n--------------------------------------------------";
				cout<<"\nSOURCE PORT  : ";
				cout<<"\t"<<curr->iVertex<<"\t"<<curr->cPort;	
				cout<<"\nDESTINATIONS : ";
				cout<<"\n\tAIRPORT\tTIME\tCOST";
			}
			else
			{
				cout<<"\n"<<"\t"<<curr->cPort<<"\t"<<curr->fTime<<"\t"<<curr->fCost;
				
			}
			curr=curr->next;
			
		}
		cout<<"\n--------------------------------------------------";	
	}
}

int main()
{
	cout<<"\n------------------------------------------";
	cout<<"\n\tGRAPHS USING ADJACENCY LIST";
	cout<<"\n------------------------------------------";	
	graph g;
	g.create();
	g.display();
return 0;
}

/*
OUTPUT :

------------------------------------------
	GRAPHS USING ADJACENCY LIST
------------------------------------------
Enter the total number of airports : 4

Enter the name of port 1: aaaa

Enter the name of port 2: bbbb

Enter the name of port 3: cccc

Enter the name of port 4: dddd

Do any flights from 1.aaaa?(y/n) : y

2.bbbb
3.cccc
4.dddd
Enter the destination airport : 2

Enter the duration of flight : 3

Enter the fuel cost for flight : 44

Add more destination flights?(y/n)n

Do any flights from 2.bbbb?(y/n) : y

1.aaaa
3.cccc
4.dddd
Enter the destination airport : 1

Enter the duration of flight : 6

Enter the fuel cost for flight : 7

Add more destination flights?(y/n)y

1.aaaa
3.cccc
4.dddd
Enter the destination airport : 3

Enter the duration of flight : 5

Enter the fuel cost for flight : 66

Add more destination flights?(y/n)y

1.aaaa
3.cccc
4.dddd
Enter the destination airport : 4

Enter the duration of flight : 7

Enter the fuel cost for flight : 8

Do any flights from 3.cccc?(y/n) : y

1.aaaa
2.bbbb
4.dddd
Enter the destination airport : 1

Enter the duration of flight : 5

Enter the fuel cost for flight : 88

Add more destination flights?(y/n)y

1.aaaa
2.bbbb
4.dddd
Enter the destination airport : 4

Enter the duration of flight : 8

Enter the fuel cost for flight : 99

Add more destination flights?(y/n)n

Do any flights from 4.dddd?(y/n) : y

1.aaaa
2.bbbb
3.cccc
Enter the destination airport : 2

Enter the duration of flight : 7

Enter the fuel cost for flight : 99

Add more destination flights?(y/n)n

--------------------------------------------------
SOURCE PORT  : 	1	aaaa
DESTINATIONS : 
	AIRPORT	TIME	COST
	bbbb	3	44
--------------------------------------------------
--------------------------------------------------
SOURCE PORT  : 	2	bbbb
DESTINATIONS : 
	AIRPORT	TIME	COST
	aaaa	6	7
	cccc	5	66
	dddd	7	8
--------------------------------------------------
--------------------------------------------------
SOURCE PORT  : 	3	cccc
DESTINATIONS : 
	AIRPORT	TIME	COST
	aaaa	5	88
	dddd	8	99
--------------------------------------------------
--------------------------------------------------
SOURCE PORT  : 	4	dddd
DESTINATIONS : 
	AIRPORT	TIME	COST
	bbbb	7	99
--------------------------------------------------

*/
