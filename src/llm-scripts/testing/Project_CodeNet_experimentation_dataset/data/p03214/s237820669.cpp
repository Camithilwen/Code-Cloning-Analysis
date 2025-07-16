#include<bits/stdc++.h>
using namespace std;
namespace FAST_IO
{
	template<typename T> void read(T &a)
	{
		a=0;
		int f=1;
		char c=getchar();
		while(!isdigit(c))
		{
			if(c=='-')
			{
				f=-1;
			}
			c=getchar();
		}
		while(isdigit(c))
		{
			a=a*10+c-'0';
			c=getchar();
		}
		a=a*f;
	}
	template <typename T> void write(T a)
	{
		if(a<0)
		{
			a=-a;
			putchar('-');
		}
		if(a>9)
		{
			write(a/10);
		}
		putchar(a%10+'0');
	}
	template <typename T> void writeln(T a)
	{
		write(a);
		puts("");
	}
}
int n,q[101],tot,tt=1;
double mins=190000;
double avg;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
		tot+=q[i];
	}
	avg=tot*1.0/n;
	for(int i=1;i<=n;i++)
	{
		if(abs(q[i]-avg)<mins)
		{
			mins=abs(q[i]-avg);
			tt=i;
		}
	}
	cout<<tt-1;
}