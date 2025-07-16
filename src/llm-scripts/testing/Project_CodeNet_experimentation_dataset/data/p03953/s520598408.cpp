#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define cerr if(false) cerr
#define show(...) cerr << #__VA_ARGS__ << " = ",debug(__VA_ARGS__);
using namespace std;
using ll = long long;
using pii = pair<int,int>;
template<typename T, typename S>
ostream &operator<<(ostream &os,pair<T,S>a){
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os, vector<T> v){
    for(auto x:v)os << x << ' ';
    return os;
}
void debug(){cerr << '\n';}
template<typename H, typename... T>
void debug(H a, T... b){
    cerr << a;
    if(sizeof...(b))cerr << ", ";
    debug(b...);
}
vector<int> inv(const vector<int> &perm){
    vector<int> res(perm.size());
    rep(i,perm.size()){
        res[perm[i]] = i;
    }
    return res;
}
vector<int> product(const vector<int> &a, const vector<int> &b){
    vector<int> res(a.size());
    rep(i,a.size()){
        res[i] = a[b[i]];
    }
    return res;
}
vector<int> power(const vector<int> &a, ll p){
    auto res = a;
    auto temp = a;
    p--;
    for(int i = 0; i < 60; i++){
        if(p >> i & 1){
            res = product(res, temp);
        }
        temp = product(temp, temp);
    }
    return res;
}
ll x[100005];
ll dx[100005];
ll a[100005];
vector<int>b;
signed main(){
    int n;
    cin >> n;
    rep(i,n){
        cin >> x[i];
    }
    rep(i,n-1){
        dx[i] = x[i+1] - x[i];
        //        show(dx[i]);
    }
    int m;
    ll k;
    cin >> m >> k;
    rep(i,n-1){
        b.push_back(i);
    }
    rep(i,m){
        cin >> a[i];
        a[i]--;
        swap(b[a[i]-1],b[a[i]]);
    }
    rep(i,n-1){
        //        show(b[i]);
    }
    auto c = power(b,k);
    ll ans = x[0];
    rep(i,n){
        cout << ans << endl;
        if(i!=n-1){
            ans += dx[c[i]];
        }
    }
}