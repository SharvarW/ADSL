/* 
# PROGRAM FOR ADJACENCY MATRIX
# NAME : SHARVARI S. WAGH
# SE(A): 73
*/

#include<iostream>
#include<cstdlib>
#include<cstring>
#define SIZE 50
#define MAX 20

using namespace std;

class edge
{
	float fCost;
	float fTime;
	public:
		edge()
		{
			fCost=0.00;
			fTime=0.00;
		}
		int read_edge();
		int display_edge(int x);
		int disp_cost();
		int disp_time();
		int refresh_edge();
		float get_time();
		float get_cost();
};

int edge :: refresh_edge()
{
	fCost=0.00;
	fTime=0.00;
	return 1;
}

int edge :: disp_cost()
{
	cout<<"\t"<<fCost;
	return 1;
}

int edge :: disp_time()
{
	cout<<"\t"<<fTime;
	return 1;
}


float edge :: get_time()
{
	return fTime;
}

float edge :: get_cost()
{
	return fCost;
}


int edge :: read_edge()
{
	cout<<"\nEnter time required : ";
	cin>>fTime;
	cout<<"\nEnter cost : ";
	cin>>fCost;
	return 1;
}

int edge :: display_edge(int x)
{
	if(x==1)
	{
		cout<<fCost;
	}
	else if(x==2)
	{
		cout<<fTime;
	}
	return 1;
}

class matgraph
{
	edge adj_mat[MAX][MAX];
	char cCity[MAX][SIZE];
	int n;
	bool bVisited[MAX];
	public:
		int create();
		int display();
		int disp();
		int cost_mat();
		int time_mat();
		int insert();
		int delet();
		void initialise_visit();
		int dfs(int x);
		void option();
				
};


void matgraph :: option()
{
	for(int x=0;x<n;x++)
	{
		cout<<"\n"<<x+1<<". "<<cCity[x];
	}
}

void matgraph :: initialise_visit()
{
	for(int i=0;i<n;i++)
	{
		bVisited[i]=0;
	}
}

int matgraph :: dfs(int x)
{
	//int y;
	cout<<"\n"<<x+1<<". "<<cCity[x];
	bVisited[x]=1;
	for(int i=0;i<n;i++)
	{
		if(bVisited[i]==0 && adj_mat[x][i].get_cost()!=0)
		{
			dfs(i);
		}
	}
	return 1;	
}

int matgraph :: delet()
{
	int x,y,a;
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<". "<<cCity[i];	
	}	
	cout<<"\nEnter the source port for which you want to delete edge : ";
	cin>>x;
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<". "<<cCity[i];	
	}	
	cout<<"\nEnter the destination port for which you want to delete edge : ";
	cin>>y;
	a=adj_mat[x-1][y-1].refresh_edge();
	return 1;	
}

int matgraph :: insert()
{
	int x,y,a;
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<". "<<cCity[i];	
	}	
	cout<<"\nEnter the source port for which you want to add an edge : ";
	cin>>x;
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<". "<<cCity[i];	
	}	
	cout<<"\nEnter the destination port for which you want to add an edge : ";
	cin>>y;
	if(adj_mat[x-1][y-1].get_time()==0)
	{
		a=adj_mat[x-1][y-1].read_edge();
	}
	return 1;
}

int matgraph :: cost_mat()
{
	int z=0;
	cout<<"\n";
	cout<<"\n--------------COST MATRIX-------------------\n";
	cout<<"\t";
	for(int i=0;i<n;i++)
		cout<<cCity[i]<<"\t  ";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<cCity[i];
		for(int j=0;j<n;j++)
		{	
			z=adj_mat[i][j].disp_cost();
		}
	}	
	return 1;		
}

int matgraph :: time_mat()
{
	int z=0;
	cout<<"\n";
	cout<<"\n--------------TIME MATRIX-------------------\n";
	cout<<"\t";
	for(int i=0;i<n;i++)
		cout<<cCity[i]<<"\t  ";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<cCity[i];
		for(int j=0;j<n;j++)
		{
			z=adj_mat[i][j].disp_time();
		
		}
	}
	return 1;
}

int matgraph :: disp()
{
	int z=0;
	cout<<"\n";
	cout<<"\t";
	for(int i=0;i<n;i++)
		cout<<cCity[i]<<"\t  ";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<cCity[i];
		for(int j=0;j<n;j++)
		{	
			z=adj_mat[i][j].disp_cost();
		}
	}
	
	cout<<"\n";
	for(int i=0;i<n;i++)
		cout<<"\t"<<cCity[i];
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<cCity[i];
		for(int j=0;j<n;j++)
		{
			z=adj_mat[i][j].disp_time();
		
		}
	}
	
	return 1;
}

