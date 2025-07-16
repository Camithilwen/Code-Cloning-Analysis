#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
const ll mod = 1000000007;
const int INF = 1001001001;



int main(){
    int n, m;
    cin >> n >> m;
    int arr[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    sort(whole(a));
    reverse(whole(a));
    vector<int> x(m);
    rep(i, m) x[i] = arr[a[i]-1];
    
    vector<P> dp(n+1, P(-INF, -1));
    dp[0] = P(0, -1);
    rep(i, n+1) {
        for (int j=0; j<x.size(); j++) {
            int e = x[j];
            if (i-e>=0 && dp[i-e].first>=0) {
                if (dp[i].first<dp[i-e].first+1) {
                    dp[i].first = dp[i-e].first + 1;
                    dp[i].second = a[j];
                }
            }
        }
    }
    int keta = dp[n].first;
    int index = n;
    map<int, int> mp;
    while (index) {
        mp[dp[index].second]++;
        index -= arr[dp[index].second-1];
    }
    string ans;
    for (auto m: mp) {
        rep(i, m.second) {
            ans += m.first+'0';
        }
    }
    reverse(whole(ans));
    
    
    
    
    cout << ans << endl;
    return 0;
}
