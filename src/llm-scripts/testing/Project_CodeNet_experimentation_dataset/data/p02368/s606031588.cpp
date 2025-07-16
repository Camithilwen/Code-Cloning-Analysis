#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX=10000;

int V;
vector<int> G[MAX];
vector<int> rG[MAX];
vector<int> vs;
bool used[MAX];
int cmp[MAX];

void add_edge(int from,int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
	return;
}

void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
	return;
}

void rdfs(int v,int k)
{
	used[v]=true;
	cmp[v]=k;
	for(int i=0;i<rG[v].size();i++)
	{
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
	return;
}

int ssc()//Strongly Connected Component
{
	memset(used,0,sizeof(used));
	vs.clear();
	for(int v=0;v<V;v++)
	{
		if(!used[v])dfs(v);
	}
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--)
	{
		if(!used[vs[i]])rdfs(vs[i],k++);
	}
	return k;
}

int main()
{
	int E;
	cin>>V>>E;
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin>>u>>v;
		add_edge(u,v);
	}
	int k=ssc();
	int Q;cin>>Q;
	for(int i=0;i<Q;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<(cmp[u]==cmp[v])<<endl;
	}
	return 0;
}