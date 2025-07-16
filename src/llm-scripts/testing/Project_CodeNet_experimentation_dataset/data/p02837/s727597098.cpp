#ifdef __GNUC__
#pragma GCC target("avx2")
#pragma GCC optimize ("O20")
#pragma GCC optimize ("tree-vectorize")
#pragma GCC optimize("unroll-loops")
#define iss std::cin
#endif
#include "bits/stdc++.h"
#define rep(i, times) for(ll i = 0; i < (times); ++i)
#define p(x) (cout << x << "\n")
using ll = long long; using ld = long double; using namespace std;

#ifndef __GNUC__
string text =
R"X(
2
1
2 0
1
1 0
)X";
stringstream iss{text};
#endif

class HonestOrUnkind2
{
	ll N{0};
	vector<bool> h;//正直かどうかの仮定
	vector<vector<ll>> s;//証言
	void inp( ) {
		iss >> N;
		h.resize(N);
		s.resize(N, vector<ll>(N, 3));//3:言及せず 0:不親切呼ばわり 1:正直者認定
		rep(n, N) {
			ll K; iss >> K;//証言個数
			rep(k, K) {
				ll p, hn; iss >> p >> hn;//p番目の人は(n番が言うには)正直か
				s[n][--p] = hn;
			}
		}
	}
	inline bool consistentQ( ) {//仮定と矛盾しないかだけ調べる
		for (ll n = 0; n < N; ++n) {
			if (!h[n]) continue; //不親切なら無視
			for (ll p = 0; p < N; ++p) {//n番目の人がp番目の人に対して証言		
				if (s[n][p] == 3) continue;
				if ((s[n][p] == 1) && !h[p]) return false;
				if ((s[n][p] == 0) && h[p]) return false;
			}
		}
		return true;
	}
	void changeSeikaku( ) {
		size_t NH{0}; // 正直者の最大人数
		const ll maxB{(1 << N)};
		for (ll b = 0; b < maxB; ++b) {//全員の状態を変える
			rep(n, N) { h[n] = (b >> n) & 1; }//n番の人が正直と仮定したか
			if (consistentQ( )) NH = max(NH, bitset<32>(b).count( ));
		}
		p(NH);
	}
public:
	void procedures( ) {
		inp( );
		changeSeikaku( );
	}
};

int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	class HonestOrUnkind2 a; a.procedures( );
}