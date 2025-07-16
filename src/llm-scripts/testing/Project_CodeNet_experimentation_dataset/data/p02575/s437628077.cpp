#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int>
#define vvi vector<vector<int> >
#define vpi vector<pii>
#define F first
#define S second
#define pb push_back
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define MOD 1000000007
#define mod 998244353
#define lowbit(x) x&(-x)
#define HS 173LL
using namespace std;
int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int h,w;
map<int,int> mp;
multiset<int> st;
int main()
{
	h=read(),w=read();
	for(int i=1;i<=w;i++)
		mp[i]=0;
	for(int i=1;i<=w;i++)
		st.insert(0);
	for(int i=1;i<=h;i++)
	{
		int l=read(),r=read();
		if(r!=w)
		{
			auto it=mp.upper_bound(r+1);
			if(it!=mp.begin())
			{
				--it;
				if(it->first!=r+1)
				{
					int v=it->second+r+1-it->first;
					mp[r+1]=v;
					st.insert(v);
				}
			}
		}
		auto it=mp.lower_bound(l);
		while(it!=mp.end()&&it->first<=r)
		{
			st.erase(st.find(it->second));
			it=mp.erase(it);
		}
		if(!st.empty())
			cout<<*st.begin()+i<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}