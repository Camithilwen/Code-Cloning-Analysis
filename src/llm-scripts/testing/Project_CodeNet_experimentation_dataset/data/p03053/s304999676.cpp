#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll h,w;
	cin >> h >> w;
	vector<string> s(h);
	for(auto &i:s)cin >> i;
	vector<vector<ll>> dis(h,vector<ll>(w,1e9));

	for(int i = 0;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		{
			if(s[i][j]=='#')dis[i][j]=0;
		}
	}

	for(int i = 0;i<h;i++)
	{
		for(int j = 1;j<w;j++)
		{
			dis[i][j] = min(dis[i][j],dis[i][j-1]+1);
		}
	}

	for(int i = 0;i<h;i++)
	{
		for(int j = w-2;j>=0;j--)
		{
			dis[i][j] = min(dis[i][j],dis[i][j+1]+1);
		}
	}
	for(int i = 1;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		{
			dis[i][j] = min(dis[i][j],dis[i-1][j]+1);
		}
	}

	for(int i = h-2;i>=0;i--)
	{
		for(int j = 0;j<w;j++)
		{
			dis[i][j] = min(dis[i][j],dis[i+1][j]+1);
		}
	}
	ll ans = 0;
	for(int i = 0;i<h;i++)for(int j = 0;j<w;j++)ans = max(ans,dis[i][j]);
	cout << ans << endl;

	
}
