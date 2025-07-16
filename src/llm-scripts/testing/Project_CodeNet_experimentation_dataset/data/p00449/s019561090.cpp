#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 200000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define EQ(a,b) (abs((a)-(b))<EPS)
int cost[101][101];
bool used[101];
int d[101];
int n,k;
void dijkstra(int s)
{
	fill(d,d+101,INF);
	fill(used,used+101,false);
	d[s]=0;
	for(;;)
	{
		int v=-1;
		for(int u=1;u<=n;u++)
		{
			if(!(used[u])&&(v==-1||d[u]<d[v]))
			{
				v=u;
			}
		}
		if(v==-1)break;
		used[v]=true;
		for(int u=1;u<=n;u++)
		{
			d[u]=min(d[u],d[v]+cost[v][u]);
		}
	}
	return ;
}
int main()
{
	while(1)
	{
		for(int i=0;i<101;i++)
		{
			for(int j=0;j<101;j++)
			{
				cost[i][j]=INF;
			}
		}
		cin >> n >> k;
		if(n==0&&k==0)break;
		for(int i=0;i<k;i++)
		{
			int type;
			cin >> type;
			if(type)
			{
				int a,b,co;
				cin >> a >> b >> co;
				cost[a][b]=min(cost[a][b],co);
				cost[b][a]=min(cost[b][a],co);
			}
			else
			{
				int a,b;
				cin >> a >> b;
				dijkstra(a);
				if(d[b]==INF)
				{
					cout << -1 << endl;
				}
				else
				{
					cout << d[b] << endl;
				}
			}
		}
	}
	return 0;
}