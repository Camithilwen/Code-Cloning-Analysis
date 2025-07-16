#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	string A;
	cin >> A;
	ll ans = A.size() * (A.size() - 1) / 2;
	char c = 'a';
	rep(i,26)
	{
		ll cnt = 0;
		rep(j,A.size())
		{
			if (A[j] == c) cnt++;
		}
		if (cnt != 0) ans -= cnt * (cnt - 1) / 2;
		c++;
	}
	ans++;
	cout << ans << endl;
	return 0;
}