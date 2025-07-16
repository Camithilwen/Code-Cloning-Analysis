#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,n,a) for(int i = (int)(n); i >= (int)(a); i--)

#define fi first
#define se second

using namespace std; 

using ll = long long;
using v_int = vector<int>;
using v2_int = vector<v_int>;
using v_ll = vector<ll>;
using v2_ll = vector<v_ll>;
using v_string = vector<string>;
using v_bool = vector<bool>;
using v2_bool = vector<v_bool>;
using pii = pair<int, int>;
using mii = map<int, int>;

const double PI = 3.1415926535897932;
const int INF = (int)2e9;
const ll LINF = (ll)2e18;
const ll MOD = 1000000007;
const int dc[8] = {1, -1, 0,  0, 1, -1,  1, -1};
const int dr[8] = {0,  0, 1, -1, 1,  1, -1, -1};

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p) {
    return o << "{" << p.first << "," << p.second << "}";
}
template<typename T> inline
istream& operator>>(istream &is, vector<T> &vec) {
    for(auto &v : vec) { is >> v; }
    return is;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &vec) {
    for(auto &v : vec) { os << v << ",";} 
    return os;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<vector<T> > &mat) {
    for(auto &row : mat) { os << row << endl; }
    return os;
}
template<typename T> inline
void chmin(T &a, T b) { a = min(a, b); }
template<typename T> inline
void chmax(T &a, T b) { a = max(a, b); }

void binary(int &l, int &r, v_int & v, int u)
{
    while(r-l>1) {
        int mid = (r+l)/2;
        if(v[mid] > u) {
            r = mid;
        } else {
            l = mid;
        }
    }
}

void binary2(int &l, int &r, v_int & v, int u)
{
    while(r-l>1) {
        int mid = (r+l)/2;
        if(v[mid] >= u) {
            r = mid;
        } else {
            l = mid;
        }
    }
}

int main(void)
{
    int n;
    cin >> n;

    v_int a(n), b(n), c(n);
    cin >> a >> b >> c;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;

    irep(i, n) {
        int la = -1, ra = n;
        binary2(la, ra, a, b[i]);
        if(la == -1) { continue; }

        int lc = -1, rc = n;
        binary(lc, rc, c, b[i]);
        if(rc == n) { continue; }

        ans += (ll)(la+1) * (n-rc);
    }
    cout << ans << endl;
    return 0;
}

/*atcoder*/

