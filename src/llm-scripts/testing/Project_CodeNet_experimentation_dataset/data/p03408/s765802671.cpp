#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
#define rep(i,n) for (ll i=0;i<n;i++)
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    set<string> uni;
    cin >> n;
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
        uni.insert(s[i]);
    } 
    cin >> m;
    vector<string> t(m);
    rep(i,m) {
        cin >> t[i];
        uni.insert(t[i]);
    }

    ll ans = 0;

    for(string ss:uni){
        ll tmp = 0;
        rep(i,n){
            if(s[i]==ss) tmp++;
        }
        rep(i,m){
            if(t[i]==ss) tmp--;
        }

        ans = max(ans,tmp);
    }

    cout << ans << endl;

    return 0;
}