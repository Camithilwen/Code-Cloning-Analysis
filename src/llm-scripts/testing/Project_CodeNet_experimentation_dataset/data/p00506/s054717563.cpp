#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(a);i>(b);--i)
#define eper(i,a,b) for(int i=(a);i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF 100100100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
#define vii vector<int>
#define vll vector<long long>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}

int n;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
    cin >> n;
    vll a(n);
    rep(i, 0, n) cin >> a[i];
    int k = a[0];
    rep(i, 1, n) k = gcd(k, a[i]);
    vii ans;
    erep(x, 1, k) {
        bool flag = true;
        rep(i, 0, n) {
            if (a[i] % x != 0) flag = false;
        }
        if (flag) {
            ans.pb(x);
        }
    }
    rep(i, 0, ans.size()) cout << ans[i] << endl;
    return 0;
}
