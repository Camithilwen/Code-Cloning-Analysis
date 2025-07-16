//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
	ll N;
	cin >> N;
	string s;
	cin >> s;
	ll ans = 0;
	rep(bits,0,1<<N) {
		string zeros;
		string ones;
		rrep(i,N,0) {
			if (bits & (1 << i)) {
				ones.push_back(s[i]);
			} else {
				zeros.push_back(s[i]);
			}
		}
		/*
		if (bits == 1) {
			cout << "zeros:" << zeros << endl;
			cout << "ones:" << ones << endl;
		}
		*/
		auto dp = make_vec_nd(0, 1+zeros.size(), 1+ones.size());
		dp[0][0] = 1; 
		rep(n,1,N+1) {
			rep(z,0,min((ll)zeros.size(),n)+1) {
				ll o = n - z;
				if (o > ones.size()) {
					continue;
				}
				if (z >= 1 && s[2*N-n] == zeros[zeros.size()-z]) {
					dp[z][o] += dp[z-1][o];
				}
				if (o >= 1 && s[2*N-n] == ones[ones.size()-o]) {
					dp[z][o] += dp[z][o-1];
				}
				// cout << z << "," << o << ":" << dp[z][o] << endl;
			}
		}
		ans += dp[zeros.size()][ones.size()];
	}
	cout << ans << endl;
}
