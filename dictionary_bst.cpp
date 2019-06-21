/* 
# PROGRAM FOR DICTIONARY USING BST
# NAME : SHARVARI S. WAGH
# SE(A): 73
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#define SIZE 20
#define MAX 50

using namespace std;

class Dnode
{
	
	public:
		char cWord[SIZE];
		char cMeaning[MAX];
		Dnode *left,*right;
		Dnode()
		{
			left=right=NULL;
		}
};

class Dictionary
{
	Dnode *root;
	public:
		Dictionary()
		{
			root=NULL;
		}
		int create();
		int display(Dnode *curr);
		Dnode * search(char str[20]);
		int insert();
		Dnode* ret_root();
		Dnode* delet(Dnode *temp,char str[20]);
		Dnode* min(Dnode *curr);
		Dnode* max(Dnode *curr);
};

Dnode* Dictionary :: ret_root()
{
	return root;
}

Dnode * Dictionary :: min(Dnode *curr)
{
	while(curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}

Dnode * Dictionary :: max(Dnode *curr)
{
	while(curr->right!=NULL)
	{
		curr=curr->right;
	}
	return curr;
}

int Dictionary ::insert()
{
	Dnode *curr,*temp=root;
	char cStr[SIZE];
	int j=0;
	curr=new Dnode;
	cout<<"\nEnter the word to be inserted : ";
	cin>>cStr;
	cout<<"\nEnter the meaning of the word : ";
	cin.ignore();
	cin.getline(curr->cMeaning,MAX);
	for(int i=0;cStr[i]!='\0';i++)		//for removing case sensitivity
	{
		if(cStr[i]>='A' && cStr[i]<='Z')
		{
			curr->cWord[j]=cStr[i]+32;
			j++;
		}
		else 						//if(cStr[i]>='a' && cStr[i]<='z')
		{
			curr->cWord[j]=cStr[i];
			j++;
		}
	}
	curr->cWord[j]='\0';

	while(temp!=NULL)
	{
		
		if(strcmp(curr->cWord,temp->cWord)<0)
		{
			if(temp->left==NULL)
			{
				temp->left=curr;
				break;
			}	
			temp=temp->left;
		}
		else
		{
			if(temp->right==NULL)
			{
				temp->right=curr;
				break;
			}
			temp=temp->right;
		}
	}
	return 1;
}

Dnode* Dictionary :: delet(Dnode *temp,char str[20])
{
	Dnode *curr=root;
	if(temp==NULL)
	{
		cout<<"\nWord not available";
		return temp;
	}
	else if(strcmp(temp->cWord,str)<0)
	{
		temp->right=delet(temp->right,str);
		return temp;
	}
	else if(strcmp(temp->cWord,str)>0)
	{
		temp->left=delet(temp->left,str);
		return temp;
	}
	else		//element found
	{
		if(temp->left==NULL && temp->right==NULL)//leafnode
		{
			delete temp;
			return NULL;
		}
		if(temp->left==NULL)
		{
			Dnode *curr=temp;
			temp=temp->right;
			delete curr;
			return temp;	
		}
		if(temp->right==NULL)
		{
			Dnode *curr=temp;
			temp=temp->left;
			delete curr;
			return temp;	
		}
		Dnode *curr=min(temp->right);
		strcpy(temp->cWord,curr->cWord);
		strcpy(temp->cMeaning,curr->cMeaning);
		temp->right=delet(temp->right,curr->cWord);
		
		return temp;
	}
}

Dnode * Dictionary :: search(char str[20])
{
	Dnode *curr=root;
	while(curr!=NULL)
	{
		if(strcmp(str,curr->cWord)==0)
		{
			cout<<"\nFound";
			return curr;
		}
		if(strcmp(str,curr->cWord)>0)
		{
			curr=curr->right;
		}
		if(strcmp(str,curr->cWord)<0)
		{
			curr=curr->left;	
		}
	}
	return NULL;
}

int Dictionary :: display(Dnode *curr)
{

	if(curr!=NULL)
	{
		display(curr->left);
		cout<<"\n"<<curr->cWord<<"\t : \t"<<curr->cMeaning;	
		display(curr->right);
	}	
	return 1;
}

int Dictionary :: create()
{
	char cAns,cStr[SIZE];
	int iAns;
	int iFlag=0,j;
	Dnode *curr,*temp;
	do
	{
		curr=new Dnode;
		cout<<"\nEnter the word :";
		cin>>cStr;
		j=0;
		for(int i=0;cStr[i]!='\0';i++)
		{
			if(cStr[i]>='A' && cStr[i]<='Z')
			{
				cStr[i]=cStr[i]+32;	
			}
			else	// if(cStr[i]>='a' && cStr[i]<='z')
			{
				cStr[i]=cStr[i];
			}
		}
		strcpy(curr->cWord,cStr);
		cin.ignore();
		cout<<"Enter the meaning :";
		cin.getline(curr->cMeaning,MAX);
		if(root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;		
			while(1)
			{
				if(strcmp(curr->cWord,temp->cWord)<0)
				{
					if(temp->left==NULL)
					{
						temp->left=curr;
						break;	
					}
					else
						temp=temp->left;
				}
				
				else
				{
					if(temp->right==NULL)
					{
						temp->right=curr;
						break;
					}
					else
						temp=temp->right;
				}
			}	
		}
			
		cout<<"\nAdd more?:(y/n)";
		cin>>cAns;
	}while(cAns=='y'||cAns=='Y');

	return 1;
}

int main()
{
	Dictionary d;
	int ch,iFlag=0,y; 
	char x[20],u;
	Dnode *curr=NULL;
	cout<<"\n-----------------------------------------\n";
	cout<<"\t\tDICTIONARY\n";
	d.create();
	do
	{
here:	cout<<"\n-------------------------------------\n";
		cout<<"\t\tMENU";
		cout<<"\n-------------------------------------\n";
		cout<<"\n1.Display\n2.Search word\n3.Insert new word\n4.Delete a word\n5.Exit\n";
		cout<<"\n-------------------------------------\n";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	d.display(d.ret_root());
					break;
			
			case 2:	cout<<"\nEnter the word to be searched : ";
					cin>>x;
					for(int i=0;x[i]!='\0';i++)
					{
						if(x[i]>='A' && x[i]<='Z')
						{
							x[i]=x[i]+32;
						}
						else
						{
							x[i]=x[i];
						}
					}
					curr=d.search(x);
					if(curr!=NULL)
						cout<<"\n"<<curr->cWord<<" : "<<curr->cMeaning;
					else
					{
						cout<<"\nNo such word present in Dictionary.\nWould you like to enter the word?(y/n) : ";
						cin>>u;
						if(u=='Y'||u=='y')
						{
							y=d.insert();	
						}
						if(y!=0)
						cout<<"\nWord inserted successfully!!!";
						y=0;
					}
						
					break;
				
			case 3:	y=d.insert();
					if(y!=0)
						cout<<"\nWord inserted successfully!!!";
					y=0;
					break;
								
			case 4:	cout<<"\nEnter the word to be deleted : ";
					cin>>x;
					curr=d.delet(d.ret_root(),x);
					if(curr!=NULL)
						cout<<"\nWord deleted successfully!!!";
					curr=NULL;
					break;
				
			case 5:	exit(0);
			
			default:	goto here;	
		}
			
	}while(ch!=6);
	
	return 0;
}

/*
OUTPUT : 

-----------------------------------------
		              DICTIONARY

Enter the word :mango
Enter the meaning :a fruit

Add more?:(y/n)y

Enter the word :orange
Enter the meaning :a color

Add more?:(y/n)n

-------------------------------------
		                    MENU
-------------------------------------

1.Display
2.Search word
3.Insert new word
4.Delete a word
5.Exit

-------------------------------------

Enter your choice : 1

mango	 : 	a fruit
orange	 : 	a color
-------------------------------------
		                     MENU
-------------------------------------

1.Display
2.Search word
3.Insert new word
4.Delete a word
5.Exit

-------------------------------------

Enter your choice : 3

Enter the word to be inserted : apple

Enter the meaning of the word : a fruit

Word inserted successfully!!!
-------------------------------------
		                    MENU
-------------------------------------

1.Display
2.Search word
3.Insert new word
4.Delete a word
5.Exit

-------------------------------------

Enter your choice : 1    

apple	 : 	a fruit
mango	 : 	a fruit
orange	 : 	a color
-------------------------------------
		                   MENU
-------------------------------------

1.Display
2.Search word
3.Insert new word
4.Delete a word
5.Exit

-------------------------------------

Enter your choice : 2

Enter the word to be searched : mango

Found
mango : a fruit
-------------------------------------
		                   MENU
-------------------------------------

1.Display
2.Search word
3.Insert new word
4.Delete a word
5.Exit

-------------------------------------

Enter your choice : 5

*/

