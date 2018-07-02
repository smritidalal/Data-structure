#include<iostream>
using namespace std;



//queue class
template<class t>
class node
{
	public:
		t info;
		node *next;
		node(t x,node *n=0)
		{
			info = x;
			next =n;
		}
};



template<class t>
class queue
{
	node<t>*front ,*rear;
  int top;
	public:
		queue()
		{
			top=-1;
			front=rear=0;
		}
		
		int isempty();
		void enqueue(t);
		t dequeue();
		
};

template<class t>
int queue<t>::isempty()
{
	if(front==0)
		return 1;
	else
		return 0;
}


template<class t>
void queue<t>::enqueue(t x)
{
	node<t>*temp=new node<t>(x);
	if(isempty())
	{
		rear=front=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}
template<class t>
t queue<t>::dequeue()
{
	node<t> *temp;
	t x=front->info;
	if(front==rear)
	{
		delete front;
		front=rear=0;
	}
	else
	{
		temp=front;
		front=front->next;
		delete temp;
	}
	return x;
}

//class stack

template<class t>
class stack
{
	node<t> *top;
		public:
			stack()
			{
				top=0;
			}
void push(t);
t pop();
int isempty();

};


template<class t>
void stack<t>::push(t x)
{
	node<t>*temp=new node<t>(x);
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
template<class t>
t stack<t>::pop()
{
	node<t>*temp;
	t x;
	x=top->info;
	if(top->next==0)
	{
		delete top;
		top=0;
	}
	else
	{
		temp=top;
		top=top->next;
		delete temp;
	}
	return x;
}


template<class t>
int stack<t>::isempty()
{
	if(top==0)
		return 1;
	else 
		return 0;
}


//class BSTree

template<class t>
class BSTnode
{
  public:
	  t info;
	  BSTnode *left, *right;
	  int level;
	  BSTnode(t x,BSTnode *l=0,BSTnode *r=0)
	  {
        info=x;
		left=l;
		right=r;
		level=0;
	  }
};

template<class t>
class BSTree
{
   BSTnode<t> *root;
    int h;
   public:
	  
	   BSTree()
	   {
         root=0;
		 h=-1;
	   }
   
   void insertion(t x);
   void insertion1(t x);
   void count();
   int search(t x);
   void preorder();
   void preorder(BSTnode<t> *);
   void postorder();
   void postorder(BSTnode<t> *);
   void inorder();
   void inorder(BSTnode<t> *);
   void breadthfirst();
   void findanddeletebymerging(const t& x);
   void findanddeletebycopying(const t& x);
   void deletebymerging(BSTnode<t> *&);
   void deletebycopying(BSTnode<t> *&);
   void iterativepreorder();
   void iterativepostorder();
   void iterativeinorder();
   int isempty();
   void height();
   BSTree<t> mirrorimage();

};


template<class t>
void BSTree<t>::height()
{
  queue<BSTnode<t> *> q1;
   BSTnode<t> *p=root;
   BSTnode<t> *v;

   q1.enqueue(p);

   while(!q1.isempty())
   {
     v=q1.dequeue();
	 if(v->level>h)
		 h=v->level;

	 if(v->left!=0)
		 q1.enqueue(v->left);

	 if(v->right!=0)
		 q1.enqueue(v->right);

   }
	cout<<"Height of tree is "<<h;
}

template<class t>
int BSTree<t>::isempty()
{
  if(root==0)
	  return 1;
  else
	  return 0;
}

template<class t>
void BSTree<t>::count()
{
   queue<BSTnode<t> *> q1;
   BSTnode<t> *p=root;
   BSTnode<t> *v;
   int l=0,nl=0; 

   q1.enqueue(p);

   while(!q1.isempty())
   {
     v=q1.dequeue();
	 if(v->left==0 && v->right==0)
		 l++;
	 else if((v->left!=0 || v->right!=0) && v!=root)
		 nl++;


	 if(v->left!=0)
		 q1.enqueue(v->left);

	 if(v->right!=0)
		 q1.enqueue(v->right);

   }
   cout<<"No. of leaf nodes is "<<l;
   cout<<"No. of non-leaf nodes is "<<nl;
}


template<class t>
void BSTree<t>::insertion(t x)
{
  BSTnode<t> *temp=new BSTnode<t> (x);
  BSTnode<t> *p=root, *prev=0;

  while(p!=0)
  {
    prev=p;
    
	if(p->info>x)
		p=p->left;
	
	else
		p=p->right;
  }

  if(prev==0)
	  root=temp;

  else if(prev->info>x)
	  prev->left=temp;

  else
	  prev->right=temp;

  if(prev!=0)
    temp->level=prev->level+1;
}

template<class t>
void BSTree<t>::insertion1(t x)
{
  BSTnode<t> *temp=new BSTnode<t> (x);
  BSTnode<t> *p=root, *prev=0;

  while(p!=0)
  {
    prev=p;
    
	if(p->info<x)
		p=p->left;
	
	else
		p=p->right;
  }

  if(prev==0)
	  root=temp;

  else if(prev->info<x)
  
	  prev->left=temp;
	  

  else
	  prev->right=temp;

  if(prev!=0)
    temp->level=prev->level+1;
}

template<class t>
int BSTree<t>::search(t x)
{
   BSTnode<t> *p=root;

   while(p!=0)
   {
     if(p->info==x)
		 return 1;

	 else if(p->info>x)
		 p=p->left;

	 else
		 p=p->right;
   }
   return 0;

}

template<class t>
void BSTree<t>::breadthfirst()
{
   queue<BSTnode<t> *> q1;
   BSTnode<t> *p=root;
   BSTnode<t> *v;

   q1.enqueue(p);

   while(!q1.isempty())
   {
     v=q1.dequeue();
	 cout<<v->info<<" ";

	 if(v->left!=0)
		 q1.enqueue(v->left);

	 if(v->right!=0)
		 q1.enqueue(v->right);

   }
}

template<class t>
BSTree<t> BSTree<t>::mirrorimage()
{
	BSTree<t> l1;
   queue<BSTnode<t> *> q1;
   BSTnode<t> *p=root;
   BSTnode<t> *v;

   q1.enqueue(p);

   while(!q1.isempty())
   {
     v=q1.dequeue();
	 l1.insertion1(v->info);

	 if(v->left!=0)
		 q1.enqueue(v->left);

	 if(v->right!=0)
		 q1.enqueue(v->right);

   }
   return l1;
}

template<class t>
void BSTree<t>::preorder()
{
  preorder(root);
}


template<class t>
void BSTree<t>::preorder(BSTnode<t> *p)
{
  if(p!=0)
  {
    cout<<p->info<<" ";
	preorder(p->left);
	preorder(p->right);

  }
}


template<class t>
void BSTree<t>::postorder()
{
  postorder(root);
}


template<class t>
void BSTree<t>::postorder(BSTnode<t> *p)
{
  if(p!=0)
  {
    postorder(p->left);
	postorder(p->right);
	cout<<p->info<<" ";

  }
}

template<class t>
void BSTree<t>::inorder()
{
  inorder(root);
}


template<class t>
void BSTree<t>::inorder(BSTnode<t> *p)
{
  if(p!=0)
  {
    inorder(p->left);
	cout<<p->info<<" ";
	inorder(p->right);

  }
}



template<class t>
void BSTree<t>::iterativepreorder()
{
  stack<BSTnode<t> *> s1;
  BSTnode<t> *p=root;

  if(p!=0)
  {
    s1.push(p);

	while(!s1.isempty())
	{ 
       p=s1.pop();
	   cout<<p->info<<" ";

	   if(p->right!=0)
		   s1.push(p->right);

	   if(p->left!=0)
		   s1.push(p->left);
	}
  }
}


template<class t>
void BSTree<t>::iterativepostorder()
{
  stack<BSTnode<t> *> s1;
  BSTnode<t> *p=root, *q=root;

  while(p!=0)
  {
    for(;p->left!=0;p=p->left)
	{
      s1.push(p);
	}

	while(p!=0 && (p->right==0||p->right==q))
	{
      cout<<p->info;
	  q=p;
	  if(s1.isempty())
		  return;
	  p=s1.pop();

	}

	s1.push(p);
	p=p->right;
  }
}


template<class t>
void BSTree<t>::iterativeinorder()
{
  stack<BSTnode<t> *> s1;
  BSTnode<t> *p=root;
  
  while(p!=0)
  {
    while(p!=0)
	{
      if(p->right)
		  s1.push(p->right);

	  s1.push(p);
	  p=p->left;
	}

	p=s1.pop();
	while(!s1.isempty() && p->right==0)
	{
      cout<<p->info<<" ";
      p=s1.pop();
	}

	cout<<p->info<<" ";
    if(!s1.isempty())
		p=s1.pop();
	else
		p=0;
  }
}


template<class t>
void BSTree<t>::findanddeletebymerging(const t& x)
{
  BSTnode<t> *node1=root, *prev=0;

  while(node1!=0)
  {
    if(node1->info==x)
	 break;
	prev=node1;
	
	if(node1->info<x)
		node1=node1->right;

	else
		node1=node1->left;
  }

  if(node1!=0 && node1->info==x)
  {
     if(node1==root)
		 deletebymerging(root);
	 else if(prev->left==node1)
		 deletebymerging(prev->left);
	 else
		 deletebymerging(prev->right);
  }

  else if(root!=0)
	  cout<<"Element "<<x<<" is not in the tree....";
  else
	  cout<<"The tree is empty...";
}


template<class t>
void BSTree<t>::deletebymerging(BSTnode<t> *& node1)
{
  BSTnode<t> *temp=node1;
  if(node1!=0)
  {
  if(!node1->right)
	  node1=node1->left;

  else if(node1->left==0)
	  node1=node1->right;

  else
  {
    temp=node1->left;
	while(temp->right!=0)
	{
      temp=temp->right;
	}
	temp->right=node1->right;

	temp=node1;
	node1=node1->left;
  }
  delete temp;
  }
}

template<class t>
void BSTree<t>::findanddeletebycopying(const t& x)
{
  BSTnode<t> *node1=root, *prev=0;

  while(node1!=0)
  {
    if(node1->info==x)
	 break;
	prev=node1;
	
	if(node1->info<x)
		node1=node1->right;

	else
		node1=node1->left;
  }

  if(node1!=0 && node1->info==x)
  {
     if(node1==root)
		 deletebycopying(root);
	 else if(prev->left==node1)
		 deletebycopying(prev->left);
	 else
		 deletebycopying(prev->right);
  }

  else if(root!=0)
	  cout<<"Element "<<x<<" is not in the tree....";
  else
	  cout<<"The tree is empty...";
}


template<class t>
void BSTree<t>::deletebycopying(BSTnode<t> *& node1)
{
  BSTnode<t> *prev, *temp=node1;

  if(node1->right==0)
     node1=node1->left;

  else if(node1->left==0)
	  node1=node1->right;

  else
  {
    temp=node1->left;
	prev=node1;

	while(temp->right!=0)
	{
      prev=temp;
	  temp=temp->right;
	}

	node1->info=temp->info;
	
	if(prev==node1)
	   prev->left=temp->left;

	else
		prev->right=temp->left;

  }

  delete temp;
}



void main()
{
  BSTree<int> b1,b2;
   char c,ch1;
  int ch,x,z;

  do
  {
	  cout<<"MENU::\n1.Insertion\n2.Deletion By Copying\n3.Deletion By Merging\n4.Search a number in BST\n5.Preorder\n6.Iterative preorder\n";
	  cout<<"7.Postorder\n8.Iterative postorder\n9.Inorder\n10.Iterative inorder\n11.Breadth-first traversal\n12.calculate leaf and non-leaf nodes\n";
	  cout<<"13.Height of tree\n14.Mirror image of BST\n\nEnter your choice::";
	  cin>>ch;

	  switch(ch)
	  {
	     case 1:do
				{
                  cout<<"\nEnter a number to be inserted in BST::";
			      cin>>x;
                  b1.insertion(x);
				cout<<"Do you want to enter more elements(y/n)...";
				cin>>ch1;
				}
				while(ch1=='y');
                cout<<"Display BST::";
				b1.preorder();
				  
			 break;

         case 2:cout<<"Enter the element you want to be deleted::";
			    cin>>x;
				b1.findanddeletebycopying(x);
				cout<<"Display BST";
				b1.preorder();
				break;

  
         case 3:cout<<"Enter the element you want to be deleted::";
			    cin>>x;
				b1.findanddeletebymerging(x);
				cout<<"Display BST";
				b1.preorder();
				break;

		 case 4:cout<<"Enter a number you want to search in BST::";
			    cin>>x;
				if(!b1.isempty())
				{
                   z=b1.search(x);
				   if(z==1)
					   cout<<"Element found...";
				   else
					   cout<<"Element not found";
				}

				else
					cout<<"Search can't be completed. Tree is empty...";
				break;

         case 5:cout<<"Preorder Traversal::";
			    b1.preorder();
				break;
 
         
         case 6:cout<<"Preorder Traversal::";
			    b1.iterativepreorder();
				break;

       
         case 7:cout<<"Postorder Traversal::";
			    b1.postorder();
				break;


         case 8:cout<<"Postorder Traversal::";
			    b1.iterativepostorder();
				break;

				
         case 9:cout<<"Inorder Traversal::";
			    b1.inorder();
				break;

				 
         case 10:cout<<"Inorder Traversal::";
			    b1.iterativeinorder();
				break;

		 case 11:cout<<"Breadth-first traversal::";
			     b1.breadthfirst();
				 break;

         case 12:b1.count();
    		     break;

		 case 13:b1.height();
			     break;
  
		 case 14:b2=b1.mirrorimage();
			     b2.preorder();
				 break;
			     

	  }
	  cout<<"\nDo you want to continue(y/n).....";
	  cin>>c;
  }
  while(c=='y');
  
}