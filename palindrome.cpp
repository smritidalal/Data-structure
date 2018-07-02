#include<iostream>
#include<cstring>
using namespace std;

class palindrome
{
public:

	int palin(int i, int j,char a[10])
	{
		if(i==j)
		 return 0;

		else if(a[i]!=a[j])
			return 1;

		else return palin(++i,--j,a);
	}
};

void main()
{
	palindrome p;
	
	char b[10];
   int m,n,z;
   cout<<"\n Enter a string ";
   cin>>b;

   m=0;
   n=strlen(b);

   z=p.palin(m,n-1,b);

 if(z==0)
 cout<<"\n String is a palindrome\n";
 
 else cout<<"\n String is not a palindrome\n";
}


