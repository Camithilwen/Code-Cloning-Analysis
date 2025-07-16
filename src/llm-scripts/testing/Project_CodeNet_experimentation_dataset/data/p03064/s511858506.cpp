#include<algorithm>
#include<chrono>
#include<climits>
#include<numeric>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
 
struct Debug{
	int cnt = 0;
	bool on = false;
	char debug[10] = "debug";
	template<class T>
	Debug & operator<<(const T & v) {
		if(on && cnt++ == 0) cerr << "debug: ";
		if(on) cerr << v << ' ';
		return *this;
	}
	Debug & operator<<(ostream&(*pManip)(ostream&)) {
		if(on) cerr << (*pManip);
		cnt = 0;
		return *this;
	}
} debug;
#define rep(i, a, b) for(auto i = (a); i < (b); i++)
#define rrep(i, a, b) for(auto i = (a); i > (b); i--)
#define all(v) (v).begin(), (v).end()
#define print(v) {if(debug.on){for(auto x : v) debug << x; debug << endl;}}
#define printn(v, n) {if(debug.on){for(int _i = 0; _i < n; _i++) debug << *(v + _i); debug << endl;}}
 

typedef unsigned long long ull;
typedef long long ll;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

struct mint{
    long long x;
    long long mod = 998244353;
    
    mint(): x(0) {}
    mint(long long _x): x(_x) {}
    operator long long() { return x; }

    mint operator+(const mint & b) const { return (x + b.x) % mod; }
    mint operator-(const mint & b) const { return (x - b.x + mod) % mod; }
    mint operator*(const mint & b) const { return (x * b.x) % mod; }

    template<class T>
    mint operator^(T b) const {
        if(!b) return 1;
        mint tmp = (*this) ^ (b / 2);
        return b % 2 ? tmp * tmp * (*this) : tmp * tmp;
    }

    mint inv() const { 
    	static unordered_map<long long, long long> inv_dp;
        if(inv_dp.count(x))
            return inv_dp[x];
        else if(inv_dp.size() < 100000)
            return inv_dp[x] = (*this) ^ (mod - 2);
        else return (*this) ^ (mod - 2);
    }
    
    mint operator/(const mint & b) const { return (*this) * b.inv(); }
};
// unordered_map<long long, long long> mint::inv_dp;
 
const int MAXN = 300 + 20, MAXM = 90000 + 20;
int n;
int a[MAXN];
mint dp[MAXM];
mint dp2[MAXM];

int main(int argc, char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(argc > 1 && !strcmp(argv[1], debug.debug)) debug.on = true;

    cin >> n;
    int tot = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	tot += a[i];
    }
    dp[0] = mint(2) ^ n;
    dp2[0] = mint(1);
    for(int i = 1; i <= n; i++) {
    	for(int j = tot; j >= 0; j--) {
    		if(j - a[i] >= 0) {
    			dp[j] = dp[j] + dp[j - a[i]] / mint(2);
    			dp2[j] = dp2[j] + dp2[j - a[i]];
    		}
    	}
    	debug << i << endl;
    	for(int i = 0; i < 10; i++)
    		debug << dp[i].x;
    	debug << endl;
    }

    mint res = 0;
    for(int i = (tot + 1) / 2; i <= tot; i++) {
    	res = res + dp[i];
    	if(i * 2 == tot)
    		res = res - dp2[i];
    	debug << i << res.x << endl;
    }
    debug << (mint(3) ^ n).x << res.x << endl;
    res = (mint(3) ^ n) - res * mint(3);
    debug << res.x << (mint(3) ^ n).x << endl;

    cout << res.x << endl;


    return 0;
}




















