#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<29)
#define MAX_V 100010

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii>   vii;
typedef vector<int>   vi;
const int DFS_WHITE = -1; // unvisited
const int DFS_BLACK =  1; // visited

int V,E;
int dfsNumberCounter,rootChildren,dfsRoot;
vi dfs_num,dfs_low,dfs_parent,articulation_vertex;
vii AdjList[MAX_V];// ii(neighbor,weight)


void articulationPointAndBridge(int u)
{
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for(int j=0;j<(int)AdjList[u].size();j++)
    {
      ii v = AdjList[u][j];
      if(dfs_num[v.first] == DFS_WHITE)
	{
	  dfs_parent[v.first] = u;
	  if(u == dfsRoot)rootChildren++;

	  articulationPointAndBridge(v.first);

	  if(dfs_low[v.first] >= dfs_num[u])
	    articulation_vertex[u] = true;
	  //if(dfs_low[v.first] >  dfs_num[u])
	    //printf("Edge (%d,%d) is a bridge\n",u,v.first);
	  dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);

	}
      else if(v.first != dfs_parent[u])
	dfs_low[u] = min(dfs_low[u],dfs_num[v.first]);
    }
}

void compute()
{
  dfsNumberCounter = 0; dfs_num.assign(V,DFS_WHITE); dfs_low.assign(V,0);
  dfs_parent.assign(V,0); articulation_vertex.assign(V,0);
  //puts("Bridges:");
  for(int i = 0; i < V; i++)
    if(dfs_num[i] == DFS_WHITE)
      {
	dfsRoot = i; rootChildren = 0;
	articulationPointAndBridge(i);
	articulation_vertex[dfsRoot] = (rootChildren > 1);// special case
      }
  //puts("Articulation Points");
  for(int i = 0; i < V; i++)
    if(articulation_vertex[i])
      printf("%d\n",i);
      //printf("Vertex %d\n",i);
}

int main()
{
  scanf("%d%d",&V,&E);
  rep(i,V)AdjList[i].clear();
  rep(i,E)
    {
      int s,t;
      scanf("%d%d",&s,&t);
      AdjList[s].push_back(ii(t,1));
      AdjList[t].push_back(ii(s,1));
    }

  compute();

  return 0;
}