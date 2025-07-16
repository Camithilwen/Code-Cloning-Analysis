#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int a[500005];
ll dp1[2100000];
ll dp2[2100000];
ll s[500005];
ll last[2100000];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll x = 0;
    for(int i = 0; i < 2100000; i++) dp2[i] = 1;
    for(int i = 0; i < n; i++){
        x ^= a[i];
        s[i + 1] = s[i];
        if(x){
            dp2[x] = (dp2[x] + dp1[x] * (s[i + 1] - s[last[x]]) % MOD) % MOD;
            dp1[x] = (dp1[x] + dp2[x]) % MOD;
            last[x] = i + 1;
        }
        else{
            s[i + 1]++;
        }
    }
    ll ans = 0;
    if(x == 0){
        for(int i = 0; i < 2100000; i++) ans = (ans + dp1[i]) % MOD;
        ll c = 0;
        for(int i = 0; i < n; i++){
            x ^= a[i];
            if(x == 0) c++;
        }
        ll k = 1;
        for(int i = 0; i < c - 1; i++) k = k * 2 % MOD;
        ans = (ans + k) % MOD;
    }
    else{
        ans = dp2[x];
    }
    cout << ans << endl;
}
