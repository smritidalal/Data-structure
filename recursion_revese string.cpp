

#include<iostream>
#include<cstring>
using namespace std;
class reverse
{
public:
	void rev()
	{
		char ch;
		cin.get(ch);
		if(ch!='\n')
		{
			rev();
			cout<<ch;
		}
	}
};
void main()
{
	reverse o1;
	o1.rev();
}