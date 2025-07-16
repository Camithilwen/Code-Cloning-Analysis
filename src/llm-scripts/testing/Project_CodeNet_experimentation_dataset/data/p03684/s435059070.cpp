#include<bits/stdc++.h>
using namespace std;
//type
typedef long long ll;
#define pii pair<int, int>
#define vi vector<int>
//x * y * 1.0 can cause overflow
//constant
#define inf (int)(1e9+7)
#define mod (ll)(1e9+7)
#define eps 1e-10
//omission
#define eb emplace_back
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define all(v) v.begin(), v.end()
#define ios cin.tie(0); ios::sync_with_stdio(false)
#define FIX(a) cout << fixed << setprecision(a)
//manip
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end(), v.end());
#define fill(x, y) memset(x, y, sizeof(x))
#define ceil(a, b) a / b + !!(a % b)
template<class T> T power(T a, T b)
{return b ? power(a * a % inf, b / 2) * (b % 2 ? a : 1) % inf : 1;}
#define LB(v, x) (int)(lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (int)(upper_bound(v.begin(), v.end(), x) - v.begin())
template<typename T> T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template<typename T> T lcm(T a, T b) {return a / gcd(max(a, b), min(a, b)) * b;} //先に割る!!
#define outa(a, n) rep(i, n) cout << a[i] << " "; cout << endl
#define out(a) cout << a << endl
#define outv(v) rep(i, SZ(v)) cout << v[i] << " "; cout << endl
//loop
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep3(i, st, n) for (int i = st; i < n; ++i)
//algorithm
//double pointer, l start, how many adds, can be 0 -> init r = l, sum = 0
//bfs, not x, y, i, j
//not !(i % 2), i % 2 == 0
//minimal required terms
//cast caution
//look constraints always


/*
 最小全域木
 
 どうやってcostでsortするかがpointかな
 
 組み合わせ考えたらN^2
 
 解説見た
 ある点と、その点から2本以上の辺を通って着く点との距離は、すべての点で隣だけ見たら求まる
 
 cost = min(|a - c|, |b - d|)より
 
 
 
 */



class UnionFind {
public:
    vector<int> Parent;
    UnionFind(int N) {
        Parent = vector<int>(N, -1);
    }
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    int size(int A) {
        return -Parent[root(A)];
    }
    bool connect(int A, int B) {
        A = root(A);
        B = root(B);
        if (A == B) {
            return true;
        }
        if (size(A) < size(B)) swap(A, B);
        Parent[A] += Parent[B];
        Parent[B] = A;
        return false;
    }
};


bool comp(pair<int, pii> a, pair<int, pii> b) {
    return a.S.F < b.S.F;
}
bool comp2(pair<int, pii> a, pair<int, pii> b) {
    return a.S.S < b.S.S;
}
bool compv(pair<pii, int> a, pair<pii, int> b) {
    return a.S < b.S;
}

int main() {
    
    
    
    
    int n; cin >> n;
    pair<int, pii> p[n];
    rep(i, n) {cin >> p[i].S.F >> p[i].S.S; p[i].F = i;}
    
    sort(p, p + n, comp);
    vector<pair<pii, int> > v; //id1, id2, cost
    rep3(i, 1, n) {
        v.eb(pii(p[i].F, p[i - 1].F), p[i].S.F - p[i - 1].S.F);
    }
    sort(p, p + n, comp2);
    //cout << endl; rep(i, n) cout << p[i].F << " " << p[i].S.F << " " << p[i].S.S << endl;
    rep3(i, 1, n) {
        v.eb(pii(p[i].F, p[i - 1].F), p[i].S.S - p[i - 1].S.S);
    }
    sort(all(v), compv);
    
    //cout << endl; rep(i, SZ(v)) cout << v[i].F.F << " " << v[i].F.S << " " << v[i].S << endl;
    
    
    
    UnionFind uni(n);
    ll ans = 0;
    rep(i, SZ(v)) {
        if (uni.connect(v[i].F.F, v[i].F.S) == 1) continue;
        //cout << v[i].F.F << " " << v[i].F.S << " " << v[i].S << endl;
        ans += v[i].S;
    }
    out(ans);
    
    
}
