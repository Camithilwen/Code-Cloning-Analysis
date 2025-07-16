#include <bits/stdc++.h> 
using namespace std;  
#define ll   long long int
#define INF 1000000007

int main()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	ll a = 0,b = 0,c = 0;
	string ch = "a";
	while(1)
	{
		if(ch == "a")
		{
			if(s1.size()>a)
			{
				ch = s1[a];
				a++;
			}
			else
			{
				cout<<"A"<<endl;
				return 0;
			}
		}
				if(ch == "b")
		{
			if(s2.size()>b)
			{
				ch = s2[b];
				b++;
			}
			else
			{
				cout<<"B"<<endl;
				return 0;
			}
		}
				if(ch == "c")
		{
			if(s3.size()>c)
			{
				ch = s3[c];
				c++;
			}
			else
			{
				cout<<"C"<<endl;
				return 0;
			}
		}
	}
}
