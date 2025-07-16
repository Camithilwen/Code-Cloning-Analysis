#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
const ll INF = 1e16;
#define PI (acos(-1))
//const ll mod = 1000000007;
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree() {
        int sz = 200050;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = INF;
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }

    // k 番目のノードについて遅延評価を行う
    void eval(int k, int l, int r) {

    // 遅延配列が空でない場合、自ノード及び子ノードへの
    // 値の伝播が起こる
        if(lazy[k] != 0) {
            node[k] += lazy[k];

        // 最下段かどうかのチェックをしよう
        // 子ノードは親ノードの 1/2 の範囲であるため、
        // 伝播させるときは半分にする
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }

        // 伝播が終わったので、自ノードの遅延配列を空にする
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

    // k 番目のノードに対して遅延評価を行う
        eval(k, l, r);

    // 範囲外なら何もしない
        if(b <= l || r <= a) return;
    
    // 完全に被覆しているならば、遅延配列に値を入れた後に評価
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }

    // そうでないならば、子ノードの値を再帰的に計算して、
    // 計算済みの値をもらってくる
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

    ll getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

    // 関数が呼び出されたらまず評価！
        eval(k, l, r);

        if(b <= l || r <= a) return 1e17;
        if(a <= l && r <= b) return node[k];
        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }

};



int main() {
    //cout.precision(10);
    LazySegmentTree seg, forward, backward;
    ll N, Q, A, B;
    cin >> N >> Q >> A >> B;
    for(int i = 1; i <= N; i++) {
        forward.add(i, i + 1, i);
        backward.add(i, i + 1, (N - i));
    }
    seg.add(A, A+1, -INF);
    forward.add(A, A+1, -INF);
    backward.add(A, A+1, -INF);
    //cerr << backward.getmin(1, 3) << endl;
    ll before = B;
    while(Q--) {
        ll x;
        cin >> x;
        ll val = backward.getmin(1, x) - N + x;
        //cerr << val << endl;
        val = min(val, forward.getmin(x, N + 1) - x);
        //cerr << val << endl;
        seg.add(1, N + 1, abs(x - before));
        forward.add(1, N + 1, abs(x - before));
        backward.add(1, N + 1, abs(x - before));
        ll beforeval = seg.getmin(before, before + 1);
        //cerr << seg.getmin(before, before + 1) << endl;
        seg.add(before, before + 1, val - beforeval);
        //cerr << seg.getmin(before, before + 1) << endl;
        forward.add(before, before + 1, val - beforeval);
        //cerr << forward.getmin(before, before + 1) << endl;
        backward.add(before, before + 1, val - beforeval);
        //cerr << backward.getmin(before, before + 1) << endl;
        before = x;
        //cerr << endl << Q << endl;
        /*
        for(int i = 1; i <= N; i++) {
            cerr << i << " " << seg.getmin(i, i + 1) << endl;
        }
        */
    }
    cout << seg.getmin(1, N + 1) << endl;
    return 0;
}
