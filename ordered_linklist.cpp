#include<iostream>
using namespace std;
template<class t>
class node
{
public:
	t info;
	node *next;
	node(t x,node*n=0)
	{
		info=x;
		next=n;
	}
};
template<class t>
class sllist
{
	node<t> *head;
public:
	sllist()
	{head=0;}
	void insertion(t);
	t deletion(t);
	int isempty();

	void display();
    sllist merge(sllist);
};
template<class t>
sllist<t> sllist<t>::merge(sllist<t> s1)
{
	sllist<t> s3;
	node<t> *temp,*temp1;
	temp=head;
	temp1=s1.head;
	while(temp!=0 && temp1!=0)
	{
		if(temp->info<=temp1->info)
		{
			s3.insertion(temp->info);
			temp=temp->next;
		}
		else
		{
			s3.insertion(temp1->info);
			temp1=temp1->next;
		}
	}
		if(temp!=0)
		{
			while(temp!=0)
			{
				s3.insertion(temp->info);
				temp=temp->next;
			}
		}
		if(temp1!=0)
		{
			while(temp1!=0)
			{
				s3.insertion(temp1->info);
				temp1=temp1->next;
			}
		}
	
	return s3;
}
template<class t>
int sllist<t>::isempty()
{
	if(head==0)
		return 1;
	else
		return 0;
}
template<class t>
t sllist<t>::deletion(t x)
{
	if(head->next==0&&head->info==x)
	{
		delete head;
		head=0;
	}
	else if(head->info==x)
	{
		t x=head->info;

		node<t>*temp=head;
		head=head->next;
		delete temp;
	
		cout<<x<<"deleted";
	}
	else
	{
		node<t>*prev=head;
		node<t>*cur=head->next;
		while(cur!=0&&cur->info!=x)
		{
			prev=cur;
			cur=cur->next;
		}
		if(cur!=0)
		{
			prev->next=cur->next;
			delete cur;
		}
		else
			{
				cout<<"element not found";
			}
	}
	return x;
}

template<class t>
void sllist<t>::insertion(t x)
{
	node<t> *temp=new node<t>(x);
	if(isempty())
	{
		head=temp;
	}
	else
	{
		node<t>*prev=0;
		node<t>*cur=head;
		while(cur!=0 && cur->info<=x)
		{
			prev=cur;
			cur=cur->next;
		}
			if(prev==0)
			{
				temp->next=head;
				head=temp;
			}
			else
			{temp->next=prev->next;
			prev->next=temp;
			}
				
	}

		}
	

template<class t>
void sllist<t>::display()
{
	node<t>*temp;
	temp=head;
	while(temp!=0)
	{
		cout<<temp->info;
		temp=temp->next;
	}
}
void main()
{
	sllist<int> s1,s2,s3;
	char ch,b;
	int a,e,f,c;
	do
	{
		cout<<"===Menu:=== \n1.insert element \n2.Delete any element \n3.merge linllist \n4.display \nEnter Your choice... :) \n";

	cin>>c;
	switch(c)
	{
	case 1:cout<<"enter element";
		cin>>e;
		s1.insertion(e);
		break;

	case 2:cout<<"\nLink list before deletion:\n";
		s1.display();
		cout<<"\nEnter the element you want to delete: ";
	    cin>>a;
	    s1.deletion(a);
		cout<<"\nLink list after deletion:\n";
	    s1.display();
		break;

	case 3:do
		   {
		cout<<"\nEnter element for second linklist: ";
		cin>>f;
		s2.insertion(f);
		cout<<"Do you want to insert more element in second linklist...(y/n)  ";
		cin>>b;
		   }
		while(b=='Y' || b=='y');
		
        s3=	s2.merge(s1);
	    cout<<"\nMerged linked list is:\n";
	    s3.display();
		break;

	case 4:cout<<"\nLink list :\n";
	    s1.display();
		break;
	}
		
		cout<<"\nDo you want to continue the program..(y/n)..:";
		cin>>ch;

	}
	while(ch=='Y' || ch=='y');
}
