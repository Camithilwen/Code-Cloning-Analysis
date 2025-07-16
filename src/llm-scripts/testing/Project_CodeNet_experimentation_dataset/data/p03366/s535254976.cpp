#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
vector<int> v;
int main() {
	int n; ll s; cin >> n >> s;
	ll x[100000]; ll p[100000];
	rep(i, n) {
		cin >> x[i] >> p[i];
	}
	int j, k; j = 0; k = n - 1;
	while (j < k) {
		if (p[j] < p[k]) {
			p[k] += p[j];
			if (s > x[j]) {
				v.push_back(j);
			}
			j++;
		}
		else if (p[j] >= p[k]) {
			p[j] += p[k];
			if (s < x[k]) {
				v.push_back(k);
			}
			k--;
		}
	}
	v.push_back(j);
	int len = v.size();
	ll sum = 0; ll now = s;
	per(i, len) {
		sum += abs(x[v[i]] - now);
		now = x[v[i]];
	}
	cout << sum << endl;
	return 0;
}