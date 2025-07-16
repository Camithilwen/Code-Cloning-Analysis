#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <iomanip>
#include <tuple>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;

void exec()
{
	int edge[100][100]={0};
	int n,k;
	cin >> n >> k;
	if(n==0&&k==0)exit(0);
	for(int i=0;i<k;i++){
		int a,b,c;
		cin >> a >> b >> c;
		b--;
		c--;
		if(a==0){
			priority_queue<P, vector<P>, greater<P> > q;
			q.push(P(0,b));
			int dist[100];
			fill(dist,dist+n,INT_MAX);
			dist[b]=0;
			while(q.size()){
				int f=q.top().second;
				int d=q.top().first;
				q.pop();
				if(f==c)break;
				if(dist[f]<d)continue;
				for(int j=0;j<n;j++){
					if(edge[f][j]&&d+edge[f][j]<dist[j]){
						dist[j]=d+edge[f][j];
						q.push(P(dist[j],j));
					}
				}
			}
			if(dist[c]!=INT_MAX){
				cout << dist[c] << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else
		{
			int d;
			cin >> d;
			if(edge[b][c]==0||d<edge[b][c]){
				edge[b][c]=d;
				edge[c][b]=d;
			}
		}
	}
}
int main() {
	while(1)exec();
}