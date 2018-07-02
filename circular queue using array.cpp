#include<iostream>
using namespace std;
const int size = 5;
class cqueue
{
	int a[size],front,rear;
   public :
		   cqueue()
		   {
			 front=rear=-1;
		   }
		   void push(int );
		   int pop();
		   void display();
	  };

	  void cqueue :: push(int x)
	  {
		 if((front==0 && rear==size-1) || (rear+1==front))
			  cout<<" Circular Queue is Full";
		 else
		 {
		   if(rear==size-1)
			  rear=0;
		   else
			 rear++;
		   a[rear]=x;
		 }
		 if(front==-1)
		   front=0;
	  }


	  int cqueue :: pop()
	  {
		 int y;
		 if(front==-1)
			cout<<"Circular Queue is Empty";
		 else
		 {
			y=a[front];
			if(front==rear)
			   front=rear=-1;
			else
			{
			   if(front==size-1)
				  front=0;
			   else
				  front++;
			}
		 }
		 return y;
	  }


	  void cqueue :: display()
	  {
		  int i;
		  if(front==-1)
			 cout<<"Circular Queue is Empty";
		  else
		  {
			 if(rear < front)
			 {
				for(i=front;i<=size-1;i++)
				   cout<<a[i]<<"   ";
				for(i=0;i<=rear;i++)
				   cout<<a[i]<<"   ";
			 }
			 else
			 {
				for(i=front;i<=rear;i++)
				   cout<<a[i]<<"   ";
				cout<<endl;
			 }
		  }
	  }

	  void main()
	  {
		 cqueue o1;

		 int ch,x;
		 char n;
		 do
		 {
		   
		   cout<<"---Menu---"<<endl;
		   cout<<"1.Push"<<endl;
           cout<<"2.Pop"<<endl;
		   cout<<"3.Display"<<endl;
		   cout<<"Enter Your Choice ?";
		   cin>>ch;
		   switch(ch)
		   {
			   case 1 : cout<<"Enter Element to Insert ?";
						cin>>x;
						o1.push(x);
						break;

			   case 2 : x=o1.pop();
						cout<<"Deleted Element :"<<x<<endl;
						break;

			   case 3 : o1.display();
						break;
			}
			cout<<"Do you want to continue<Y/N> ?";
			cin>>n;
		  }while(n=='Y' || n=='y');
		  
		}

