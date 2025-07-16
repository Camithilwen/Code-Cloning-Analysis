#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int H,W,K;

const int MOD = 1e9+7;

vector<int> change;
vector<vector<int>> next_w;

void rec(int w){
    if(w == W-1){
        vector<int> n(W,0);
        REP(i,W) n[i] = i;
        REP(i,W-1) if(change[i]==1) swap(n[i],n[i+1]);
        REP(i,W){
            next_w[n[i]][i]++;
        }
        return;
    }
    
    
    change[w] = 0;
    rec(w+1);

    change[w] = 1;
    if(w+2 < W) change[w+1]=0, rec(w+2);
    if(w+2 == W) rec(w+1); 
}

int main() {
    cin >> H >> W >> K;

    next_w.assign(W, vector<int>(W,0));
    change.assign(W-1,0);

    rec(0);

    vector<vector<ll>> ans(H+1, vector<ll>(W,0));
    ans[0][0] = 1;

    REP(i,H){
        REP(j,W){
            if(j-1>=0){
                ans[i+1][j-1] += ans[i][j] * next_w[j][j-1];
                ans[i+1][j-1] %= MOD;
            }
            ans[i+1][j] += ans[i][j] * next_w[j][j];
            ans[i+1][j] %= MOD;
            if(j+1<=W-1){
                ans[i+1][j+1] += ans[i][j] * next_w[j][j+1];
                ans[i+1][j+1] %= MOD;
            }
        }
    }

    cout << ans[H][K-1] << endl;

    return 0;
}