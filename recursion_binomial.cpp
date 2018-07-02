#include<iostream>
using namespace std;
class binomial
{
public:
	long bin(int n,int k)
	{
		if(k==0||k==n)
			return 1;
		else 
			return bin(n-1,k-1)+bin(n-1,k);
	}
};
void main()
{
	binomial o1;
	int x,y,g;
	cout<<"enter first value\n";
	cin>>x;
	cout<<"enter second value\n";
	cin>>y;
	g=o1.bin(x,y);
	cout<<"binomial is\n";
	cout<<g;
}


