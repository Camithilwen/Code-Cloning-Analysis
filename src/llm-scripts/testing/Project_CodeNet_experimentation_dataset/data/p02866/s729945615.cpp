#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll MOD = 998244353;

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n & 1)ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    VEC(int, a, n);

    bool ok = true;
    if(a[0] != 0)ok = false;
    map<int, int> mp;

    rep(i, n){
        mp[a[i]]++;
    }

    int now = 0;
    for(auto m : mp){
        if(now != m.first)ok = false;
        now++;
    }

    ll res = 1;
    ll p;
    if(mp[0] != 1)ok = false;

    if(ok){
        for(auto m : mp){
            if(m.first > 0)res = res * mpow(p, m.second) % MOD;
            p = m.second;
        }
    }
    else res = 0;
    cout << res;
}