int matgraph :: create()
{
	int i,j,y=0,flag=0,iCh,iF=0;
	char cAns;
	cout<<"\nEnter the number of ports (vertices) : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the city name for "<<i+1<<" :";
		cin>>cCity[i];
		for(int y=0;cCity[i][y]!='\0';y++)		//for removing case sensitivity
		{
			if(cCity[i][y]>='A' && cCity[i][y]<='Z')
			{
				cCity[i][y]=cCity[i][y]+32;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(flag==0)
		{
			cout<<"\nDo any edges exist starting from vertex "<<i+1<<" "<<cCity[i]<<" (y/n) : ";
			cin>>cAns;
			if(cAns=='y'||cAns=='Y')
			{
				flag=1;
			}
			else
				continue;
			
		}
		for(int b=0;b<n-1;b++)
		{
			cout<<"\nEnter the vertices such that edge exists between "<<i+1<<cCity[i]<<" vertex your choice : ";
			for(int h=0;h<n;h++)
			{
				if(i!=h)
				cout<<"\n"<<h+1<<". "<<cCity[h];				
			}
			cout<<"\nEnter choice : ";
			cin>>iCh;
			iF=adj_mat[i][iCh-1].read_edge();
		
			if(b!=n-2)
			{
				cout<<"\nAdd more vertices (y/n)? : ";
				cin>>cAns;
			}
			if(cAns=='y'||cAns=='Y')
			{
			}
			else
				break;
			
		}	
		flag=0;
	}
	return 1;
}

int matgraph :: display()
{
	cout<<"\n------------------------------------";
	cout<<"\nSOURCE\t\tDESTINATION";
	cout<<"\n------------------------------------";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
	//	cout<<" "<<i+1<<cCity[i]<<"\t\t";
		cout<<" "<<cCity[i]<<"\t\t";
		for(int j=0;j<n;j++)
		{
			if(adj_mat[i][j].get_cost()!=0)
			{
				//cout<<j+1<<cCity[j]<<",";	
				cout<<cCity[j]<<",";
			}
		}
	}
	cout<<"\n------------------------------------";
	return 1;
}

int main()
{
	matgraph m;
	int x,iChoice,iFlag=0,y;
	cout<<"\n=============================";
	cout<<"\n     ADJACENCY  MATRIX";
	cout<<"\n=============================";
	x=m.create();
	
	do
	{
here:	cout<<"\n------------------------";
		cout<<"\n\tMENU";
		cout<<"\n------------------------";
		cout<<"\n1.Display as table\n2.Display cost matrix\n3.Display time matrix\n4.Insert edge\n5.Delete edge\n6.DFS\n7.Exit";
		cout<<"\n------------------------";
		cout<<"\nEnter your choice : ";
		cin>>iChoice;
		switch(iChoice)
		{
			case 1:	x=m.display();
					x=0;
					break;
					
			case 2:	x=m.cost_mat();
					x=0;
					break;
					
			case 3:	x=m.time_mat();
					x=0;
					break;
				
			case 4:	x=m.insert();
					x=0;
					break;
			
			case 5:	x=m.delet();
					x=0;
					break;
					
			case 6:	m.initialise_visit();
					m.option();
					cout<<"\nEnter the city (vertex no.): ";
					cin>>y;
					x=m.dfs(y-1);	
					x=0;
					break;
					
			case 7:	exit(0);
			
			default:	goto here;	
				
		}
	}while(iChoice); 
	
return 0;
}

