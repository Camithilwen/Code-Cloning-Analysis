#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }



int n;
vector<ll> a;

const int MAX_COL = 63;
const int MAX_ROW = 100005;



struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) { return val[i]; }
};

BitMatrix mat(100005, 61);

int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // cout << bitset<61>(1008288677408720767) << endl;
    
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    
    
    
    rep(i, n) rep(j, 61) {
        if (a[i] & (1LL << j)) {
            mat[i][60 - j] = 1;
        } else mat[i][60 - j] = 0;
    }
    
    // rep(i, n) { rep(j, 60) cout << mat[i][j] << " "; cout << endl; }
    
    // たてのbit数える
    ll ans = 0;
    rep(j, 61) {
        int cnt = 0;
        rep(i, n) {
            // if (mat[i][j] & (1LL << (59 - j))) cnt++; // mat[i][j]は1, 0 -> 1LL << とかやばい
            if (mat[i][j] == 1) cnt++;
        }
        // cout << j << " " << cnt << endl;
        if (cnt % 2) {
            ans += (1LL << (60 - j));
            rep(i, n) mat[i][j] = 0;
        }
    }
    // cout << "ans " << ans << endl;
    // cout << endl; rep(i, n) { rep(j, 60) cout << mat[i][j] << " "; cout << endl; }
    
    GaussJordan(mat);
    // cout << endl; rep(i, n) { rep(j, 60) cout << mat[i][j] << " "; cout << endl; }
    
    // int r = 0;
    rep(j, 61) {
        int cnt = 0;
        rep(i, n) {
            if (mat[i][j] == 1) cnt++;
            /*
            if (mat[i][j] == 1 && r == i) {
                // cout << i << " " << j << " " << ans << endl;
                ans += (2LL << (59 - j));
                r++;
            }
             */
        }
        if (cnt % 2) ans += (2LL << (60 - j));
    }
    cout << ans << endl;
}
