#include "bits/stdc++.h"
using namespace std;
#define int long long
#define double long double
#define low lower_bound
#define upp upper_bound
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define Rep(i,n) for (int i = (int)(n); i >= 0; i--)
#define all(vec) vec.begin(), vec.end()
#define rever(vec) reverse(all(vec));
#define cend printf("\n");
#define prique(T) priority_queue<T, vector<T>, greater<T>>
#define prique2(T) priority_queue<T>
struct edge { int to, cost; };
using P = pair<int, int>;
using PP = pair<P, int>;
using D = pair<double, double>;
const int mod2 = 998244353;
const int mod = (int)1e9 + 7, inf = (int)1e16;
const string sp = " ";
 
int modpow(int x, int n) {
	int ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans *= x;
			if (mod <= ans) ans %= mod;
		}
		x *= x;
		if (mod <= x) x %= mod;
		n >>= 1;
	}
	return ans;
}
 
int fact[1000000];
void f_init(int n) {
	if (1000000 <= n) return;
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= n; ++i) {
		fact[i] *= fact[i - 1];
		if (mod <= fact[i]) fact[i] %= mod;
	}
	return;
}
 
int comb(int n, int r) {
	if (n < r) return 0;
	int ans = fact[n] * modpow(fact[n - r], mod - 2) % mod * modpow(fact[r], mod - 2);
	if (ans < 0) return ans + mod;
	return ans;
}
 
int perm(int n, int r) {
	if (n < r) return 0;
	if (n - r < r) r = n - r;
	int ans= fact[n] * modpow(fact[n - r], mod - 2) % mod;
	if (ans < 0) return ans + mod;
	return ans;
}
 
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
 
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
 
bool pri(int p) {
	for (int i = 2; i * i <= p; ++i) if (p % i == 0) return false;
	return p > 1;
}
 
map<int, int>factring(int n) {
	map<int, int>ans;
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			n /= i;
			++ans[i];
		}
	}
	if (n != 1) ++ans[n];
	return ans;
}
 
P operator+(const P& a, const P& b) {
	return P(a.first + b.first, a.second + b.second);
}
P operator-(const P& a, const P& b) {
	return P(a.first - b.first, a.second - b.second);
}
 
class unionfind {
private:
	int par[200010], rankth[200010], sizeth[200020];
public:
	void init(int n) {
		rep(i, n) {
			par[i] = i;
			rankth[i] = 0;
			sizeth[i] = 1;
		}
	}
	int root(int x) {
		while (par[x] != x) {
			x = par[x] = par[par[x]];
		}
		return x;
	}
 
	bool same(int x, int y) {
		return root(x) == root(y);
	}
 
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return;
		if (rankth[x] < rankth[y]) {
			par[x] = y;
			sizeth[y] += sizeth[x];
		}
		else {
			par[y] = x;
			if (rankth[x] == rankth[y]) rankth[x]++;
			sizeth[x] += sizeth[y];
		}
	}
};

int n;
P x[100000],y[100000];
prique(PP) que;
int ans;

signed main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i].first>>y[i].first;
		x[i].second=i;
		y[i].second=i;
	}
	sort(x,x+n);
	sort(y,y+n);
	for(int i=1;i<n;i++){
		que.push({{x[i].first-x[i-1].first,x[i-1].second},x[i].second});
		que.push({{y[i].first-y[i-1].first,y[i-1].second},y[i].second});
	}
	unionfind UF;
	UF.init(n);
	while((int)que.size()){
		PP p=que.top();que.pop();
		if(!UF.same(p.first.second,p.second)){
			ans+=p.first.first;
			UF.unite(p.first.second,p.second);
		}
	}
	cout<<ans<<endl;
}
