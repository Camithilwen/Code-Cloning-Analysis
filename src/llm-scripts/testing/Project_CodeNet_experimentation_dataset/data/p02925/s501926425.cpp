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

vector<int> to[500000];
int tab[1005][1005];

int toID(int i, int j) {
    if (i>j) swap(i, j);
    return tab[i][j];
}

int dp[500000];
bool used[500000];
bool calculated[500000];

int dfs(int x) {
    if (used[x]) {
        if (!calculated[x]) return -1;
        return dp[x];
    }
    used[x] = true;
    int now = 1;
    for (int e: to[x]) {
        int res = dfs(e);
        if (res<0) return -1;
        now = max(res+1, now);
    }
    dp[x] = now;
    calculated[x] = true;
    return dp[x];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i, n) rep(j, n-1) {
        cin >> a[i][j];
        a[i][j]--;
    }
    int id = 0;
    rep(i, n) rep(j, n) {
        if (i<j) tab[i][j] = id++;
    }
    rep(i, n) {
        rep(j, n-1) {
            a[i][j] = toID(i, a[i][j]);
        }
        rep(j, n-2) {
            to[a[i][j]].push_back(a[i][j+1]);
        }
    }

    
    int ans = 0;
    rep(i, id) {
        int res = dfs(i);
        ans = max(ans, res);
        if (res==-1) {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    
    
    cout << ans << endl;
    return 0;
}
