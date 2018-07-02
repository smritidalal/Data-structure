#include<iostream>
using namespace std;

template<class t>
class node
{
  public:
	  t info;
	  node* next;

	  node(t x,node* n=0)
	  {
        info=x;
		next=n;
	  }
};

template<class t>
class sllist
{
   node<t> *head,*tail;
   public:
	   sllist()
	   {
         head=tail=0;
	   }
	   int isempty();
	   void addtohead(t);
	   void addtotail(t);
	   t deletefromhead();
	   t deletefromtail();
	   void deletenode(t);
	   void operator+(sllist<t>o1);
	   sllist<t> reverse();
	   void display();
	   void deleteithnode(int);
};

template<class t>
int sllist<t>::isempty()
{
  if(head==0)
	  return 1;
  else
	  return 0;
}

template<class t>
void sllist<t>::addtohead(t x)
{
  node<t> *temp=new node<t>(x);
  if(isempty())
  {
    head=tail=temp;
  }
  else
  {
    temp->next=head;
	head=temp;
  }
}


template<class t>
void sllist<t>::addtotail(t x)
{
  node<t> *temp=new node<t>(x);
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

template<class t>
t sllist<t>::deletefromhead()
{
 node<t> *temp;
 int x=head->info;
 if(head==tail)
 {
   delete head;
   head=tail=0;
 }
 else
 {
   temp=head;
   head=head->next;
   delete temp;
 }
 return x;
}

template<class t>
t sllist<t>::deletefromtail()
{
  node<t> *temp;
  int x=tail->info;
  if(head==tail)
  {
    delete head;
	head=tail=0;
  }
  else
  {
     temp=head;
	 while(temp->next!=tail)
	 {
       temp=temp->next;
	 }
	 delete (temp->next);
		 tail=temp;
	 tail->next=0;
  }
  return x;
}

template<class t>
void sllist<t>::display()
{
  node<t> *temp=head;
  while(temp!=0)
  {
    cout<<temp->info<<" ";
	temp=temp->next;
  }
}

template<class t>
void sllist<t>::deletenode(t x)
{
	node<t> *temp;
  if(head==tail && head->info==x)
  {
    delete head;
	head=tail=0;
  }

  else if(head->info==x)
  {
    temp=head;
	head=head->next;
	delete temp;
  }
  else
  {
    node<t> *prev=head;
	node<t> *cur=head->next;
	while(cur!=0 && cur->info!=x)
	{
      prev=cur;
	  cur=cur->next;
	}

	if(cur!=0)
	{
      prev->next=cur->next;
	  if(tail==cur)
	  {
        tail=prev;
	  }
	  delete cur;
	}
	else
		cout<<"Element not found...";
  }
}


template<class t>
void sllist<t>::deleteithnode(int i)
{
   
	int count=2;
	if(head==tail && i==1)
	{
		head=tail=0;
	}

	else
	{
       node<t> *prev=head, *cur=head->next;
	   while(cur!=0 && count!=i)
	   {
         prev=cur;
		 cur=cur->next;
		 count++;
	   }

	   if(cur!=0)
	   {
          prev->next=cur->next;
		  if(cur==tail)
			  tail=prev;
		  delete cur;
	   }

	   else
		   cout<<i<<"th node not found....";
	}
}

template<class t>
void sllist<t>::operator+(sllist<t>o1)
{
  node<t>*temp=o1.head;
  while(temp!=0)
  {
    addtotail(temp->info);
	temp=temp->next;
  }
 }

template<class t>
sllist<t> sllist<t>::reverse()
{
  sllist<t> o2;
  node<t>*temp=head;

  while(temp!=0)
  {
    o2.addtohead(temp->info);
	temp=temp->next;
  }
  return o2;
}

void main()
{
  sllist <int>o1,o2,o3;
  char c;
  int ch,x,y;
 
  
  do
  {

 cout<<"MENU:\n1.Add to head\n2.Add to tail\n3.Delete from head \n4.Delete from tail\n5.Delete node\n6.Delete ith node\n7.Display\n8.Concatenate\n9.Reverse\nEnter your choice::";
  cin>>ch;
  
  switch(ch)
  {
  case 1:cout<<"Enter a number to be inserted in the linked list::";
	     cin>>x;
		 o1.addtohead(x);
		 cout<<"Display linked list::";
		 o1.display();
		 break;

  case 2:cout<<"Enter a number to be inserted in the linked list::";
	     cin>>x;
		 o1.addtotail(x);
		 cout<<"Display linked list::";
		 o1.display();
		 break;
  
  case 3:if(!o1.isempty())
		 {
           int z=o1.deletefromhead();
		   cout<<z;
		 }
	  		 cout<<"Display linked list::";
		 o1.display();
		 break;
 
  case 4:if(!o1.isempty())
		 {
           int z=o1.deletefromtail();
		   cout<<z;
		 }
	  		 cout<<"Display linked list::";
		 o1.display();
		 break;
 
  case 5:if(!o1.isempty())
		 {
			 cout<<"Enter the element to be deleted:";
           cin>>x;
		   o1.deletenode(x);
		 }
	     cout<<"Display linked list::";
		 o1.display();
	     break;

  case 6:cout<<"Enter the node to be deleted::";
	     cin>>x;
         cout<<"Display linked list::";
		 o1.display();

		 o1.deleteithnode(x);
		 cout<<"Display linked list after deletion::";
		 o1.display();
         break;


  case 7:cout<<"Display the linked list::";
	     o1.display();
	  break;

  case 8:cout<<"Enter the first linked list::";
	  cin>>x;
	  o1.addtohead(x);
	  cout<<"Enter the elements of second linked list::";
	  cin>>y;
	  o2.addtohead(y);
	  o1+o2;
	  cout<<"Display the linked list after concatenation::";
          o1.display(); 
		  break;

  case 9:o2=o1.reverse();
	  cout<<"Display the linked list::";
	     o2.display();
  }
  
  cout<<"\nDo you want to continue....(y/n)::";
  cin>>c;
  } while(c=='y');
 

}