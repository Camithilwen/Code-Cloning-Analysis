#define _USE_MATH_DEFINES
#define INF 100000000
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>

using namespace std;

typedef long long ll;
typedef pair <int,int> P;

static const double EPS = 1e-8;

int path[101][101];

int dijkstra(int s,int g,int n){
	int d[101];
	bool used[101];
	memset(d,0x3f,sizeof(d));
	memset(used,0,sizeof(used));
	d[s] = 0;
	
	while(1){
		int v=-1;
		for(int u=1;u<=n;u++){
			if(!used[u] && (v==-1 || d[u] < d[v])) v=u;
		}

		if(v==-1) break;

		used[v] = true;

		for(int u=1;u<=n;u++){
			d[u] = min(d[u],d[v] + path[v][u]);
		}
	}

	return d[g];
}

int main(){
	int n,k;

	while(~scanf("%d %d",&n,&k)){
		if(n==k && k==0) break;
		memset(path,0x3f,sizeof(path));
		for(int i=0;i<k;i++){
			int ch;
			scanf("%d",&ch);
			if(ch){
				int a,b,val;
				scanf("%d %d %d",&a,&b,&val);
				path[a][b] = path[b][a] = min(val,path[a][b]);
			}
			else{
				int a,b,res;
				scanf("%d %d",&a,&b);
				res = dijkstra(a,b,n);
				printf("%d\n",res > INF ? -1 : res);

			}
		}
	}
}