#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll mod = 1000000007;
const int MAX = 1000100;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 1;
    vector<ll> num(n);
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            ans *= 3 - num[0];
            num[0]++;
        }
        else{
            ans *= num[a[i] - 1] - num[a[i]];
            num[a[i]]++;
        }
        ans %= mod;
    }
    cout << ans << endl;
}