/* 
# PROGRAM FOR EXPRESSION TREE
# NAME : SHARVARI S. WAGH
# SE(A): 73
*/
#include<iostream>
#include "stack.cpp"
#include"template_stack.cpp"
using namespace std;
class Binarytree
{
	public:
		Treenode *root;
		public:
			Binarytree()
			{
				root=NULL;	
			}
			Treenode* creat(char[]);
			void inorderNonRec(Treenode *root);
			void postNonRec(Treenode *root);
			void preNonRec(Treenode *root);
			void inorderRec(Treenode *root);
			void postRec(Treenode *root);
			void preRec(Treenode *root);
};
void Binarytree :: postNonRec(Treenode *root)
{
	char ch;
	stack<char>cSt;
	Stack s;
	Treenode *curr=root;
	do
	{
		while(curr!=NULL)
		{
			s.push(curr);
			cSt.push('l');
			curr=curr->left;
		}
		if(!s.IsEmpty())
		{
			ch=cSt.pop();
			curr=s.pop();
			if(ch=='l')
			{
				s.push(curr);
				cSt.push('r');
				curr=curr->right;
			}
			else
			{
				cout<<curr->data;
				curr=NULL;
			}
		}
		else
			break;
	}while(1);
	
}
Treenode* Binarytree::creat(char cStrpost[20])
{
	char cCh;
	Stack s;
	Treenode *curr;
	cout<<"\nPostfix Expression : "<<cStrpost;
	for(int i=0;cStrpost[i]!='\0';i++)
	{
		cCh=cStrpost[i];
		curr=new Treenode;
		curr->data=cCh;
		curr->left=NULL;
		curr->right=NULL;
		if(cCh>='a' && cCh<='z')
		{
			s.push(curr);	
		}
		else
		{
			curr->right=s.pop();
			curr->left=s.pop();
			s.push(curr);
		}
	}
	root=s.pop();
	return root;
	
}
void Binarytree::inorderRec(Treenode *root1)
{
	if(root1!=NULL)
	{
		inorderRec(root1->left);
		cout<<root1->data;
		inorderRec(root1->right);
	}	
}
void Binarytree::postRec(Treenode *root1)
{
	if(root1!=NULL)
	{
		postRec(root1->left);
		postRec(root1->right);
		cout<<root1->data;
		
	}	
}
void Binarytree::preRec(Treenode *root1)
{
	if(root1!=NULL)
	{
		cout<<root1->data;
		preRec(root1->left);
		preRec(root1->right);
	
	}	
}
void Binarytree::inorderNonRec(Treenode *curr)
{
	Stack s;
	Treenode *temp5;
	while(1)
	{
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		if(!s.IsEmpty())
		{
			curr=s.pop();
			cout<<curr->data;
			curr=curr->right;
		}
		else
		{
		
		break;
		}
	}
	
}
void Binarytree::preNonRec(Treenode *curr)
{
	Stack s;
	Treenode *temp5;
	while(1)
	{
		while(curr!=NULL)
		{
			s.push(curr);
			cout<<curr->data;
			curr=curr->left;
		}
		if(!s.IsEmpty())
		{
			curr=s.pop();
			curr=curr->right;
		}
		else
		{
		break;
		}
	}
}
int main()
{
	int iCh;
	char cStrpost[20];
	Binarytree b;
	Treenode *curr2;
	cout<<"\nEnter Postfix expression :	";
	cin>>cStrpost;
	curr2=b.creat(cStrpost);
	cout<<"\n";
	cout<<"\n----------------------------";
	cout<<"\n          MENU";
	cout<<"\n----------------------------";
	cout<<"\n1.Recursive Inorder\n2.Recursive Postorder\n3.Recursive Preorder\n4.Non-recursive Preorder\n5.Non-recursive Postorder\n6.Non-recursive Preorder\n";
	cout<<"\n----------------------------";
	cout<<"\nEnter Choice : ";
	cin>>iCh;
	switch(iCh)
	{
		case 1:	b.inorderRec(curr2);
			break;
		case 2:	b.postRec(curr2);
			break;
		case 3:	b.preRec(curr2);
			break;
		case 4:	b.inorderNonRec(curr2);
			break;
		case 5:	b.postNonRec(curr2);
			break;
		case 6:	b.preNonRec(curr2);
			break;
	}
	return 0;
	
}

/*
OUTPUT : 

Enter Postfix expression :	ab+c*

Postfix Expression : ab+c*

----------------------------
          MENU
----------------------------
1.Recursive Inorder
2.Recursive Postorder
3.Recursive Preorder
4.Non-recursive Preorder
5.Non-recursive Postorder
6.Non-recursive Preorder

----------------------------
Enter Choice : 1
a+b*c

./a.out

Enter Postfix expression :	ab+c*

Postfix Expression : ab+c*

----------------------------
          MENU
----------------------------
1.Recursive Inorder
2.Recursive Postorder
3.Recursive Preorder
4.Non-recursive Preorder
5.Non-recursive Postorder
6.Non-recursive Preorder

----------------------------
Enter Choice : 2
ab+c*

./a.out

Enter Postfix expression :	ab+c*

Postfix Expression : ab+c*

----------------------------
          MENU
----------------------------
1.Recursive Inorder
2.Recursive Postorder
3.Recursive Preorder
4.Non-recursive Preorder
5.Non-recursive Postorder
6.Non-recursive Preorder

----------------------------
Enter Choice : 3
*+abc
ab+c*

./a.out

Enter Postfix expression :	ab+c*   

Postfix Expression : ab+c*

----------------------------
          MENU
----------------------------
1.Recursive Inorder
2.Recursive Postorder
3.Recursive Preorder
4.Non-recursive Preorder
5.Non-recursive Postorder
6.Non-recursive Preorder

----------------------------
Enter Choice : 5
ab+c*

./a.out

Enter Postfix expression :	ab+c*

Postfix Expression : ab+c*

----------------------------
          MENU
----------------------------
1.Recursive Inorder
2.Recursive Postorder
3.Recursive Preorder
4.Non-recursive Preorder
5.Non-recursive Postorder
6.Non-recursive Preorder

----------------------------
Enter Choice : 6
*+abc

*/
