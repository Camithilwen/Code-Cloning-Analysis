#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
#define INF 1000000000

int main(){
	int n,m,flg;
	ll a,b,c;
	while(cin >> n >> m && n && m){
		vector<P> node[101];
		for(int k=0;k<m;k++){
			cin >> flg;
			if(flg){
				cin >> a >> b >> c;
				P p; p.first=b; p.second=c;
				node[a].push_back(p);
				p.first = a;
				node[b].push_back(p);
			}
			else {
				bool f = true;
				cin >> a >> b;
				ll used[102];
				used[a] = 0;
				for(int j=1;j<=n;j++) used[j] = INF;
				priority_queue<P, vector<P>, greater<P> > que;
				que.push(P(0,a));
				while(!que.empty()){
					P p = que.top(); que.pop();
					ll cost = p.first;
					ll now = p.second;
					if(now == b) {
						cout << cost << endl;
						f = false;
						break;
					}
					int len = node[now].size();
					for(int i=0;i<len;i++){
						P p = node[now][i];
						ll next = p.first;
						ll nc = p.second;
						if(used[next]==INF || used[next] > cost+nc){
							used[next] = cost+nc;
							que.push(P(cost+nc,next));
						}
					}
				}
				if(f) cout << "-1" << endl;
			}
		}
	}
}