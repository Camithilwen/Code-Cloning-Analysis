#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a;
	ll b;
	ll c;
	cin>>a;
	cin>>b;
	cin>>c;
	if((a==b)&&(b==c))
	{
		cout<<"No"<<"\n";
	}
	else if((a!=b)&&(b!=c)&&(c!=a))
	{
		cout<<"No"<<"\n";
	}
	else
	{
		cout<<"Yes"<<"\n";
	}
	return 0;
}
