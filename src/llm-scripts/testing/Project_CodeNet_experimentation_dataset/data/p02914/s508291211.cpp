#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
ll p[64];
int st[64];
int tot = 0;
void ins(ll x) {
	for (int i = 0; i < tot; ++i) {
		if ((x >> st[i]) & 1) {
			if (p[i]) x ^= p[i];
			else {
				p[i] = x;
				break;
			}
		}
	}
}
int n;
ll a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i) cin >> a[i], sum ^= a[i];
	for (int i = 60; i >= 0; --i) if (!((sum >> i) & 1)) st[tot++] = i;
	for (int i = 0; i < n; ++i) ins(a[i]);
	ll res = 0;
	for (int i = 0; i < tot; ++i)
		if (!((res >> st[i]) & 1)) res ^= p[i];
	cout << res + (sum ^ res) << endl;
}
