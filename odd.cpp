#include<iostream>
using namespace std;

class odd
{
public:
	void a(int i, int n)
	{
		if(i<=n)
			
		{
			if( (i%2)!=0)
				cout<<" "<<i;
			a(++i,n);
		}
	}
	void d(int i, int n)
	{
		if(n>=i)
		{ if((n%2)!=0)
            cout<<" "<<n;
	     d(i,--n);
		}
	}
};

void main()
{
	odd o1;
  int i1=1,n1;
  cout<<"\n Enter a number ";
  cin>>n1;

  cout<<"\n odd numbers between 1 and "<< n1<<" are ";
  o1.a(i1,n1);
  cout<<"\n";

  cout<<"\n Odd numbers between "<<n1 <<" and 1 are ";
  o1.d(i1,n1);
  cout<<"\n";
}