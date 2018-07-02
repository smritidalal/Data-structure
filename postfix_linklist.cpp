#include<iostream>
using namespace std;

template<class T>
class node
{
	public: T info;
			node *next;
			node(T x, node *n=NULL)
			{
				info=x;
				next=n;
			}
};

template<class T>
class stack
{
	node<T> *top;
	public: stack()
			{
				top=NULL;
			}
			void push(T);
			T pop();
			void display();
			int isempty();
			void evaluate(int a,int b,char c);
};


template<class T>
void stack<T>::push(T x)
{
	node<T> *temp=new node<T>(x);
	if(isempty())
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}


template<class T>
T stack<T>::pop()
{
	node<T> *temp;
	T x;
	x=top->info;

	if(top->next==NULL)
	{
		delete top;
		top=NULL;
	}
	else
	{
		temp=top;
		top=top->next;
		delete temp;
	}
	return x;
}

template<class T>
void stack<T>::display()
{
	node<T> *temp;
	temp=top;
	while(temp!=NULL)
	{
		cout<<temp->info;
		temp=temp->next;
	}
}


template<class T>
int stack<T>::isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}


template <class T>
void stack<T> :: evaluate(int a,int b,char ch)
{
   
	if(ch=='+')
	{
	  push(a+b);
	}

   else if(ch=='-')
   {
	   push(a-b);
   }

   else if(ch=='/')
   { 
	   push(a/b);
   }

   else if(ch=='*')
   { 
	   push(a*b);
   }

}


void main()
{
   int x,y,r;
  stack<int> o1;
 char a[15];
   cout<<"Enter your expression::";
   cin>>a;

 for(int i=0;a[i]!='\0';i++)
{

   if(isdigit(a[i]))
   {
     o1.push(a[i]-48);
   }
   
   else if(a[i]=='+' || a[i]=='*' || a[i]=='-' || a[i]=='/')
   {
      char c=a[i];
      x=o1.pop();
      y=o1.pop();
      o1.evaluate(x,y,c);
   }
   
}

 r=o1.pop();
 cout<<"\nResult:"<<r;
}