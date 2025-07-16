#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
struct edge{long long to,cost;};
const int inf = 1 << 27;
const long long INF = 1LL << 60;
const int COMBMAX = 1001001;
const long long MOD = 1000000007;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define eachdo(v, e) for(const auto& e : (v))
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (long long)distance((v).begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (long long)distance((v).begin(), upper_bound((v).begin(), (v).end(), e))
long long mpow(long long a, long long n, long long mod = MOD){long long res = 1; while(n > 0){if(n & 1)res = res * a % mod; a = a * a % mod; n >>= 1;} return res;}
void yn(bool j){cout << (j ? "Yes" : "No") << endl; return;}
template<class Head> void pt(Head&& head){cout << head << endl; return;}
template<class Head, class... Tail> void pt(Head&& head, Tail&&... tail){cout << head << " "; pt(forward<Tail>(tail)...);}
template<class T> void debug(T v){rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void debug2(T v){rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}
template<class T1, class T2> long long bcount(T1 v, T2 a){return upper_index(v, a) - lower_index(v, a);} 
template<class T1, class T2> inline bool chmin(T1 &a, T2 b){if(a > b){a = b; return true;} return false;}
template<class T1, class T2> inline bool chmax(T1 &a, T2 b){if(a < b){a = b; return true;} return false;}
template<class T1, class T2> void sortTwoVecter(vector<T1> &f, vector<T2> &s, bool isReverse = false){
    vector<pair<T1, T2>> p;
    rep(i, f.size()) p.emplace_back(make_pair(f[i], s[i]));
    if (!isReverse) sort(p.begin(), p.end());
    else sort(p.rbegin(), p.rend());
    rep(i, f.size()) tie(f[i], s[i]) = p[i];
    return;
}

int main(){
    ll N; cin >> N;
    vector<ll> a(N + 2, 0), s(N + 2, 0);
    rep(i, N){
        cin >> a[i + 1];
        s[i + 1] = s[i] + abs(a[i] - a[i + 1]);
    }
    s[N + 1] = s[N] + abs(a[N] - a[N + 1]);

    rep(i, N){
        pt(s[i] + abs(a[i + 2] - a[i]) + s[N + 1] - s[i + 2]);
    }
    return 0;
}

