#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
ll MOD = 1e9+7;
main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> X(N),Y(M),accumX(N+1),accumY(M+1);
    rep(i,0,N){
        cin >> X[i];
        X[i] += 1e9;
        accumX[i+1] = (accumX[i] + X[i]) % MOD;
    }
    rep(i,0,M){
        cin >> Y[i];
        Y[i] += 1e9;
        accumY[i+1] = (accumY[i] + Y[i]) % MOD;
    }
    ll sumx = 0,sumy = 0;
    rep(i,0,N-1){
        sumx += (accumX[N] - accumX[i+1] - X[i] * (N-i-1) + MOD * MOD) % MOD;
        sumx %= MOD;
    }
    rep(i,0,M-1){
        sumy += (accumY[M] - accumY[i+1] - Y[i] * (M-i-1) + MOD * MOD) % MOD;
        sumy %= MOD;
    }
    cout << (sumx * sumy) % MOD << endl;
}