#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll H, W; cin >> H >> W;
    vector<string> S(H); for(int i = 0; i < H; i++) cin >> S[i];
    ll bs = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) if(S[i][j] == '#') bs++;
    }

    vector<vector<ll>> V(H, vector<ll>(W, INF));
    queue<ll> qh, qw;
    qh.push(0); qw.push(0);
    V[0][0] = 0;
    int dh[] = {0, 1, 0, -1};
    int dw[] = {1, 0, -1, 0};
    
    while(!qh.empty()){
        ll h = qh.front(), w = qw.front();
        qh.pop(), qw.pop();
        for(int i = 0; i < 4; i++){
            ll nh = h+dh[i], nw = w+dw[i];
            if(0<=nh && nh < H && 0<=nw && nw<W && S[nh][nw] == '.' && V[h][w]+1<V[nh][nw]){
                qh.push(nh);
                qw.push(nw);
                V[nh][nw] = V[h][w]+1;
            }
        }
    }
    if(V[H-1][W-1] == INF) cout << -1 << endl;
    else cout << H*W-bs-V[H-1][W-1]-1 << endl;






}
