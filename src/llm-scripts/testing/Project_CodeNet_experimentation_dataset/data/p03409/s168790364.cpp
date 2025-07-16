#include<bits/stdc++.h>
using namespace std;

bool bfs(int s,int t,vector<vector<pair<int,int>>> graph,vector<int> &prev)
{
	int v,w;
	vector<bool> visit(201,false);
	queue<int> que;
	que.push(s);
	visit[s]=true;
	for (int i=0;i<prev.size();i++) prev[i]=0;
	while(!que.empty())
	{
		v=que.front();
		que.pop();
		for (int i=0;i<graph[v].size();i++)
		{

			if (graph[v][i].first!=0)
			{
				w=i;
				if (!visit[w])
				{
					visit[w]=true;
					prev[w]=v;
					que.push(w);
				}
			}
		}
	}
	return visit[t];
}

int main()
{
	int N;cin>>N;
	vector<pair<int,int>> red(N),blue(N);
	vector<vector<int>> capacity(2*N+2,vector<int> (2*N+2));
	vector<vector<int>> flow(2*N+2,vector<int> (2*N+2));
	vector<vector<pair<int,int>>> network(2*N+2,vector<pair<int,int>> (2*N+2));
	int x,y;
	for (int i=0;i<N;i++)
	{
		cin >> x >> y;
		red[i].first=x;
		red[i].second=y;
		capacity[0][i+1]=1;
	}
	for (int i=0;i<N;i++)
	{
		cin >> x >> y;
		blue[i].first=x;
		blue[i].second=y;
		capacity[N+i+1][2*N+1]=1;
	}
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			if ((red[i].first<blue[j].first) && (red[i].second < blue[j].second)) 
			{
				capacity[i+1][N+j+1]=1; 
			}
		}
	for (int i=0;i<2*N+2;i++)
		for (int j=0;j<2*N+2;j++)
		{
			if (capacity[i][j]>flow[i][j])
			{
				network[i][j].first=1;
				network[i][j].second=1;
			}
			if (flow[i][j]>0)
			{
				network[j][i].first=1;
				network[j][i].second=0;
			}
		}

	
	int to,from=-1;
	vector<int> prev(2*N+2);
	
	while (bfs(0,2*N+1,network,prev))
	{
		from =-1;
		to=2*N+1;
		while(from!=0)
		{
			from=prev[to];
			if (network[from][to].second==1)
			{
				flow[from][to]=1;
				network[from][to].first=0;
				network[to][from].first=1;
				network[from][to].second=1;
				network[to][from].second=0;
			}
			else
			{
				flow[from][to]=0;
				network[from][to].first=0;
				network[to][from].first=1;
				network[from][to].second=0;
				network[to][from].second=1;
			}
			to=from;	
		}
	}

	int ans=0;
	for (int i=1;i<2*N+1;i++) ans+=flow[i][2*N+1];
	cout << ans << endl;

return 0;
}