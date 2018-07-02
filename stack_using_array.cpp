// using array
#include<iostream>
using namespace std;

template<class t,int size=10>
class stack
{
	t a[size];
	int top;
	public:
		stack()
		{
			top=-1;
		}
	void push(t x);
	t pop();
	t topele();
	void clear()
	{
		top=-1;
	}
	int isempty()
	{
		if(top==-1)
			return 1;
		else 
			return 0;
	}
	void display();
	int isful()
	{
		if(top==size-1)
			return 1;
		else 
			return 0;

	}
};
template<class t,int size>
void stack<t,size>::push(t x)
{
	if(isful())
		cout<<"stack overflow";
	else
		a[++top]=x;
}
template<class t,int size>
t stack<t,size>::pop()
{
	t y;
	if(isempty())
	{
		cout<<"stack overflow";
	
	}
	else
	{
		y=a[top--];
}
	return y;
}
template<class t,int size>
void stack<t,size>::display()
{
	int i;
	if(!isempty())
	{
		for(i=top;i>=0;i--)
			cout<<a[i];
	}
	else
		cout<<"stack is empty";
}
template<class t,int size>
t stack<t,size>::topele()
{
	return a[top];
}
void main()
{
	int x,ch,z;
	char y;
	stack<int,5>o1;

do	{
	cout<<endl<<"MENU"<<endl;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.top element"<<endl;
	cout<<"4.clear\n";
	cout<<"Enter your choice";
	cin>>ch;
	switch(ch)
	{
		case 1:cout<<"\nEnter value you want to insert:: ";
			cin>>x;
			o1.push(x);
			cout<<"\nStack is..\n";
			o1.display();
			break;
		case 2:cout<<"\nAfter pop\n";
			 z=o1.pop();
			cout<<"The no. is deleted:: ";
			cout<<z;
			o1.display();
			break;
		case 3:cout<<"top element";
			z=o1.topele();
			cout<<z;
			break;
		case 4:o1.clear();
			cout<<"Now stack is..::\n";
				o1.display();
			break;
	}
cout<<"\nDo You to continue....(y/n) ";
cin>>y;
}while(y=='y'||y=='Y');
}