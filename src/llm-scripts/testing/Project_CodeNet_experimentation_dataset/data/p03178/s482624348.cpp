#include <bits/stdc++.h>
#define FAST_INPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


const int mod = 1e9+7;

void add_self(int& a, int b) {
	a+=b;
	if (a>mod) {
		a-=mod;
	}
}

void solve() {
	string K;
	cin >> K;
	int D;
	cin >> D;

	// 544 -> 499
	vector<vector<int>> dp(D, vector<int>(2));
	dp[0][false] = 1;
	for (int idx=0; idx<(int) K.size(); idx++) {
		vector<vector<int>> new_dp(D, vector<int>(2));
		for (int sum=0; sum<D; sum++) {
			for (bool smaller_already: {false, true}) {
				for(int digit=0; digit<10; digit++) {
					if (digit>K[idx]-'0' && !smaller_already) {
						break;
					}
					add_self(new_dp[(sum+digit)%D][smaller_already||(digit<K[idx]-'0')], dp[sum][smaller_already]);
				}
			}
		}
		dp = new_dp;
	}

	int res=(dp[0][true]+dp[0][false])%mod;
	res--;
	if (res==-1){
		res=mod-1;
	}

	cout << res << endl;
}

int main() {
    FAST_INPUT;

    solve();

    return 0;
}
