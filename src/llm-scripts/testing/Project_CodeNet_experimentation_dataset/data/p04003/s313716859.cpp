#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n,m;
map<int,vector<pair<int,int> > >G[1<<17];
map<int,int>d[1<<17];
main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;cin>>a>>b>>c;
		G[a][c].push_back(make_pair(b,c));
		G[b][c].push_back(make_pair(a,c));
		G[a][c].push_back(make_pair(a,0));
		G[b][c].push_back(make_pair(b,0));
		G[a][0].push_back(make_pair(b,c));
		G[b][0].push_back(make_pair(a,c));
	}
	priority_queue<pair<int,pair<int,int> > >P;
	d[1][0]=0;
	P.push(make_pair(0,make_pair(1,0)));
	while(!P.empty())
	{
		int dis=-P.top().first;
		int u=P.top().second.first;
		int c=P.top().second.second;
		P.pop();
		if(u==n&&c==0)
		{
			cout<<dis<<endl;
			return 0;
		}
		if(d[u][c]<dis)continue;
		for(pair<int,int>&p:G[u][c])
		{
			int v=p.first;
			int cost=dis+!c;
			int col=p.second;
			if(d[v].find(col)==d[v].end()||d[v][col]>cost)
			{
				d[v][col]=cost;
				P.push(make_pair(-cost,make_pair(v,col)));
			}
		}
	}
	cout<<-1<<endl;
}