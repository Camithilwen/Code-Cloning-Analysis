#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

string S;
int num[300001][3][2][3]; // yes even, yes odd, current parity, current num

void ad(int& x, int y) {
    x = (x+y)%MOD;
}

void solve() {
    num[0][0][0][0] = 1;
    F0R(i,sz(S)) F0R(a,3) F0R(b,2) F0R(c,3) if (num[i][a][b][c]) {
        if (S[i] != '1') ad(num[i+1][a][b][c == 2 ? 1 : c+1],num[i][a][b][c]);
        if (S[i] != '0') {
            if (c == 0) {
                if (b == 0) ad(num[i+1][max(a,1)][b^1][0],num[i][a][b][c]);
                else ad(num[i+1][a>0?2:0][b^1][0],num[i][a][b][c]);
            } else if (c == 1) {
                ad(num[i+1][a][b][0],num[i][a][b][c]);
            } else {
                ad(num[i+1][a][b^1][0],num[i][a][b][c]);
            }
        }
    }
    int ans = 0;
    F0R(a,3) F0R(b,2) F0R(c,3) 
        if (a == 2 || (a == 1 && b == 1 && c == 0)) 
            ad(ans,num[sz(S)][a][b][c]);
            
    cout << ans << "\n";
}

string gen() {
    string t;
    F0R(i,5) {
        int k = rand();
        if (k % 3 == 0) t += '0';
        else if (k % 3 == 1) t += '1';
        else t += '?';
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    solve();
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)