#include<iostream>
using namespace std;
template<class t>
class diagonal//diagonal
{
	t *a;
	int n;
	public:
		diagonal(int k)
		{
			a=new t[k];
			n=k;
		}
	void store(int i,int j,int x);
	t retr(int i,int j);
};

template<class t>
void diagonal<t>::store(int i,int j,int x)
{

	if(i<1||j<1||i>n||j>n)
	{
		cout<<"invalid index";
		exit(1);
	}
	if(i==j)
		a[i-1]=x;
	else if(x!=0)
		cout<<"it must be zero";
}

template<class t>
t diagonal<t>::retr(int i,int j)
{
	if(i<1||j<1||i>n||j>n)
	{
		cout<<"invalid index";
		exit(1);
	}
	if(i==j)
		return a[i-1];
	else
		return 0;
}
//diagonal

//tridiagonal

template<class t>
class tridia
{
	t *a;
	int n;
	public:
		tridia(int k)
		{
			n=k;
			a=new t[3*n-2];
		}
	void store(int i,int j,int x);
	t retr(int i,int j);
};

template<class t>
void tridia<t>::store(int i,int j,int x)
{

	if(i<1||j<1||i>n||j>n)
	{
		cout<<"invalid index";
		exit(1);
	}
	switch(i-j)
	{
		case 1:a[i-2]=x;
			break;
		case 0:a[n+i-2]=x;
			break;
		case -1:a[2*n+i-2]=x;
			break;
	}
}


template<class t>
t tridia<t>::retr(int i,int j)
{
	if(i<1||j<1||i>n||j>n)
	{
		cout<<"invalid index";
		exit(1);
	}
	switch(i-j)
	{
		case 1:return a[i-2];
			break;
		case 0:return a[n+i-2];
			break;
		case -1:return a[2*n+i-2];
			break;
		default:return 0;
	}

}
//tridiagonal
	
//lower triangle

template<class t>
class lowertri
{
	t *a;
	int n;
	public:
		lowertri(int k)
		{
			n=k;
			a=new t[n*(n+1)/2];
		}
	void store(int i,int j,t x);
	t retr(int i,int j);
};
template<class t>
void lowertri<t>::store(int i,int j,t x)
{
	if(i<1||j<1||i>n||j>n)
	{
		cout<<"invalid index";
		exit(1);
	}
	if(i>=j)
		a[i*(i-1)/2+j-1]=x;
	else if(x!=0)
		cout<<"it must be zero";
}
template<class t>
t lowertri<t>::retr(int i,int j)
{
	if(i<1||j<1||i>n||j>n)
	{
		cout<<"invalid index";
		exit(1);
	}
	if(i>=j)
		return a[i*(i-1)/2+j-1];
	else
		return 0;
}

//upper triangle
template<class t>
class updiagonal
{
	t *a;
	int n;
	public: updiagonal(int k)
			{
				a=new t[(k*(k+1))/2];
				n=k;
			}

			void store(int i,int j,t x);
			t retr(int i,int j);

};

template<class t>
void updiagonal<t>::store(int i,int j,t x)
{
	if(i<1 || i>n|| j<1 || j>n)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}
	if(i<=j)
		a[j*(j-1)/2+(i-1)]=x;
	else if(x!=0)
		cout<<"\n It must be zero";
}

template<class t>
t updiagonal<t>::retr(int i, int j)
{	
	if(i<1 || i>n || j<1 || j>n)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}
	if(i<=j)
		return 	a[j*(j-1)/2+(i-1)];
	else
		return 0;
}


//symmetric
template<class t>
class sym
{
	t *a;
	int n;
	public:
		sym(int k)
		{
			n=k;
			a=new t[n*(n+1)/2];
		}
	void store(int i,int j,t x);
	t retr(int i,int j);
};
template<class t>
void sym<t>::store(int i,int j,t x)
{
	if(i<1||j<1||i>n||j>n)
	{
		cout<<"invalid index";
		exit(1);
	}
	if(i>=j)
		a[i*(i-1)/2+j-1]=x;
	
}
template<class t>
t sym<t>::retr(int i,int j)
{
	if(i<1||j<1||i>n||j>n)
	{
		cout<<"invalid index";
		exit(1);
	}
	if(i>=j)
		return a[i*(i-1)/2+j-1];
	else
		return a[j*(j-1)/2+i-1];
}


void main()
{    
	diagonal<int> o(3);
	 tridia<int>o1(3);
	lowertri<int> o2(3);
	updiagonal<int> o4(3);
	sym<int> o3(3);

		
	int a,i,j,x;
	cout<<"1.diagonal";
	cout<<endl<<"2.tri diagonal";
	cout<<endl<<"3.lower triangle";
	cout<<endl<<"4.symmetric";
	cout<<endl<<"5.upper triangle";
	cout<<"enter your choice";
	cin>>a;
	switch(a)
	{
	case 1:
		cout<<"enter elements";
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++)
			{
				cin>>x;
				o.store(i,j,x);
			}

		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
		
			{
				cout<<o.retr(i,j)<<" ";
		
			}
				cout<<endl;
		}
		break;
	case 2:
	
		cout<<"enter elements";
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++)
			{
				cin>>x;
				o1.store(i,j,x);
			}

		for(i=1;i<=3;i++)
		{	
			for(j=1;j<=3;j++)
		
			{
				cout<<o1.retr(i,j)<<" ";
	
			}
				cout<<endl;
		}
		break;
	case 3:
		cout<<"enter elements";
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++)
			{
				cin>>x;
				o2.store(i,j,x);
			}

		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
		
			{
				cout<<o2.retr(i,j)<<" ";
		
			}
				cout<<endl;
		}
		break;
	case 4:	cout<<"enter elements";
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++)
			{
				cin>>x;
				o3.store(i,j,x);
			}

		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
		
			{
				cout<<o3.retr(i,j)<<" ";
		
			}
				cout<<endl;
		}
		break;
	case 5:cout<<"enter elements";
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++)
			{
				cin>>x;
				o4.store(i,j,x);
			}

		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
		
			{
				cout<<o4.retr(i,j)<<" ";
		
			}
				cout<<endl;
		}
		break;

}
}


