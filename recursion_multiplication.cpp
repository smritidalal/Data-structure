	#include<iostream>
using namespace std;

class multiplication
{
public:
	int mult(int a, int b, int prod)
	{
		if(b>0)
		{
			prod=prod+a;
			return mult(a,--b,prod);
		}
		return prod;
	}
};

void main()
{
	int x,y,p=0,z;
	cout<<"\n Enter two numbers ";
	cin>>x>>y;
    multiplication m1;
	z=m1.mult(x,y,p);
	cout<<"\n"<<x<<"*"<<y<<"="<<z<<"\n";
}

