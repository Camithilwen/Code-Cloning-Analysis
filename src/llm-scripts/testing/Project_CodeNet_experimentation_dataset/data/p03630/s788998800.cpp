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
#include<bitset>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
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
struct rect { ll hei; int pos; };
ll getmaxrect(int size, ll buffer[]) {
	stack<rect> s;
	ll res = 0;
	buffer[size] = 0;
	for (int i = 0; i <= size; i++) {
		rect rec;
		rec.hei = buffer[i];
		rec.pos = i;
		if (s.empty()) {
			s.push(rec);
		}
		else {
			if (s.top().hei < rec.hei) {
				s.push(rec);
			}
			else if (s.top().hei > rec.hei) {
				int tag = i;
				while (!s.empty() && s.top().hei >= rec.hei) {
					rect pre = s.top(); s.pop();
					ll area = (pre.hei+1)*(i - pre.pos+1);
					res = max(res, area);
					tag = pre.pos;
				}
				rec.pos = tag;
				s.push(rec);
			}
		}
	}
	return res;
}
int p[2000][2000];
char t[2000][2000];
ll hi[2000][2000];
int main() {
	ll buffer[2001];
	int h, w; cin >> h >> w;
	rep(i, h) {
		string s; cin >> s;
		rep(j, w) {
			t[i][j] = s[j];
		}
	}
	rep(i, h - 1) {
		rep(j, w - 1) {
			int cnt = 0;
			rep(k, 2) {
				rep(l, 2) {
					if (t[i + k][j + l] == '#')cnt++;
				}
			}
			if (cnt % 2)p[i][j] = 1;
		}
	}
	rep(j, w - 1) {
		hi[0][j] = 1;
		if (p[0][j])hi[0][j] = 0;
		rep1(i, h - 2) {
			if (p[i][j])hi[i][j] = 0;
			else hi[i][j] = hi[i - 1][j] + 1;
		}
	}
	ll out = max(h,w);
	rep(i, h - 1) {
		rep(j, w - 1) {
			buffer[j] = hi[i][j];
		}
		out = max(out, getmaxrect(w - 1, buffer));
	}
	cout << out << endl;
	return 0;
}