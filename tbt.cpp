/* 
# PROGRAM FOR THREADED BINARY TREE
# NAME : SHARVARI S. WAGH
# SE(A): 73
*/

#include<iostream>
#include<cstdlib>
using namespace std;

struct TBTnode
{
	int iData;
	TBTnode *left,*right;
	bool bLthread,bRthread;
	TBTnode()
	{
		left=NULL;
		right=NULL;
		bLthread=bRthread=1;
	}
	
};

class TBT
{
	public:
		TBTnode *head,*root;
		TBT()
		{
			head=root=NULL;
		}
		void create();
		void insert(int x);
		void inorder(TBTnode *);
		void preorder(TBTnode *);
		void postorder(TBTnode *);
};

void TBT :: preorder(TBTnode *root)
{
	TBTnode *temp=root;
	bool flag=0;
	if(root==NULL)
		cout<<"\nTree not present";

	else
	{
		while(temp!=head)
		{
			if(flag==0)
				cout<<"\t"<<temp->iData;
			if(temp->bLthread==0 && flag==0)
			{
				
				temp=temp->left;
			}
			else
			{
				if(temp->bRthread==0)
				{
					temp=temp->right;
					flag=0;
				}
				else
				{
					temp=temp->right;
					flag=1;
				}
			}
		}//while
	}
}

void TBT :: insert(int x)
{
	TBTnode *curr,*temp=root;
	curr=new TBTnode;
	curr->iData=x;
	curr->left=curr->right=head;

	while(1)
	{
		if(temp->iData>x)
		{
			if(temp->bLthread==1)
			{
				curr->left=temp->left;
				curr->right=temp;
				temp->left=curr;
				temp->bLthread=0;
				break;
			}
			else
				temp=temp->left;
		}
		else
		{
			if(temp->bRthread==1)
			{
				curr->right=temp->right;
				curr->left=temp;
				temp->right=curr;
				temp->bRthread=0;
				break;
			}
			else
				temp=temp->right;
		}	
	}
}

void TBT :: create()
{
	TBTnode *curr,*temp;
	char cAns;
	head=new TBTnode;
	head->right=head;
	do
	{
		curr=new TBTnode;
		cout<<"\nEnter the data : ";
		cin>>curr->iData;
		curr->left=curr->right=head;
		if(root==NULL)
		{        
			root=curr;
			head->left=root;
			head->bLthread=0;	
		}
		else
		{
			temp=root;
			while(1)
			{
				if(curr->iData<temp->iData)
				{
					if(temp->bLthread==1)
					{
						curr->left=temp->left;
						curr->right=temp;
			
						temp->left=curr;
						temp->bLthread=0;
						break;
					}
				    else
						temp=temp->left;
			     	}
			    else
			    {
					if(temp->bRthread==1)
					{
						curr->right=temp->right;
						curr->left=temp;
			
						temp->right=curr;
						temp->bRthread=0;
						break;
					}
					else
						temp=temp->right;
			      	}
	                 }//end of while
	    	 }
		cout<<"\nAdd more?";
                cin>>cAns;
	}while(cAns=='y'||cAns=='Y');
}

void TBT :: inorder(TBTnode *root)
{
	TBTnode *temp=root;
	bool flag=0;
	if(root==NULL)
		cout<<"\nTree not present";
	else
	{
		while(temp!=head)
		{
			if(temp->bLthread==0 && flag==0)
			{
				temp=temp->left;
			}
			else
			{
				cout<<"\t"<<temp->iData;
				if(temp->bRthread==0)
				{
					temp=temp->right;
					flag=0;
				}
				else
				{
					temp=temp->right;
					flag=1;
				}			
			}		
		}//while
	}
}






int main()
{
	cout<<"\n------------------------------------------";
	cout<<"\n\tTHREADED BINARY TREE";
	cout<<"\n------------------------------------------";
	TBT tb;
	int x,ch;
	tb.create();
	do
	{
	here:	cout<<"\n----------------------";
		cout<<"\n\tMENU";
		cout<<"\n----------------------";
		cout<<"\n1.Insert\n2.Inorder\n3.Preorder\n4.Exit";
		cout<<"\n----------------------";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:	cout<<"\nEnter the data to be inserted : ";
				cin>>x;
				tb.insert(x);
				break;
				
			case 2:	tb.inorder(tb.root);
				break;
				
			case 3:	tb.preorder(tb.root);
				break;
				
			case 4:	exit(0);
			
			default:goto here;
		}
		
	}while(ch!=4);
	return 0;
}

/*
OUTPUT : 
------------------------------------------
	             THREADED BINARY TREE
------------------------------------------
Enter the data : 55

Add more?y

Enter the data : 23

Add more?y

Enter the data : 95

Add more?y

Enter the data : 44

Add more?y

Enter the data : 3

Add more?y

Enter the data : 1

Add more?y

Enter the data : 100

Add more?n

----------------------
	          MENU
----------------------
1.Insert
2.Inorder
3.Preorder
4.Exit
----------------------
Enter your choice : 2

	1	3	23	44	55	95	100
----------------------
	        MENU
----------------------
1.Insert
2.Inorder
3.Preorder
4.Exit
----------------------
Enter your choice : 3
	55	23	3	1	44	95	100
----------------------
	         MENU
----------------------
1.Insert
2.Inorder
3.Preorder
4.Exit
----------------------
Enter your choice : 1

Enter the data to be inserted : 75

----------------------
        	MENU
----------------------
1.Insert
2.Inorder
3.Preorder
4.Exit
----------------------
Enter your choice : 1

Enter the data to be inserted : 77

----------------------
	         MENU
----------------------
1.Insert
2.Inorder
3.Preorder
4.Exit
----------------------
Enter your choice : 2
	1	3	23	44	55	75	77	95	100
----------------------
	          MENU
----------------------
1.Insert
2.Inorder
3.Preorder
4.Exit
----------------------
Enter your choice : 4

*/



