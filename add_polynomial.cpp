#include<iostream>
using namespace std;

template<class T>
class node
{
	public: T info;
			T power;
			node *next;
			node(T x,T p, node *n=NULL)
			{
				info=x;
				next=n;
				power=p;
			}
};

template<class T>
class SLList 
{
	node<T> *head,*tail;

	public:
		SLList()
		{
			head=tail=NULL;
		}

		int isempty();
		void insert(T x,T p);
		void addtotail(T,T);
		void display();
		SLList<T> add(SLList<T>);


};

template<class T>
int SLList<T>::isempty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}


template<class T>
void SLList<T>::addtotail(T x,T P)
{
	node<T> *temp=new node<T>(x,P);

	if(isempty())
	{
		head=tail=temp;
	}
	else
	{
		tail->next=temp;
		tail=temp;
	}
}



template<class T>
void SLList<T>::display()
{
	node<T> *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		cout<<temp->info<<"x^"<<temp->power<<" ";
	}
}

template<class T>
SLList<T> SLList<T>::add(SLList<T> s2)
{
	node<T> *temp1, *temp2;
	SLList<T> l3;
	temp1=head;
	temp2=s2.head;
	while(temp1!=NULL || temp2!=NULL)
	{
		if(temp1->power==temp2->power)
		{
			T x=temp1->info+temp2->info;
			l3.addtotail(x,temp1->power);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->power>temp2->power)
		{
			l3.addtotail(temp1->info,temp1->power);
			temp1=temp1->next;
		}
		else if(temp1->power<temp2->power)
		{
			l3.addtotail(temp2->info,temp2->power);
			temp2=temp2->next;
		}
	}

	if(temp1!=NULL)
	{
		while(temp1!=NULL)
		{
			l3.addtotail(temp1->info,temp1->power);
			temp1=temp1->next;
		}
	}
	else
	{
		while(temp2!=NULL)
		{
			l3.addtotail(temp2->info,temp2->power);
			temp2=temp2->next;
		}
		
	}
	return l3;
}

void main()
{
	SLList<int> s1,s2,s3;
	char ch;
	int coff, pow,c;

	do
	{
		cout<<"\n===MENU=== \n1.Enter First Polynomial.. \n2.Enter second Polynomial...\n3.ADD polynomial...\n\nENTER YOUR CHOICE....";
		cin>>c;

		switch(c)
		{

		case 1:	cout<<"\n Enter first polynomials:\n";
			do
			{
				
		        cout<<"\n Enter coefficient of x: ";
		        cin>>coff;

		        cout<<"\n Enter power of x: ";
		        cin>>pow;

		        s1.addtotail(coff,pow);
			
		        
		        

				cout<<"\n Enter more terms?(y/n)\n";
				cin>>ch;

			}while(ch=='y' || ch=='Y');

			cout<<"\n..Display Polynomial...\n";

			s1.display();
			break;


		case 2:cout<<"\n Enter second polynomials:";
			do
			{
				cout<<"\n Enter term: ";
		        cout<<"\n Enter coefficient of x: ";
		        cin>>coff;

		        cout<<"\n Enter power of x: ";
		        cin>>pow;

		        s2.addtotail(coff,pow);
		        
		        

				cout<<"\n Enter more terms?(y/n)\n";
				cin>>ch;

			}while(ch=='y' || ch=='Y');

 			cout<<"\n...Display Polynomial...\n";

			s2.display();
			break;

		case 3: cout<<"\nADDING POLYNNOMIALS....\n";
			    s3=s1.add(s2);
				s3.display();
				break;
		}

		cout<<"\n\nDo You Want to coninue...(y/n)";
		cin>>ch;

	}while(ch=='y' || ch=='Y');

}