#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000;
const ll mod = 1000000007;
#define PI 3.1415926535
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> pair;
bool seen[100000];
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする
 
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

//dpTable
int dp[100050];

int main(){
    ll L,R;
    cin >> L >> R;
    if (L + 2019 <= R) cout << 0 << endl;
    else {
        ll ans = 2019;
        for (ll i = L; i < R; i++) {
            for (ll j = i + 1; j <= R; j++) {
                ll hoge = (i * j) % 2019;
                ans = min(ans,hoge);
            }
        }
        cout << ans << endl;
    }
    return 0;
}