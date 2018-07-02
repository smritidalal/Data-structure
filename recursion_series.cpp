#include<iostream>
#include<cmath>
using namespace std;
class series 
{
public:
	float f1(int n)
	{
		if(n==1)
			return 1;
		else 
			return pow(-1,n)*1/n+f1(--n);
	}
};
void main()
{
	series o1;
	float d;
	int a;
	cout<<"enter the value of a\n";
	cin>>a;
	d=o1.f1(a);
	cout<<d;
}