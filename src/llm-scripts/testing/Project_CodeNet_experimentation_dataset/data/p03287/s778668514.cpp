#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

const int sz = 1e5+5;
int n, m, a[sz];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> a[i];


    ll ans = 0;
    map<int, int> cnt;
    cnt[0] = 1;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum = (sum + a[i]) % m;
        ans += cnt[sum];
        cnt[sum]++;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}