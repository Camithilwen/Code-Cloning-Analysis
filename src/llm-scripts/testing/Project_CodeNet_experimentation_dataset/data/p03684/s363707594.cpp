#include<bits/stdc++.h>
using namespace std;
const int MAX=100000+5;

int n;
pair<int,int> coord[MAX];
vector<int> par(MAX,0);
vector<pair<int,pair<int,int> > > edges;
int root(int x)
{
	while(par[x]!=x)
	{	
		par[x]=par[par[x]];
		x=par[x];
	}
	return x;
}

void union1(int x,int y)
{
	int u=root(x);
	int v=root(y);
	par[u]=v;
}
int main()
{
	cin>>n;
	vector<pair<int,int> > xc;
	vector<pair<int,int> > yc;

	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		coord[i]={x,y};
		xc.push_back({x,i});
		yc.push_back({y,i});
	}
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
	}
	sort(xc.begin(),xc.end());
	sort(yc.begin(),yc.end());
	for(int i=0;i<n-1;i++)
	{
		edges.push_back({abs(xc[i].first-xc[i+1].first),{xc[i].second,xc[i+1].second}});
	}
	for(int i=0;i<n-1;i++)
	{
		edges.push_back({abs(yc[i].first-yc[i+1].first),{yc[i].second,yc[i+1].second}});
	}
	long long int sum=0;
	//kruskal
	for(int i=1;i<=n;i++)
		par[i]=i;
	sort(edges.begin(),edges.end());
	for(int i=0;i<edges.size();i++)
	{
		int w=edges[i].first;
		int u=edges[i].second.first;
		int v=edges[i].second.second;
		if(root(u)!=root(v))
		{
			union1(u,v);
			sum+=w;
		}
	}
	cout<<sum<<endl;
}