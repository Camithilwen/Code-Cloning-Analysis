#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<string> isu(N);

	ll L = 0;
	ll R = N;
	std::cout << L << std::endl;
	cin >> isu[L];
	if (isu[L] == "Vacant") return 0;

	while (abs(R-L) > -1)
	{
		ll mid = (R+L)/2;
		std::cout << mid << std::endl;
		cin >> isu[mid];
		if (isu[mid] == "Vacant") return 0;

		if ((mid - L) & 1)
		{
			if (isu[mid] == isu[L])
			{
				R = mid;
			}
			else
			{
				L = mid;
			}
		}
		else
		{
			if (isu[mid] == isu[L])
			{
				L = mid;
			}
			else
			{
				R = mid;
			}
		}
		
	}
	std::cout << L << std::endl;

	return 0;
}
