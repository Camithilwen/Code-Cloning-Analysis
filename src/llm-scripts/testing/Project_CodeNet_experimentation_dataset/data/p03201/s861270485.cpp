#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int N; cin>>N;
	vector<int> A(N);
	map<int,int> cnt;
	rep(i,N){
		cin>>A[i];
		cnt[A[i]]++;
	}
	sort(all(A));
	int ans = 0;
	for(int i = N-1; i>= 0; --i){
		if(cnt[A[i]] < 1)continue;
		--cnt[A[i]];
		int need = pow(2LL, (int)log2(A[i])+1) - A[i];
		// printf("%d,%d\n", A[i], need);
		if(cnt[need] > 0){
			++ans;
			--cnt[need];
		}
	}
	cout<<ans<<endl;
}

// int main(){
// 	int N; cin>>N;
// 	vector<ll> A(N);
// 	map<ll,ll> hash;
// 	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
// 	rep(i,N){cin>>A[i]; hash[A[i]]++;}
// 	rep(i,N){
// 		ll cand = 0;
// 		ll t = 2;
// 		while(t < 1000000100){
// 			if(hash.count(t - A[i]) == 1){
// 				if(A[i] == t-A[i]){
// 					if(hash[A[i]] >= 2){++cand;}
// 				}else{
// 					++cand;
// 				}
// 			}
// 			t *= 2;
// 		}
// 		if(cand != 0){
// 			Q.push(make_pair(cand, i));
// 		}
// 	}
// 	// while(!Q.empty()){
// 	// 	cout<<Q.top().second<<" has "<<Q.top().first<<endl;
// 	// 	Q.pop();
// 	// }
// 	// return 0;
// 	ll ans = 0;
// 	while(!Q.empty()){
// 		ll e = A[Q.top().second];
// 		Q.pop();
// 		if(hash[e] <= 0)continue;
// 		ll t = 2;
// 		while(t < 1000000100){
// 			if(hash[t-e] > 0){
// 				++ans;
// 				--hash[t-e];
// 				--hash[e];
// 				break;
// 			}
// 			t *= 2;
// 		}
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }