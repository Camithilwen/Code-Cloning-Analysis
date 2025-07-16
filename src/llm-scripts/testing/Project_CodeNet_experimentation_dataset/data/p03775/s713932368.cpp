#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}//vector<ll>で受け取ること！

int main() {
    ll n;cin >> n;
    vector<ll> a=enum_divisors(n);
    ll x=a[a.size()/2];
    ll y=n/x;
    ll p=1,q=1;
    while(x>=10){
        x /= 10;
        p++;
    }
    while(y>=10){
        y /= 10;
        q++;
    }

    cout << max(p,q) << endl;

    return 0;
}