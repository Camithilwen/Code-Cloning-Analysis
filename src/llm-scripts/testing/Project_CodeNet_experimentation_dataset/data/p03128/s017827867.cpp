#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


ll dp[10010]; // i本使って作れる最大桁数
int num[10] = {0,2,5,5,4,5,6,3,7,6};
int main(){
    int n, m;
    cin >> n >> m;
    rep(i, 10010) dp[i] = -INF;
    dp[0] = 0;
    int a[m];
    rep(i,m) cin >> a[i];
    sort(a,a+m);
    reverse(a,a+m);

    rep(i, n+1){
        rep(j, m){
            if (i >= num[a[j]]) dp[i] = max(dp[i], dp[i-num[a[j]]] + 1);
        }
    }

    vector<char> ans;

    // rep(i, m) cout << a[i] << " ";
    // cout << endl;
    
    int i = n;
    while(i > 0){
        bool flag = false;
        rep(j, m){
            if (i - num[a[j]] < 0) continue;
            if (dp[i - num[a[j]]] == dp[i]-1){
                ans.push_back(a[j] + '0');
                i -= num[a[j]];
                // cout << "j=" << j << endl;
                flag = true;
                break;
            }
        }
        if (!flag) break;
    }

    rep(i, ans.size()) cout << ans[i];
    cout << endl;


    return 0;
}
