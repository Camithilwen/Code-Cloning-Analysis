#include <iostream>
#include <vector>
#define ll long long
using namespace std;
 
vector<ll> value; // ノードの値を持つ配列
ll N;             // 葉の数
 
void update(ll i, ll x) {
    // i 番目の葉の値を x に変える
    i += N - 1; // i 番目の葉のノード番号
    value[i] += x;
    while (i > 0) {
        i = (i - 1) / 2; // ノード i の親ノードの番号に変える
        value[i] = value[i * 2 + 1]+value[i * 2 + 2];
    }
}
 
ll query(ll a, ll b, ll k, ll l, ll r) {
    // [a, b) の区間に対するクエリについて
    // ノード k （区間 [l, r) 担当）が答える
    if (r <= a || b <= l) return 0; 
    else if (a <= l && r <= b) return value[k]; // ノード k の担当範囲がクエリ区間 [a, b) に完全に含まれる
    else {
        ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
        ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
        return c1+c2; 
    }
}
 
int main(void) {
    ll n , q;
    cin >> n >> q;
    N = 1;
    while (N <= n) N *= 2; // 葉の数を計算（n以上の最小の2冪数） //大きめに設定
    
    value = vector<ll>(2 * N - 1, 0); //二項目が初期値
    
    for(ll i=0; i<n; i++){
        ll p; cin>>p;
        update(i,p);
    }
 
    for (ll j = 0; j < q; j++) {
        ll c;
        cin >> c;
        if (c == 0) {
            ll i, x;
            cin >> i >> x;
            update(i, x);
        } else {
            ll s, t;
            cin >> s >> t;
            cout << query(s, t , 0, 0, N) << endl;
        }
    }
    return 0;
}