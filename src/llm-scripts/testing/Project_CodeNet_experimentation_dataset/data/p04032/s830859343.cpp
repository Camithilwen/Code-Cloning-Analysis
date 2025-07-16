#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int n = s.size();
    rep(i, n) {
        if (i==0) continue;
        if (s[i]==s[i-1]) {
            cout << i << " " << i+1 << endl;
            return 0;
        }
    }
    rep(i, n) {
        if (i<=1) continue;
        if (s[i]==s[i-2]) {
            cout << i-1 << " " << i+1 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;

    return 0;
}
