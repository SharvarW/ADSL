/* 
# PROGRAM FOR HASH TABLE WITHOUT REPLACEMENT
# NAME : SHARVARI S. WAGH
# SE(A): 73
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
#define SIZE 15
#define MAX 20
#define KEY 15
using namespace std;

class contact
{
	char cName[SIZE];
	char cPhone[KEY];
	public:
		contact()
		{
			strcpy(cName,"");
			strcpy(cPhone,"");
		}
		int read_contact();
		int refresh_contact();
		int display_contact();
		char* get_phone();
};

char* contact :: get_phone()
{
	return cPhone;
}

int contact :: refresh_contact()
{
	strcpy(cPhone,"");
	strcpy(cName,"");
	return 1;
}


int contact :: read_contact()
{	
	cout<<"\nEnter the contact Name : ";
	cin>>cName;
	cout<<"\nEnter the contact Number : ";
	cin>>cPhone;
	return 1;
}

int contact :: display_contact()
{
	cout<<"\t\t"<<cPhone<<"\t"<<cName;
	return 1;
}

class hashtable
{
	contact hash_t[MAX];
	public:
		int read_hash();
		int display_hash();
		int insert_hash();
		int hash_value(char cKey[KEY]);
		int search_hash(char cKey[KEY]);
		int delete_hash(char cKey[KEY]);
};

int hashtable :: insert_hash()
{
	contact c;
	int i,iIndex,iFlag;
	iFlag=c.read_contact();
	iIndex=hash_value(c.get_phone());
	if(strcmp(hash_t[iIndex].get_phone(),"")==0)
	{
		hash_t[iIndex]=c;
		return 1;
	}
	else
	{
		for(i=iIndex+1;iIndex!=i%MAX;i=(i+1)%MAX)
		{
			if(i!=MAX)
			{
				if(strcmp(hash_t[i].get_phone(),"")==0)
				{
					hash_t[i]=c;
					break;
				}
			}
			else
			{
				i=MAX-1;
			}
		}
	}
	return -1;
}

int hashtable :: delete_hash(char cKey[KEY])
{
	int i,iFlag=0,iIndex;
	iFlag=search_hash(cKey);
	if(iFlag!=-1)
	{
		iIndex=iFlag;
		i=hash_t[iIndex].refresh_contact();
		if(i==1)
		{
			cout<<"\nContact deleted successfully!";
			return 1;
		}
		
	}
	return -1;
}

int hashtable :: search_hash(char cKey[KEY])
{
	int iFlag=0,iIndex=hash_value(cKey);
	if(strcmp(hash_t[iIndex].get_phone(),cKey)==0)	//linear search remaining 
	{
		iFlag=1;
		cout<<"\nContact Found!\n";
		iFlag=hash_t[iIndex].display_contact();
		return iIndex;		
	}
	else					//else condition for linear search 
	{
		for(int i=iIndex+1;i%MAX!=iIndex;i=(i+1)%MAX)
		{
			if(i!=MAX)
			{
				if(strcmp(hash_t[i].get_phone(),cKey)==0)
				{
					iFlag=1;
					cout<<"\nContact Found!";
					iFlag=hash_t[i].display_contact();
					return i;
				}
			}
			else
				i=MAX-1;
			
		}
		return -1;	//if not found even by linear search	
	}
	
}

int hashtable :: hash_value(char cKey[KEY])
{
	int x=0,y=0,z=0;
	for(int i=0;cKey[i]!='\0';i++)
	{
		if(i%3==0)
		{
			x=x+cKey[i];
		}
		if(i%3==1)
		{
			y=y+cKey[i];
		}
		else
		{
			z=z+cKey[i];
		}
	
	}
		
	return ((x%MAX)+(y%MAX)+z)%MAX;
}

int hashtable :: read_hash()
{
	contact c;
	int i,iIndex,iFlag;
	char cAns;
	do
	{
		iFlag=c.read_contact();
		iIndex=hash_value(c.get_phone());
		if(strcmp(hash_t[iIndex].get_phone(),"")==0)
		{
			hash_t[iIndex]=c;
		}
		else
		{
			for(i=iIndex+1;iIndex!=i%MAX;i=(i+1)%MAX)
			{
				if(i!=MAX)
				{
					if(strcmp(hash_t[i].get_phone(),"")==0)
					{
						hash_t[i]=c;
						break;
					}
				}
				else
				{
					i=MAX-1;
				}
				
			}
		}
		cout<<"\nAdd more? : ";
		cin>>cAns;
	}while(cAns=='y'||cAns=='Y');
	return 1;
}

int hashtable :: display_hash()
{
	int i=0,iFlag;
	char cAns;
	cout<<"\n========================";
	cout<<"\n    LINEAR HASHING";
	cout<<"\n========================";
	cout<<"\n------------------------------------------";
	cout<<"\n   HASH INDEX\t    PHONE NO.\t NAME";
	cout<<"\n------------------------------------------";
	for(i=0;i<MAX;i++)
	{
		
		cout<<"\n\t"<<i;
		iFlag=hash_t[i].display_contact();
		
	}
	cout<<"\n------------------------------------------";
	return 1;
}


int main()
{
	hashtable h;
	char cPhn[KEY];
	int iCh,i=0,iFlag;
	i=h.display_hash();
	i=h.read_hash();
	i=0;
	do
	{
here:	cout<<"\n-----------------------------------";
		cout<<"\n\t\tMENU";
		cout<<"\n-----------------------------------";
		cout<<"\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit";
		cout<<"\n-----------------------------------";
		cout<<"\nEnter your choice : ";
		cin>>iCh;
		switch(iCh)
		{
			case 1:	i=h.insert_hash();
					if(i!=-1)
					cout<<"\nInserted successfully!!!";
					i=0;	
					break;
				
			case 2:	i=h.display_hash();
					break;	
				
			case 3:	cout<<"\nEnter the number to be searched : ";
					cin>>cPhn;
					i=h.search_hash(cPhn);
					if(i==-1)
						cout<<"\nContact not found!";
					i=0;
					break;
				
			case 4:	cout<<"\nEnter the number to be deleted : ";
					cin>>cPhn;
					i=h.delete_hash(cPhn);
					if(i==-1)
					cout<<"\nContact no found for deletion!";
					break;
				
			case 5:	exit(0);
									
			default:goto here;		
		}
	}while(iCh!=5);
return 0;
}

/*
OUTPUT :
 
==========================
              LINEAR HASHING
==========================


------------------------------------------
   HASH INDEX	    PHONE NO.	 NAME
------------------------------------------
	0			
	1			
	2			
	3			
	4			
	5			
	6			
	7			
	8			
	9			
	10			
	11			
	12			
	13			
	14			
	15			
	16			
	17			
	18			
	19			
------------------------------------------
Enter the contact Name : abc

Enter the contact Number : 987

Add more? : y

Enter the contact Name : def

Enter the contact Number : 456

Add more? : n

-----------------------------------
		MENU
-----------------------------------
1.Insert
2.Display
3.Search
4.Delete
5.Exit
-----------------------------------
Enter your choice : 2

------------------------------------------
   HASH INDEX	    PHONE NO.	 NAME
------------------------------------------
	0			
	1			
	2			
	3			
	4			
	5		987	abc
	6			
	7			
	8			
	9			
	10			
	11		456	def
	12			
	13			
	14			
	15			
	16			
	17			
	18			
	19			
------------------------------------------
-----------------------------------
		MENU
-----------------------------------
1.Insert
2.Display
3.Search
4.Delete
5.Exit
-----------------------------------
Enter your choice : 1

Enter the contact Name : xyz

Enter the contact Number : 123

Inserted successfully!!!
-----------------------------------
		MENU
-----------------------------------
1.Insert
2.Display
3.Search
4.Delete
5.Exit
-----------------------------------
Enter your choice : 2

------------------------------------------
   HASH INDEX	    PHONE NO.	 NAME
------------------------------------------
	0			
	1			
	2			
	3			
	4			
	5		987	abc
	6			
	7			
	8			
	9			
	10			
	11		456	def
	12			
	13			
	14			
	15			
	16			
	17			
	18			
	19		123	xyz
------------------------------------------
-----------------------------------
		MENU
-----------------------------------
1.Insert
2.Display
3.Search
4.Delete
5.Exit
-----------------------------------
Enter your choice : 3

Enter the number to be searched : 123

Contact Found!
		123	xyz
-----------------------------------
		MENU
-----------------------------------
1.Insert
2.Display
3.Search
4.Delete
5.Exit
-----------------------------------
Enter your choice : 4

Enter the number to be deleted : 987

Contact Found!
		987	abc
Contact deleted successfully!
-----------------------------------
		MENU
-----------------------------------
1.Insert
2.Display
3.Search
4.Delete
5.Exit
-----------------------------------
Enter your choice : 5

*/

