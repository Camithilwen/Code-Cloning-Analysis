#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 1;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
ll n, m, x = 0, y,z,w,h, sum= 0, ans = 0;
string s, t;
int main() {
	cin >> h >> w; vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) {
		rep(j, w) cin >> a[i][j];
	}vector<pair<int, int>> p,q;
	rep(i, h) {
		if (i % 2 == 0) {
			rep(j, w - 1) {
				if (a[i][j] % 2 == 1) {
					a[i][j + 1]++;
					sum++;
					p.push_back({ i,j });
					q.push_back({ i,j + 1 });
				}
			}
			if (a[i][w - 1] % 2 == 1 && i != h - 1) {
				a[i + 1][w - 1]++;
				sum++;
				p.push_back({ i,w - 1 });
				q.push_back({ i + 1,w - 1 });
			}
		}
		else {
			rrep(j, w) {
				if (a[i][j] % 2 == 1) {
					a[i][j - 1]++;
					sum++;
					p.push_back({ i,j });
					q.push_back({ i,j - 1 });
				}
			}
			if(a[i][0] % 2 == 1 && i != h - 1) {
				a[i + 1][0]++;
				sum++;
				p.push_back({ i,0 });
				q.push_back({ i + 1,0 });
			}
		}
	}
	cout << sum << endl;
	rep(i, p.size()) {
		cout << p[i].first + 1 << " " << p[i].second+ 1 << " " << q[i].first+1 << " ";
		cout << q[i].second + 1 << endl;
	}
}