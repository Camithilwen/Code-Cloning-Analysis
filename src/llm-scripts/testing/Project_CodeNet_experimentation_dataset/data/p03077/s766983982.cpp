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
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 1000000000000000;
    rep(i,5){
        ll m;
        cin >> m;
        ans = min(ans,m);
    }
    cout << (n+ans-1)/ans + 4 << endl;

    return 0;
}