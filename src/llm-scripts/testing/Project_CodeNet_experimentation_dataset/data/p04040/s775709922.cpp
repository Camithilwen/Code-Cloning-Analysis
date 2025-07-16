#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
vector<long long>fact(200550);
long long bigmod(long long a, long long p){
    if(p == 0){
        return 1;
    }
    long long ans = bigmod(a, p/2);
    ans = (ans * ans) % mod;
    if(p % 2 == 1){
        ans = (ans * a) % mod;
    }
    return ans;
}
long long per(long long a, long long b){
    long long cur = (fact[b] * fact[a]) % mod;
    cur = bigmod(cur, mod - 2);
    cur = (cur * fact[a + b]) % mod;
    return cur;
}
int main(){
    long long h, w, a, b;
    cin >> h >> w >> a >> b;
    long long ans = 0;
    fact[0] = 1;
    for(long long i = 1; i <= 200010; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    long long p = h - a, q = b + 1;
    while(p >= 1 && q <= w){
        ans = (ans + (per(p - 1, q - 1) * per(h - p, w - q)) % mod) % mod;
        p--;
        q++;
    }
    cout << ans;
    return 0;
}