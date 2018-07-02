#include<iostream>
#include<cmath>
using namespace std;
class power
{

public:
		long pow (int x,int n)
		{
			if(n==0)
				return 1;
			else 
				return x*pow(x,n-1);
		}
};
void main()
{
	power o1;
	int a,b;
	cout<<"enter the num a\n";
	cin>>a;
	cout<<"enter the power b\n";
	cin>>b;
	int y=o1.pow(a,b);
	cout<<y;
}