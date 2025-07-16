#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,n,a) for(int i = (int)(n); i >= (int)(a); i--)
#define fi first
#define se second

using ll = long long;
using v_int = std::vector<int>;
using v2_int = std::vector<v_int>;
using v_ll = std::vector<ll>;
using v2_ll = std::vector<v_ll>;
using v_string = std::vector<std::string>;
using v_bool = std::vector<bool>;
using v2_bool = std::vector<v_bool>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using mii = std::map<int, int>;
using mll = std::map<ll, ll>;

const double PI = 3.1415926535897932;
const int INF = 2*(int)1e9;
const ll LINF = (ll)1e18;
const ll MOD = 1000000007;
const int dc[4] = {1, -1, 0,  0};
const int dr[4] = {0,  0, 1, -1};
//const int dc[8] = {1, -1, 0,  0, 1, -1,  1, -1};
//const int dr[8] = {0,  0, 1, -1, 1,  1, -1, -1};

using namespace std; 

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p)
{
    return o << "{" << p.first << "," << p.second << "}";
}

template<typename T> inline
istream& operator>>(istream &is, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) {
        is >> v[i]; 
    }
    return is;
}

template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) { 
        os << v[i];
        if(i != len-1) { os << ","; } 
    } 
    return os;
}

template<typename T> inline
void chmin(T &a, T b) { a = min(a, b); }

template<typename T> inline
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    int h, w;
    cin >> h >> w;
    
    v_string s(h);
    cin >> s;
    
    queue<pii> q;
    v2_int dist(h, v_int(w, 0));
    v2_bool done(h, v_bool(w, false));
    irep(i, h) {
        irep(j, w) {
            if(s[i][j] == '#') {
                q.push(pii(i,j));
                done[i][j] = true;
            }
        }
    }
        
    while(q.size()) {
        pii t = q.front(); q.pop();
        irep(x,4) {
            int row = t.fi + dr[x];
            int col = t.se + dc[x];
            if(row < 0 || row >= h) { continue; }
            if(col < 0 || col >= w) { continue; }
            if(s[row][col] == '#' || done[row][col]) { continue; }
            done[row][col] = true;
            dist[row][col] = dist[t.fi][t.se] + 1;
            q.push(pii(row,col));
        }
    }

    int ans = 0;
    irep(i, h) {
        irep(j, w) {
            chmax(ans, dist[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}

/*atcoder*/
