#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    pair<ll, ll> p[n];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        ans += 0 - p[i].second;
    }

    ll q[n];
    for(int i = 0; i < n; i++){
        q[i] = p[i].first + p[i].second;
    }

    sort(q, q + n, greater<ll>());

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            ans += q[i];
        }
    }

    cout << ans << endl;
}