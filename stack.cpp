#include<iostream>
#define MAX 20
using namespace std;
class Treenode
{
	public:
	char data;
	struct Treenode *left,*right;
};


class Stack
{
	public:
	Treenode *r[MAX];
	int iTop;
	public:
		Stack()
		{
			iTop=-1;
		}
		int IsEmpty();
		int IsFull();
		int push(Treenode *curr );
		Treenode* pop();
		Treenode* Top();	
};

int Stack::IsEmpty()
{
	if(iTop==-1)
	return 1;
	else
	return 0;
}

int Stack::IsFull()
{
	if(iTop==MAX-1)
	return 1;
	else
	return 0;
}

int Stack::push(Treenode *curr )
{
	
	if(!IsFull())
	{
		iTop++;
		r[iTop]=curr;
	}
}

Treenode*  Stack::pop()
{
Treenode *curr;
	if(!IsEmpty())
	{
		curr=r[iTop];
		iTop--;
		return curr;
	}
}

Treenode*  Stack::Top()
{
	if(!IsEmpty())
	{
		return r[iTop];
	}
}
