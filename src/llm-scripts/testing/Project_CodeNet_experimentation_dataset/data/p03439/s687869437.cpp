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

	ll MAX = 1;
	ll WOM = 2;

	vector<string> isu(N);

	string S;
	ll l = 0;
	ll r = N-1;

	std::cout << l << std::endl;
	cin >> S;
	if (S == "Vacant") return 0;
	isu[l] = S;
	
	while (true)
	{
		if (r - l <= 1)
		{
			std::cout << r << std::endl;
			cin >> S;
			if (S == "Vacant") return 0;
		}

		ll mid = (l + r) / 2;

		std::cout << mid << std::endl;
		cin >> S;
		if (S == "Vacant") return 0;
		isu[mid] = S;

		ll diff = mid - l - 1;;

		if (diff % 2 == 0)
		{
			if (isu[l] == isu[mid])
			{
				r = mid - 1;
			}
			else
			{
				l = mid;
			}
		}
		else
		{
			if (isu[l] == isu[mid])
			{
				l = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
	}
}
 
