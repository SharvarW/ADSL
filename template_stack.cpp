
#include<iostream>
#define MAX 20
using namespace std;

template<class T>
class stack
{
	public:
	T r[MAX];
	int iTop;
	public:
		stack()
		{
			iTop=-1;
		}
		int IsEmpty();
		int IsFull();
		void push(T);
		T pop();
		T Top();	
};
template<class T>
int stack<T>::IsEmpty()
{
	if(iTop==-1)
	return 1;
	else
	return 0;
}
template<class T>
int stack<T>::IsFull()
{
	if(iTop==MAX-1)
	return 1;
	else
	return 0;
}
template<class T>
void stack<T>::push(T value)
{
	
	if(!IsFull())
	{
		iTop++;
		r[iTop]=value;
	}
}
template<class T>
T  stack<T>::pop()
{
	T tep;
	if(!IsEmpty())
	{
		tep=r[iTop];
		iTop--;
		return tep;
	}
}
template<class T>
T  stack<T>::Top()
{
	if(!IsEmpty())
	{
		return r[iTop];
	}
}
