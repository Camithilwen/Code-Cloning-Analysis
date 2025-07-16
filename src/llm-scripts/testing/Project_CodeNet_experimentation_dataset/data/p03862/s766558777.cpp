#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1001001001;

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i] > x){
            ll tmp = a[i] - x;
            ans += tmp + a[i+1];
            a[i+1] = 0;
        }
        else{
            if(a[i+1] + a[i] <= x) continue;
            else{
                ll tmp = a[i+1] + a[i] - x;
                ans += tmp;
                a[i+1] -= tmp;
                if(i + 1 == n - 1 && a[i+1] > x) ans += a[i+1] - x;
            }
        }
    }
    cout << ans << endl;
}