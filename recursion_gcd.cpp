
#include<iostream>
using namespace std;
class GCD
{
public:
	int gcd(int x1,int x2)
	{
		if(x2==0)
			return x1;
		else if(x1==0)
			return 1;
		else
			return gcd(x2,x1%x2);
	}
		
};
void main()
{
    GCD o1;
	int d ,a,b;
	cout<<"enter dividend a\n";
	cin>>a;
	cout<<"enter divisor b\n";
	cin>>b;
	d=o1.gcd(a,b);
	cout<<"gcd is\n";
	cout<<d;
}