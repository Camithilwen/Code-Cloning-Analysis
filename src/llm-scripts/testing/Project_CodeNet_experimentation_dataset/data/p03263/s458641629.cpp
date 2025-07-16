#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    vector<P> now, next;
    rep(i,h)rep(j,w) {
        if (a[i][j]%2 == 0) continue;
        if (i == h-1 && j == w-1) continue;
        if (i == h-1) {
            now.emplace_back(i+1,j+1);
            next.emplace_back(i+1,j+2);
            a[i][j]--;
            a[i][j+1]++;
            continue;
        }
        if (j == w-1) {
            now.emplace_back(i+1,j+1);
            next.emplace_back(i+2,j+1);
            a[i][j]--;
            a[i+1][j]++;
            continue;
        }
        now.emplace_back(i+1,j+1);
        next.emplace_back(i+2,j+1);
        a[i][j]--;
        a[i+1][j]++;
    }
    int n = now.size();
    cout << n << endl;
    rep(i,n) {
        cout << now[i].first << " " << now[i].second << " " << next[i].first << " " << next[i].second << endl;
    }
    return 0;
}