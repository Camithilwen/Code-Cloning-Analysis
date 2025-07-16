#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			cin >> a[i][j];
		}
	}
	const long long minf = numeric_limits<long long>::min() / 8;
	const int mx = 1 << n;
	vector<long long> dp(mx, minf), sum(mx);
	dp[0] = 0;
	for(auto mask = 1; mask < mx; ++ mask){
		for(auto i = 0; i < n; ++ i){
			if(mask & 1 << i){
				for(auto j = i + 1; j < n; ++ j){
					if(mask & 1 << j){
						sum[mask] += a[i][j];
					}
				}
			}
		}
		for(auto submask = mask; submask; submask = (submask - 1) & mask){
			ctmax(dp[mask], dp[mask ^ submask] + sum[submask]);
		}
	}
	cout << dp.back();
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////