#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> A(N), B(N);
	REP(i, N)
		cin >> A[i] >> B[i];
	vector<ll> index(N);
	iota(ALL(index), 0ll);

	sort(ALL(index), [&](auto &a, auto &b)
					 {
						 return (A[a] + B[a] > A[b] + B[b]);
					 });

	ll res{0};
	bool ist{true};
	REP(i, N)
	{
		if (ist)
			res += A[index[i]];
		else
			res -= B[index[i]];
		ist ^= true;
	}

	std::cout << res << std::endl;
}
