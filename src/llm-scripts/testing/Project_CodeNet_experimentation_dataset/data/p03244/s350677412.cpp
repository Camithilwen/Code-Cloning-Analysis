#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = long long ;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    vi v(n);
    rep(i,n) cin >> v.at(i);
    // 全部同じはダメ
    vi a(100100,0);
    vi b(100100,0);
    rep(i,n){
        if(i%2){
            // 奇数
            a.at(v.at(i))++;
        }else{
            // 偶数
            b.at(v.at(i))++;
        }
    }
    vector<P> va;
    vector<P> vb;
    rep(i,a.size()){
        va.push_back(make_pair(a.at(i),i));
    }
    rep(i,b.size()){
        vb.push_back(make_pair(b.at(i),i));
    }
    sort(va.begin(), va.end(), greater<>());
    sort(vb.begin(), vb.end(), greater<>());
    ll a1=va.at(0).first;
    ll a2=va.at(1).first;
    ll b1=vb.at(0).first;
    ll b2=vb.at(1).first;
    ll a1i=va.at(0).second;
    ll b1i=vb.at(0).second;
    cerr << "a1:" << a1 << " b1:" << b1 << endl;
    cerr << "a2:" << a2 << " b2:" << b2 << endl;
    ll res = 0;
    if(a1i!=b1i){
        res += (n/2) - a1;
        res += (n/2) - b1;
    }else{
        if(a2 >= b2){
            res += (n/2) - a2;
            res += (n/2) - b1;
        }else{
            res += (n/2) - a1;
            res += (n/2) - b2;
        }
    }
    cout << res << endl;
}
