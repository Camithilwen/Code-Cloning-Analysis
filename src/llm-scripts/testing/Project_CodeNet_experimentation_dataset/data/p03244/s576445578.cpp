#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n;
    cin >> n;
    map<ll,ll> m, p;
    rep(i,n/2) {
        ll a, b;
        cin >> a >> b;
        m[a]++, p[b]++;
    }
    vector<P> even, odd; //回数 値
    for(auto x : m) even.push_back(make_pair(x.second, x.first));
    for(auto x : p) odd.push_back(make_pair(x.second, x.first));
    sort(all(even)); sort(all(odd));;
    reverse(all(even)); reverse(all(odd));
    ll A = 0, B = 0, ans;
    if(even[0].second==odd[0].second){
        ans = min(n-even[0].first-odd[1].first, n-even[1].first-odd[0].first);
    }
    else{
        A = even[0].first;
        B = odd[0].first;
        ans = n-A-B;
    }
    cout << ans << endl;
    return 0;
}