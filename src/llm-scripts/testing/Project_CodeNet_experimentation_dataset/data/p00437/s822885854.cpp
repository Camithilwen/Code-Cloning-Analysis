#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> plli;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const ll mod = 1e9 + 7;
const ll INF = 1<<30;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    while (a != 0) {
        int n;
        cin >> n;
        int ans[a + b + c + 1];
        fill(ans, ans + a + b + c, 2);
        int ii[n] = {}; int jj[n] = {}; int kk[n] = {}; int rr[n] = {};
        rep(m, n) {
            int i, j, k, r;
            cin >> i >> j >> k >> r;
            ii[m] = i; jj[m] = j; kk[m] = k; rr[m] = r;
            if (r == 1) {
                ans[i] = 1;
                ans[j] = 1;
                ans[k] = 1;
            }
            else {
                if (ans[i] == 1 && ans[j] == 1) ans[k] = 0;
                else if (ans[i] == 1 && ans[k] == 1) ans[j] = 0;
                else if (ans[j] == 1 && ans[k] == 1) ans[i] = 0;

            }

        }
        rep(m, n) {
            int i = ii[m]; int j = jj[m]; int k = kk[m]; int r = rr[m];
            if (r == 1) {
                ans[i] = 1;
                ans[j] = 1;
                ans[k] = 1;
            }
            else {
                if (ans[i] == 1 && ans[j] == 1) ans[k] = 0;
                else if (ans[i] == 1 && ans[k] == 1) ans[j] = 0;
                else if (ans[j] == 1 && ans[k] == 1) ans[i] = 0;

            }

        }
        rep2(i, 1, a + b + c + 1) cout << ans[i] << endl;
        cin >> a >> b >> c;
    }
}