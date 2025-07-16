//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
//i->jへ行くコストがcの時、集合adj[i]にはpair(i->jのコスト、j)が含まれる
vector<vector<pair<LL,LL>>> adj;
LL Q,K;
LL x[100000],y[100000];

LL ans[100000];

void solve(){
	priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> pq;
	pq.push(pair<LL,LL>(0,K));
	vector<LL> dist(N+1,INF);
	dist[K] = 0;
	while(!pq.empty()){
		LL now = pq.top().second;
		LL cost = pq.top().first;
		pq.pop();
		if(dist[now]<cost) continue;
		for(pair<LL,LL> next_info:adj[now]){
			LL diff_cost = next_info.first;
			LL next = next_info.second;
			if(dist[next]>=dist[now]+diff_cost){
				dist[next] = dist[now]+diff_cost;
				pq.push(pair<LL,LL>(dist[next],next));
			}
		}
	}

	for(int i=0;i<Q;i++){
		ans[i] = dist[x[i]] + dist[y[i]];
	}
}

int main(){
    cin >> N;
    adj = vector<vector<pair<LL,LL>>>(N+1);
    for(int i=0;i<N-1;i++){
    	LL a,b,c;cin >> a >> b >> c;
    	adj[a].push_back(pair<LL,LL>(c,b));
    	adj[b].push_back(pair<LL,LL>(c,a));
    }
    cin >> Q >> K;
	for(int i=0;i<Q;i++) cin >> x[i] >> y[i];

    solve();

    for(int i=0;i<Q;i++)cout << ans[i] << endl;
    return 0;
}