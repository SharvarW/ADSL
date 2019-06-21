/* 
# PROGRAM FOR HASH TABLE CHAINING
# NAME : SHARVARI S. WAGH
# SE(A): 73
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
#define SIZE 10
#define MAX 30
using namespace std;

class word
{public:
	int iIndex;
	char cWord[SIZE];
	char cMeaning[MAX];
	
	
		word *next;
		word()
		{
			iIndex=0;
			strcpy(cWord,"");
			strcpy(cMeaning,"");
			next=NULL;
		}
		word* read_word(word *x);
		int display_word(word *x);
		char* ret_word();
		int put_index(int x);
		int get_index();
};

int word :: display_word(word *x)
{
	cout<<"\t\t"<<x->cWord<<"\t\t"<<x->cMeaning;
	return 1;
}

char* word :: ret_word()
{
	return cWord;
}

word* word :: read_word(word *x)
{
	cout<<"\nEnter the word : ";
	cin>>x->cWord;
	for(int i=0;cWord[i]!='\0';i++)
	{
		if(cWord[i]>='A' && cWord[i]<='Z')
		{
			cWord[i]=cWord[i]+32;
		}
	}
	cout<<"\nEnter the meaning : ";
	cin.ignore();
	cin.getline(x->cMeaning,MAX);
	return x;	
}

int word :: put_index(int x)
{
	iIndex=x;
	return 1;
}

int word :: get_index()
{
	return iIndex;
}

class Dictionary
{
	word *tb[MAX];
	public:
		Dictionary()
		{
			int f;
			for(int i=0;i<MAX;i++)
			{
				tb[i]=NULL;
			}
		}
		int hash_value(char cStr[SIZE]);
		int search(char cStr[SIZE]);
		int insert();
		int display();
		int create();
		int delete_word(char cStr[SIZE]);
};

int Dictionary :: delete_word(char cStr[SIZE])
{
	word *temp,*curr;
	int iX,iFlag=0;
	iX=hash_value(cStr);
	temp=curr=tb[iX];
	curr=curr->next;
	
	while(curr!=NULL)
	{
		if(strcmp(curr->ret_word(),cStr)==0)
		{
			iFlag=1;	
			break;
		}
		temp=temp->next;
		curr=curr->next;
	}
	
	if(iFlag==1)
	{
		temp->next=curr->next;
		delete curr;
		cout<<"\nWord deleted!";
		return 1;
	}
	
	return -1;
		
}

int Dictionary :: create()
{
	int iX;
	char cAns;
	word *curr,*temp;
	for(int i=0;i<MAX;i++)
	{
		tb[i]=new word;
		tb[i]->put_index(i);
		strcpy(tb[i]->cWord,"");
		strcpy(tb[i]->cMeaning,"");	
	}	
	
	do
	{
		curr=new word;
		curr->read_word(curr);
	 	iX=hash_value(curr->ret_word());
 		temp=tb[iX];
		curr->next=tb[iX]->next;
		tb[iX]->next=curr;
		cout<<"\nAdd more?(y/n) : ";
		cin>>cAns;
	}while(cAns=='y'||cAns=='Y');
	
	return 1;	
}

int Dictionary :: hash_value(char cStr[SIZE])
{
	int iSum=0,key;
	for(int i=0;cStr[i]!='\0';i++)
	{
		if(i%2==0)
			iSum=iSum+cStr[i];
	}
	return iSum%MAX;
}

int Dictionary :: display()
{
	word *curr;
	int m;
	cout<<"\n--------------------------------------------";
	cout<<"\n   Hash\t\tWord\t\tMeaning";
	cout<<"\n--------------------------------------------";
	for(int i=0;i<MAX;i++)
	{
		curr=tb[i];
		curr=curr->next;
		cout<<"\n   "<<i<<". ";
		while(curr!=NULL)
		{
			cout<<"\n";
			m=curr->display_word(curr);
			curr=curr->next;
		}
			
		cout<<"\n";
	}
	cout<<"\n--------------------------------------------";
	return 1;
}

int Dictionary :: insert()
{
	int iX;
	
	
	word *curr=new word,*temp;
	curr->read_word(curr);
	cout<<curr->ret_word();
 	iX=hash_value(curr->ret_word());
 	temp=tb[iX];
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=curr;
	
	return 1;
	
}

int Dictionary :: search(char cStr[SIZE])
{
	word *curr;
	int iX,v;
	iX=hash_value(cStr);
	curr=tb[iX];
	while(curr!=NULL)
	{
		if(strcmp(curr->ret_word(),cStr)==0)
		{
			cout<<"\nFound\n";
			cout<<"\n   \t\tWord\t\tMeaning";
			cout<<"\n--------------------------------------------\n";
			v=curr->display_word(curr);
			return 1;
		}
		curr=curr->next;
	}
	
	return -1;	
}



int main()
{
	Dictionary d;
	int x=0,iChoice;
	char cStr[3];
	cout<<"\n------------------------------";
	cout<<"\n\t DICTIONARY";
	cout<<"\n------------------------------";
	x=d.create();
	do
	{
here:	cout<<"\n\n----------------------\n\tMENU\n----------------------";
		cout<<"\n1.Display\n2.Insert word\n3.Search word\n4.Delete word\n5.Exit";
		cout<<"\n----------------------\n";
		cout<<"Enter your choice :";
		cin>>iChoice;
		switch(iChoice)
		{
			case 1:	x=d.display();
					x=0;
					break;
					
			case 2:	x=d.insert();
					x=0;
					break;
					
			case 3:	cout<<"\nEnter search word : ";
					cin>>cStr;
					x=d.search(cStr);
					if(x==-1)
						cout<<"\nWord not present!";
					x=0;
					break;
					
			case 4:	cout<<"\nEnter delete word :";
					cin>>cStr;
					x=d.delete_word(cStr);
					if(x==-1)
						cout<<"\nWord not present!";
					break;
					
			case 5:	exit(0);
			
			default:	cout<<"\nInvalid choice!";
					goto here;
		}
	}while(iChoice!=5);
	return 0;
}

/*
OUTPUT : 
------------------------------
	            DICTIONARY
------------------------------
Enter the word : mango

Enter the meaning : a fruit

Add more?(y/n) : y

Enter the word : giraffe

Enter the meaning : an animal

Add more?(y/n) : y

Enter the word : zoo 

Enter the meaning : zoological park

Add more?(y/n) : y

Enter the word : cat

Enter the meaning : an animal

Add more?(y/n) : n


----------------------
	        MENU
----------------------
1.Display
2.Insert word
3.Search word
4.Delete word
5.Exit
----------------------
Enter your choice :1

--------------------------------------------
   Hash		    Word		             Meaning
--------------------------------------------
   0. 
		        giraffe		                  an animal
		        mango		                  a fruit

   1. 

   2. 

   3. 

   4. 

   5. 
		          cat		                  an animal

   6. 

   7. 

   8. 

   9. 

   10. 

   11. 

   12. 

   13. 

   14. 

   15. 

   16. 

   17. 

   18. 

   19. 

   20. 

   21. 

   22. 

   23. 
		           zoo	                    zoological park

   24. 

   25. 

   26. 

   27. 

   28. 

   29. 

--------------------------------------------

----------------------
	          MENU
----------------------
1.Display
2.Insert word
3.Search word
4.Delete word
5.Exit
----------------------
Enter your choice :2

Enter the word : apple

Enter the meaning : a fruit
apple

----------------------
	          MENU
----------------------
1.Display
2.Insert word
3.Search word
4.Delete word
5.Exit
----------------------
Enter your choice :1

--------------------------------------------
   Hash		   Word		               Meaning
--------------------------------------------
   0. 
		       giraffe		            an animal
		       mango		            a fruit

   1. 

   2. 

   3. 

   4. 

   5. 
		        cat		                     an animal

   6. 

   7. 

   8. 

   9. 

   10. 
		       apple		              a fruit

   11. 

   12. 

   13. 

   14. 

   15. 

   16. 

   17. 

   18. 

   19. 

   20. 

   21. 

   22. 

   23. 
		        zoo		                        zoological park

   24. 

   25. 

   26. 

   27. 

   28. 

   29. 

--------------------------------------------

----------------------
	         MENU
----------------------
1.Display
2.Insert word
3.Search word
4.Delete word
5.Exit
----------------------
Enter your choice :4

Enter delete word :zoo 

Word deleted!

----------------------
	        MENU
----------------------
1.Display
2.Insert word
3.Search word
4.Delete word
5.Exit
----------------------
Enter your choice :4

Enter delete word :star

Word not present!

----------------------
	         MENU
----------------------
1.Display
2.Insert word
3.Search word
4.Delete word
5.Exit
----------------------
Enter your choice :5

*/

