// ALPC-B.cpp

#include <iostream>
#include <atcoder/fenwicktree.hpp>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(ll i=0;i<(n);++i)
using ll = long long;
int main()
{
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);
    ll a;
    rep(i, n) {
        cin >> a;
        fw.add(i, a); // fwに値をセット
    }
    ll q0, q1, q2;
    rep(i, q) {
        cin >> q0 >> q1 >> q2;
        if (q0 == 0) {
            fw.add(q1, q2); // fwの値を更新
        }
        if (q0 == 1) {
            cout << fw.sum(q1, q2) << endl; // fwで区間和を求める
        }
    }
}
