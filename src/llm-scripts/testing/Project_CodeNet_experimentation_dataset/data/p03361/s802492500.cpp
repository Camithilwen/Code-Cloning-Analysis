#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
#define con(x,y)	((x)*(m)+(y))
using namespace std;

int dsu[MAX];
int sz[MAX];

int search(int a)	{
	if(dsu[a]==a)	return a;
	return dsu[a]=search(dsu[a]);
}

void join(int a, int b)	{
	a = search(a);
	b = search(b);
	if(sz[a]<sz[b])	{
		dsu[b]=a;
		sz[a]+=sz[b];
	}
	else {
		dsu[a]=b;
		sz[b]+=sz[a];
	}
}

void solve()	{
	int n,m;
	cin >> n >> m;
	string s[n];
	for(int i=0; i<m*n; i++)	{
		sz[i]=1;
		dsu[i]=i;
	}
	for(int i=0; i<n; i++)	cin >> s[i];
	for(int i=0; i<n; i++)	{
		for(int j=0; j<m; j++)	{
			//cout << con(i,j) << endl;
			if(j+1<m && s[i][j]=='#' && s[i][j+1]=='#')	{
				if(search(con(i,j))!=search(con(i,j+1)))	
					join(con(i,j),con(i,j+1));
			}
			if(i+1<n && s[i][j]=='#' && s[i+1][j]=='#')	{
				if(search(con(i,j))!=search(con(i+1,j)))
					join(con(i,j),con(i+1,j));
			}
		}
	}
	bool f=0;
	for(int i=0; i<n; i++)	{
		for(int j=0; j<m; j++)	{
			if(s[i][j]=='#')	{
				if(sz[search(con(i,j))]==1)	{
					f=1; break;
				}
			}
		}
	}
	if(f)	cout << "No\n";
	else cout << "Yes\n";
}

int main()	
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}