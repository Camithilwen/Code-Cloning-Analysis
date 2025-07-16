#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,(n))
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N, Q, a, b, c;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    rep(i, N) {
        cin >> a;
        fw.add(i, a);
    }
    rep(i, Q) {
        cin >> a >> b >> c;
        if (a) {
            cout << fw.sum(b, c) << endl;
        } else {
            fw.add(b, c);
        }
    }
}