
#include<iostream>
using namespace std;
class fibonaci
{
public:
	int fibo(int n)
	{
		if(n==1)
			return 0;
		else if(n==2)
			return 1;
		else
			return fibo(n-1)+fibo(n-2);
	}
};
void main()
{
	fibonaci o1;
	int a,y;
	cout<<"enter the range a\n";
	cin>>a;
	y=o1.fibo(a);
	cout<<y;
}