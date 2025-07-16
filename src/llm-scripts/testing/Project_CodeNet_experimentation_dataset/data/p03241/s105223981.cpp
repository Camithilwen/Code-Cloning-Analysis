#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

// O(\sqrt{n})
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i=1; i*i <= n; i++){
        if(n%i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

int main(void){
    ll n, m;
    cin >> n >> m;
    vector<ll> divs = divisor(m);
    sort(divs.begin(), divs.end());

    ll ans;
    for(ll i=0; i<divs.size(); i++){
        if(divs[i] * n <= m){
            ans = divs[i];
        }
    }
    cout << ans << endl;
    return 0;
}