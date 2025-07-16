#include<cstdio>
#include<queue>
#include<iostream>
#define ll long long
using namespace std;
ll res[4][2]={-1,0,0,1,0,-1,1,0};
char map1[60][60];
ll step[60][60];
ll n,m;
ll bfs()
{
	map1[0][0]='#';
	step[0][0]=0;
	queue<ll>qu;
	qu.push(0);
	qu.push(0);
	while(!qu.empty())
	{
		ll x=qu.front();qu.pop();
		ll y=qu.front();qu.pop();
		if(x==n-1&&m-1==y)return step[x][y];
		for(int i=0;i<4;++i)
		{
			ll dx=x+res[i][0];
			ll dy=y+res[i][1];
			if(dx>=0&&dx<n&&dy>=0&&dy<m&&map1[dx][dy]=='.')
			{
				map1[dx][dy]='#';
				step[dx][dy]=1+step[x][y];
				qu.push(dx);
				qu.push(dy);
			}
		}
	}
	return -1;
}
int main()
{
	while(cin>>n>>m)
	{
		for(ll i=0;i<n;++i)
		    cin>>map1[i];
		ll sum=0;
		for(ll i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			    if(map1[i][j]=='.')
			        sum++;
		}
		ll ss=bfs();
		if(ss==-1)puts("-1");
		else printf("%lld\n",sum-ss-1);
	}
	return 0;
}
