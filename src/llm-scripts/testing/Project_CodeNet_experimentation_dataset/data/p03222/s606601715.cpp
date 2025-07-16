// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

ll memo[15];

const ll MOD = 1e9+7;

ll fib(ll n){
    if(n <= 0) return 1LL;
    
    if(memo[n] > 0) return memo[n];
    else return memo[n] = (fib(n-1) + fib(n-2))%MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h,w,k; cin >> h >> w >> k;
    if(w == 1){
        cout << 1 << endl;
        return 0;
    }
    --k;
    vector<ll> bef(w+1, 0LL), now(w+1, 0LL);

    // fib前計算
    fib(w);

    bef[0] = 1LL;
    rep(i,h){
        rep(j, w){
            if(j == 0){
                now[0] = bef[1]*fib(w-3)%MOD + bef[0]*fib(w-2)%MOD;
                now[0] %= MOD;
                continue;
            }
            if(j == w-1){
                now[w-1] = bef[w-2]*fib(w-3)%MOD + bef[w-1]*fib(w-2)%MOD;
                now[w-1] %= MOD;
                continue;
            }
            // 1
            now[j] = (( (fib(w-j-2)*fib(j-2))%MOD )*bef[j-1]) % MOD;
            now[j] %= MOD;
            // 2
            now[j] += (( (fib(w-j-3)*fib(j-1))%MOD )*bef[j+1]) % MOD;
            now[j] %= MOD;
            // 3
            now[j] += (( (fib(w-j-2)*fib(j-1))%MOD )*bef[j]) % MOD;
            now[j] %= MOD;
        }

        rep(j,w){
            bef[j] = now[j];
            now[j] = 0LL;
        }
    }
    
    cout << bef[k] << endl;
}