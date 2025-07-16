#include<atcoder/all>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;
using namespace atcoder;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
//cout << fixed << setprecision(10) << ans << endl;
//int gcd(int a,int b){return b?gcd(b,a%b):a;}

// segtree
// 型 S, 二項演算 S op(S a, S b), 単位元 S e() を設定
// segtree<int, op, e> seg(10); // 要素数n、segという名前で作成
// seg.set(int p, S x) // a[p]にxを代入
// S seg.get(int p) // a[p]を返す
// S seg.prod(int l, int r) // op(a[l], ..., a[r - 1])を返す
// S seg.all_prod() // op(a[0], ..., a[n - 1])を返す
// int seg.max_right<f>(int l) // f(op(a[l], a[l + 1], ..., a[r - 1])) = trueとなる最大のr


int op(int a, int b){
    return a+b;
}

int e(){
    return 0;
}

signed main(){
    int n,q;
    cin >> n >> q;
    segtree<int, op, e> seg(n);
    REP(i,n){
        int a1;
        cin >> a1;
        seg.set(i,a1);
    }
    
    REP(i,q){
        int q1;
        int q2,q3;
        cin >> q1 >> q2 >> q3;
        if(q1==0){
            seg.set(q2,seg.get(q2)+q3);
        }
        else{
            cout << seg.prod(q2,q3) << endl;
        }

    }



    return 0;
}