/*
OUTPUT : 

=============================
          ADJACENCY  MATRIX
=============================

Enter the number of ports (vertices) : 4

Enter the city name for 1 :aaaa

Enter the city name for 2 :bbbb

Enter the city name for 3 :cccc

Enter the city name for 4 :dddd

Do any edges exist starting from vertex 1 aaaa (y/n) : y

Enter the vertices such that edge exists between 1 aaaa vertex your choice : 
2. bbbb
3. cccc
4. dddd
Enter choice : 2

Enter time required : 6

Enter cost : 77

Add more vertices (y/n)? : y

Enter the vertices such that edge exists between 1 aaaa vertex your choice : 
2. bbbb
3. cccc
4. dddd
Enter choice : 4

Enter time required : 2

Enter cost : 55

Add more vertices (y/n)? : n

Do any edges exist starting from vertex 2 bbbb (y/n) : n

Do any edges exist starting from vertex 3 cccc (y/n) : y

Enter the vertices such that edge exists between 3 cccc vertex your choice : 
1. aaaa
2. bbbb
4. dddd
Enter choice : 1

Enter time required : 7

Enter cost : 999

Add more vertices (y/n)? : y

Enter the vertices such that edge exists between 3 cccc vertex your choice : 
1. aaaa
2. bbbb
4. dddd
Enter choice : 4

Enter time required : 3

Enter cost : 66

Add more vertices (y/n)? : n

Do any edges exist starting from vertex 4 dddd (y/n) : y

Enter the vertices such that edge exists between 4 dddd vertex your choice : 
1. aaaa
2. bbbb
3. cccc
Enter choice : 1

Enter time required : 2

Enter cost : 33

Add more vertices (y/n)? : y

Enter the vertices such that edge exists between 4 dddd vertex your choice : 
1. aaaa
2. bbbb
3. cccc
Enter choice : 2

Enter time required : 3

Enter cost : 44

Add more vertices (y/n)? : y

Enter the vertices such that edge exists between 4 dddd vertex your choice : 
1. aaaa
2. bbbb
3. cccc
Enter choice : 3

Enter time required : 4

Enter cost : 55

------------------------
	           MENU
------------------------
1.Display as table
2.Display cost matrix
3.Display time matrix
4.Insert edge
5.Delete edge
6.DFS
7.Exit
------------------------
Enter your choice : 1

------------------------------------
SOURCE		DESTINATION
------------------------------------
 aaaa		bbbb,dddd,
 bbbb		
 cccc		aaaa,dddd,
 dddd		aaaa,bbbb,cccc,
------------------------------------
------------------------
	MENU
------------------------
1.Display as table
2.Display cost matrix
3.Display time matrix
4.Insert edge
5.Delete edge
6.DFS
7.Exit
------------------------
Enter your choice : 2


--------------COST MATRIX-------------------

	     aaaa	   bbbb	   cccc	  dddd	  
aaaa	0	    77	      0	    55
bbbb	0	      0	      0             0
cccc	       999	      0              0	   66
dddd        33	    44	    55	     0
------------------------
	MENU
------------------------
1.Display as table
2.Display cost matrix
3.Display time matrix
4.Insert edge
5.Delete edge
6.DFS
7.Exit
------------------------
Enter your choice : 3


--------------TIME MATRIX-------------------
		aaaa	  bbbb	  cccc	  dddd	  
aaaa	0		     6	           0	             2
bbbb	0		     0	           0	             0
cccc	7	0	    	     0	           0                3
dddd	2		     3	           4	             0
------------------------
	        MENU
------------------------
1.Display as table
2.Display cost matrix
3.Display time matrix
4.Insert edge
5.Delete edge
6.DFS
7.Exit
------------------------
Enter your choice : 4

1. aaaa
2. bbbb
3. cccc
4. dddd
Enter the source port for which you want to add an edge : 2

1. aaaa
2. bbbb
3. cccc
4. dddd
Enter the destination port for which you want to add an edge : 3

Enter time required : 4

Enter cost : 55

------------------------
	          MENU
------------------------
1.Display as table
2.Display cost matrix
3.Display time matrix
4.Insert edge
5.Delete edge
6.DFS
7.Exit
------------------------
Enter your choice : 1

------------------------------------
SOURCE		DESTINATION
------------------------------------
 aaaa		bbbb,dddd,
 bbbb		cccc,
 cccc		aaaa,dddd,
 dddd		aaaa,bbbb,cccc,
------------------------------------
------------------------
	MENU
------------------------
1.Display as table
2.Display cost matrix
3.Display time matrix
4.Insert edge
5.Delete edge
6.DFS
7.Exit6

1. aaaa
2. bbbb
3. cccc
4. dddd
Enter the city (vertex no.): 2

2. bbbb
3. cccc
1. aaaa
4. dddd
------------------------
	           MENU
------------------------
1.Display as table
2.Display cost matrix
3.Display time matrix
4.Insert edge
5.Delete edge
6.DFS
7.Exit
------------------------
Enter your choice : 5

1. aaaa
2. bbbb
3. cccc
4. dddd
Enter the source port for which you want to delete edge : 2

1. aaaa
2. bbbb
3. cccc
4. dddd
Enter the destination port for which you want to delete edge : 3

------------------------
	            MENU
------------------------
1.Display as table
2.Display cost matrix
3.Display time matrix
4.Insert edge
5.Delete edge
6.DFS
7.Exit
------------------------
Enter your choice : 1

------------------------------------
SOURCE		DESTINATION
------------------------------------
 aaaa		bbbb,dddd,
 bbbb		
 cccc		aaaa,dddd,
 dddd		aaaa,bbbb,cccc,
------------------------------------
------------------------
	             MENU
------------------------
1.Display as table
2.Display cost matrix
3.Display time matrix
4.Insert edge
5.Delete edge
6.DFS
7.Exit
------------------------
Enter your choice : 7

*/
