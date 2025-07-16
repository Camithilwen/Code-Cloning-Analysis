#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 1e5 + 5;
const ll LINF = 1e18 + 5;
int n;
ll Xor, c[N];
ll a[63], b[63];
int tot;
void insert(ll x)
{
	for(int i=62;~i;i--)
	{
		if((x>>i)&1)
		{
			if(!a[i])
			{
				a[i] = x;
				break;
			}
			x ^= a[i];
		}
	}
}
ll Max(ll x)
{
	ll ans = x;
	for(int i=62;~i;i--)
		ans = max(ans,ans^a[i]);
	return ans;
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n;
 	for(int i=1; i<=n; i++)
 	{
 		cin >> c[i];
 		Xor ^= c[i];
 	}
 	for(int i=1; i<=n; i++)
 		insert((c[i]&(~Xor)));
 	ll A = Max(0);
 	ll B = Xor^A;
 	ll ans = A + B;
 	cout << ans;
	return 0;
}
