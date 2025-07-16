#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> cnt(n+1, vector<int>(n+1, 0));
    rep(i, m){
        int l, r;
        cin >> l >> r;
        cnt[l][r]++;
    }
    rep(i, n)rep(j, n){
        cnt[i+1][j+1] += cnt[i][j+1] + cnt[i+1][j] - cnt[i][j];
    }
    rep(i, q){
        int p, q;
        cin >> p >> q;
        int ans = cnt[q][q] - cnt[q][p-1] - cnt[p-1][q] + cnt[p-1][p-1];
        cout << ans << endl;
    }
    
}