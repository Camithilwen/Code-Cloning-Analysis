#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<cstdlib>
#include<typeinfo>
#include<sstream>
#include<list>
#include<set>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define fori(i,k,n) for(int i=k;i<(int)n;i++)
using namespace std;
int in()
{
	int x;cin>>x;
	return x;
}
int stringInt(string a)
{
	return atoi(a.c_str());
}
string intString(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}
vector<int> SieveOfEratosthenes(int x)
{
	vector<int> a;
	vector<int> b(x+1,0);
	for(int i=2;i<=x;i++)
	{
		if(b[i]==0)
		{
			a.push_back(i);
			for(int l=i;l<=x;l+=i)
			{
				b[l]=1;
			}
		}
	}
	return a;
}

int main ()
{
	int n,m;
	while(cin>>n>>m&&n&&m)
	{
		vector<long long > a,b;
		b.push_back(0);
		rep(i,n)
		{
			b.push_back(in());
		}
		rep(i,n+1)
		{
			rep(l,n+1)
			{
				a.push_back(b[i]+b[l]);
			}
		}
		long long ans = 0;
		sort(a.begin(),a.end());
		rep(i,a.size())
		{
			vector<long long>::iterator t=upper_bound(a.begin(),a.end(),m-a[i]);
			if(t==a.begin())continue;
			t--;
			ans=max(ans,*t+a[i]);
		}
		cout<<ans<<endl;


	}

}