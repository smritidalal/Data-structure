#include<iostream>
using namespace std;

template <class T,int size>
class stack
{
	T a[size];
	int top;
	public:
		stack()
		{
			top=-1;
		}

		void push(T x);
		T pop();
		T topel()
		{
			t y;
			y=a[top];
			retuen y;
		}

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

		int isfull()
		{
			if(top==size-1)
				return 1;
			else
				return 0;
		}

		void display();
		void reverse();
};



template <class T,int size>
void stack<T,size>::push(T x)
{
    T y;
	if(isfull())
	 cout<<"OVERFLOW";
	else
		a[++top]=x;
}


template <class T,int size>
T stack<T,size>::pop()
{
	T y;
	if(isempty())
	{
		cout<<"Underflow";
		return (T)(-1);
	}
	else
	{
		y=a[top--];
		return y;
	}
}



template <class T,int size>
void stack<T,size>::display()
{
	if(!isempty())
	{
		for(int i=top;i>=0;i--)
		 cout<<a[i]<<"  ";
	}
	else
	{
		cout<<"Stack is empty";
	}
}


template <class T,int size>
class queue
{
	T a[size];
	int front,rear;
	public:
		queue()
		{
			front=rear=1;
		}

		void en(T x);
		T de();
		void clear()
		{
			front=rear=-1;
		}

		int isempty()
		{
			if(rear==-1)
				return 1;
			else 
				return 0;
		}
		int isfull()
		{
			if(rear==size-1)
				return 1;
			else
				return 0;
		}


		void display();
};


template <class T,int size>
void queue<T,size>::en(T x)
{
   if(isfull())
   cout<<"queue is full";
	else
		{
			++rear;
			a[rear]=x;
			if(front==-1)
				front=0;
		}
	}

	template <class T,int size>
		T queue<T,size>::de()
	{
		T y;
		if(isempty())
		{
			cout<<"EMPTY";
			return (T)(-1);
		}

		if(front==rear)
		{
			y=a[front];
			front=rear=-1;
		}
		else
		{
			y=a[front];
			front++;
		}
		return y;
	}


 template <class T,int size>
	 void queue<T,size>::display()
 {
	 if(!isempty())
	 {
		 for(int i=front;i<=rear;i++)
			 cout<<a[i]<<"  ";
	 }
	 else
	 {
		 cout<<"Queue is empty";
	 }
 }

 template <class T,int size>
void stack<T,size>::reverse()
 {
	 T x;
	 queue<int,10> q1;
	 while(!isempty())
	 {
		 x=pop();
		 q1.en(x);
	 }

	 while(!q1.isempty())
	 {
		 x=q1.de();
		 push(x);
	 }
 }


 void main()
 {
	 stack<int,10> o1;
	 int ele,n;

	 cout<<"Enter the no of elements in stack?"<<endl;
	 cin>>n;
     cout<<"Enter stack"<<endl;
	 for(int i=0;i<n;i++)
	 {
		 cin>>ele;
		 o1.push(ele);
	 }

	 cout<<"STACK"<<endl;
	 o1.display();
	 cout<<endl;
	 cout<<"ENTERED STACK IS"<<endl;
	 o1.reverse();
	 o1.display();
 }






