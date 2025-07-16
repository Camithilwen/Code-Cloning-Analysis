#include<bits/stdc++.h>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<long long> vl;
typedef std::vector<std::vector<long long>> vvl;
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll gcd(ll n, ll m) {
    ll tmp;
    while (m!=0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}
 
ll lcm(ll n, ll m) {
    return abs(n) / gcd(n, m)*abs(m);//gl=xy
}

using namespace std;

ll dp[200005][3];
void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	rep(i,200005){
		rep(j,3)dp[i][j] = -INF;
	}
	rep(i,3)dp[0][i] = 0;
	if(n%2==1){
		rep(i, n/2)
		{
			int id = 2 * i;
			rep(j,3)
			{
				if(j==0){
					chmax(dp[i + 1][0], dp[i][0] + a[id]);
					chmax(dp[i + 1][1], dp[i][0] + a[id+1]);
					chmax(dp[i + 1][2], dp[i][0] + a[id + 2]);
				}
				else if(j==1){
					chmax(dp[i + 1][1], dp[i][1] + a[id+1]);
					chmax(dp[i + 1][2], dp[i][1] + a[id + 2]);
				}
				else{
					chmax(dp[i + 1][2], dp[i][2] + a[id + 2]);
				}
			}
		}
		ll ans = -INF;
		rep(i,3){
			chmax(ans, dp[n / 2][i]);
		}
		cout << ans;
	}
	else{
		rep(i,n/2){
			int id = i * 2;
			rep(j,2){
				if(j==0){
					chmax(dp[i + 1][0], dp[i][0] + a[id]);
					chmax(dp[i + 1][1], dp[i][0] + a[id + 1]);
				}
				else{
					chmax(dp[i + 1][1], dp[i][1] + a[id + 1]);
				}
			}
		}
		ll ans = -INF;
		rep(i,2){
			chmax(ans, dp[n / 2][i]);
		}
		cout << ans;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}

