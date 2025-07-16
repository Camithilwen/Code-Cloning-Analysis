#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n,m;
	while(cin>>n>>m,n)
	{
		vector<int> G[500];
		int u,v;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			u--;v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int> F;
		for(int i=0;i<G[0].size();i++)
		{
			F.push_back(G[0][i]);
			for(int j=0;j<G[G[0][i]].size();j++)
			{
				F.push_back(G[G[0][i]][j]);
			}
		}
		sort(F.begin(),F.end());
		F.erase(unique(F.begin(),F.end()),F.end());
		if(F.size())cout<<F.size()-1<<endl;
		else cout<<F.size()<<endl;
	}
	return 0;
}