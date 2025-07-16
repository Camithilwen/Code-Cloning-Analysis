#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
const int inf = 1e9;

int n, k;
vector<P> vec[101];
int d[101];

void dijkstra(int s){
		pq<P, vector<P>, greater<P> > q;
		q.push(mk(0, s));
		d[s] = 0;
		while(!q.empty()){
				P p = q.top(); q.pop();
				int at = p.second;
				int dis = p.first;
				if(d[at] < dis)continue;
				for(auto itr = vec[at].begin(); itr != vec[at].end(); ++itr){
						int to = (*itr).second;
						int cost = (*itr).first;
						if(d[to] > dis + cost){
								d[to] = dis + cost;
								q.push(mk(d[to], to));
						}
				}
		}
}

int main(int argc, char const* argv[])
{
	do{
			cin >> n >> k;
			for(int i = 0; i < n; i++){
					vec[i].erase(vec[i].begin(), vec[i].end());
			}
			for(int i = 0; i < k; i++){
					int a;
					cin >> a;
					if(a == 0){
							int b, c;
							cin >> b >> c;
							b--; c--;
							fill(d, d+n, inf);
							dijkstra(b);
							if(d[c] == inf)cout << -1 << endl;
							else cout << d[c] << endl;
					}else{
							int b, c, dd;
							cin >> b >> c >> dd;
							b--; c--;
							vec[b].pb(mk(dd, c));
							vec[c].pb(mk(dd, b));
					}
			}
	}while(n != 0);
	return 0;
}

