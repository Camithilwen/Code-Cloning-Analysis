#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M;
vector<int>G[1000];
int cnt[1000];
main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;u--,v--;
		G[u].push_back(v);
		cnt[v]++;
	}
	queue<int>P;
	for(int i=0;i<N;i++)
	{
		if(cnt[i]==0)P.push(i);
	}
	int sz=0;
	while(!P.empty())
	{
		sz++;
		int u=P.front();P.pop();
		for(int v:G[u])
		{
			if(--cnt[v]==0)P.push(v);
		}
	}
	cout<<-(sz==N)<<endl;
}