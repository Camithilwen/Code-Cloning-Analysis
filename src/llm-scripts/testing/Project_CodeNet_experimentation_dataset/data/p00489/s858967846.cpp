#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned __int128 HASH;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll,int> plli;
typedef pair<double, int> pdbi;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vector<int>> mat;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const ll INF = 1<<30;
const ll mod = 1000000000 + 7;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

//#define int long long
#define addm(X, Y) (X) = ((X) + ((Y) % mod) + mod) % mod



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int cnt[n] = {};
    rep(i, n * (n - 1) / 2) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        if (c > d) cnt[a] += 3;
        else if (c == d) {
            cnt[a]++;
            cnt[b]++;
        }
        else cnt[b] += 3;
    }
    int score[305] = {};
    rep(i, n) score[cnt[i]]++;
    int total[305] = {};
    rrep2(i, 303, 0) {
        total[i] = total[i + 1] + score[i];
    }   
    rep(i, n) {
        cout << total[cnt[i]] - score[cnt[i]] + 1 << endl;
    }
}