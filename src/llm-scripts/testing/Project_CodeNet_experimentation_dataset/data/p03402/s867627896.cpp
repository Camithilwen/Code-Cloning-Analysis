#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int h = 100;
    int w = 100;
    vector<string> c(h, string(w, '.'));
    rep(i, h) rep(j, w) {
        if (i<h/2) c[i][j] = '.';
        else c[i][j] = '#';
    }
    a--; b--;
    cout << h << " " << w << endl;

    while (b) {
        int x = b*3;
        int i = x/h+1;
        int j = x%h;
        c[i][j] = '#';
        b--;
    }
    while (a) {
        int x = a*3;
        int i = x/h + h/2+1;
        int j = x%h;
        c[i][j] = '.';
        a--;
    }
    
    rep(i, h) cout << c[i] << endl;
    return 0;
}
