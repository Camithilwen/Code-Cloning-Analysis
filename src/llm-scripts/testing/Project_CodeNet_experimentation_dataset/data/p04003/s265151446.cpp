#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500010;
const int INF = 1000000010;

int n, m;
int cntNode;

int dist[MAXN];

vector<int> adj[MAXN];
vector<int> weight[MAXN];

deque<int> d;

map<int,int> indNode[MAXN];

void BFS01(int s)
{
	for(int i = 1 ; i <= cntNode ; i++)
		dist[i] = INF;

	dist[s] = 0;
	d.push_front( s );

	while( !d.empty() )
	{
		int cur = d.front();
		d.pop_front();

		for(int i = 0 ; i < (int)adj[cur].size() ; i++)
		{
			int viz = adj[cur][i];
			int w = weight[cur][i];

			if( dist[viz] <= dist[cur] + w ) continue;

			dist[viz] = dist[cur] + w;

			if( w == 0 ) d.push_front( viz );
			else d.push_back( viz );
		}
	}
}

int getExpandedNode(int node, int color)
{
	if( indNode[node][color] == 0 )
		indNode[node][color] = ++cntNode;

	return indNode[node][color];
}

void addEdge(int U, int V, int W)
{
	adj[U].push_back( V );
	weight[U].push_back( W );
}

int main()
{
	scanf("%d %d",&n,&m);

	cntNode = n;

	for(int i = 1 ; i <= m ; i++)
	{
		int U, V, C;
		scanf("%d %d %d",&U,&V,&C);

		int A = getExpandedNode( U , C );
		int B = getExpandedNode( V , C );

		addEdge( A , B , 0 );
		addEdge( B , A , 0 );
	}

	for(int i = 1 ; i <= n ; i++)
	{
		for(auto it = indNode[i].begin() ; it != indNode[i].end() ; it++)
		{
			addEdge( i , it->second , 0 );
			addEdge( it->second , i , 1 );
		}
	}

	BFS01( 1 );

	if( dist[n] == INF ) printf("-1\n");
	else printf("%d\n",dist[n]);
}