#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

string s;
ll c[26];

int main(){
    cin >> s;
    for(auto &e : s) c[e-'a']++;
    ll ans = s.size() * (s.size()-1) / 2;
    for(int i=0;i<26;i++){
        ans -= c[i] * (c[i]-1) / 2;
    }
    cout << ans+1 << endl;
    return 0;
}