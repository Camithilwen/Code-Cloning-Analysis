#include <bits/stdc++.h>

using namespace std;

#define int long long
int pref[250005], suff[250005], ans, prefix[250005], h , w, a, b;

const int mod = 1e9 + 7;

int BinPow(int x,int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    else{
        int sum = BinPow(x, n / 2) % mod;
        sum*=sum; sum%=mod;
        if(n % 2 != 0)
            sum *= x, sum%=mod;
        return sum;
    }
}

int C(int x,int n){
    if(x < 0 || x > n || n < 0) return 0;
    int sum = pref[n] * suff[x]; sum %= mod;
    sum*=suff[n - x]; sum %= mod;
    return sum;
}

signed main(){
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> h >> w >> a >> b;
    pref[0] = 1;
    for(int i = 1; i <= 250000; i++){
        pref[i] = pref[i - 1]*i;
        pref[i] %= mod;
    }
    suff[0] = 1;
    for(int i = 1; i <= 250000; i++)
        suff[i] = BinPow(pref[i], mod - 2);
    for(int i = 1; i <= 100000; i++){
        if(i >= h - a + 1){
            prefix[i] += C(b - 1, i + b - 2);
            pref[i] %= mod;
            prefix[i] += prefix[i - 1];
        }
    }
    ans = C(h - 1,h + w - 2);
    for(int i = 1; i <= h; i++){
        if(i >= h - a + 1){
            int dist = w - b;
            int dist1 = h - i + 1;
            ans -= C(b - 1, i + b - 2)*C(dist1 - 1,dist + dist1 -2 );
            ans %= mod;
            if(ans < 0) ans += mod;
        }
    }
    cout << ans;
}