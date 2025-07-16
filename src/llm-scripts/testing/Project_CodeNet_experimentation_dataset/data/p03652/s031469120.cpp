#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}
const int INF = 1e18;

int N, M;
vvi A(305, vi(305));

int dfs(int n, V(bool) D) {
    if(n==0) return 0;
    //int res = INF;
    int t = 0;
    vi cnt(M, 0);
    rep(i, N) {
        rep(j, M) {
            if(D[A[i][j]]) {
                cnt[A[i][j]]++;
                break;
            }
        }
    }
    int mi = 0;
    rep(i, M) {
        if(cnt[i]>cnt[mi]) mi = i;
    }
    int res = cnt[mi];
    D[mi] = false;
    int nx = dfs(n-1, D);
    if(nx) res = min(res, nx);
    return res;
}

signed main() {
    cin >> N >> M;
    rep(i, N) rep(j, M) {
        cin >> A[i][j];
        A[i][j]--;
    }

    V(bool) D(M, true);

    cout << dfs(M, D) << endl;

    return 0;
}