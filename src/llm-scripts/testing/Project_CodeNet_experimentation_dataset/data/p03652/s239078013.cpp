#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007; // 998244353

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
struct SegmentTree {
	typedef function<T(T,T)> F;
    typedef function<T(T,T)> G;
    int n;
    F f;
    G g;
    T e;

    vector<T> val;

    SegmentTree(vector<T> a, F f_, G g_, T e):
        f(f_), g(g_), e(e){
            int sz = a.size();
            n = 1;

            while (n < sz) n <<= 1;
            val.resize(2 * n - 1, e);
            for (int i = 0; i < sz; i++) val[i + n - 1] = a[i];
            for (int i = n - 2; i >= 0; i--) val[i] = f(val[i * 2 + 1], val[i * 2 + 2]);
        }
    
        SegmentTree() {}

        void update(int pos, T v) {
            // 0-indexed
            int k = pos + n - 1;
            val[k] = g(val[k], v);
            while (k > 0) {
                k = (k - 1) / 2;
                val[k] = f(val[k * 2 + 1], val[k * 2 + 2]);
            }
        }

        T get(int pos) {
            // 0-indexed
            int k = pos + n - 1;
            return val[k];
        }

        T query(int a, int b, int k = 0, int l = 0, int r = -1) {
            // 0-indexed
            // [a,b)に対してquery
            if (r < 0) r = n;
            if (r <= a || b <= l) return e;
            if (a <= l && r <= b) return val[k];
            T lv = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T rv = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return f(lv, rv);
        }
};

int main(void){
    auto f = [](P a, P b){
        return max(a,b);
    };
    auto g = [](P a, P b){
        return P(a.first+b.first, a.second);
    };

    int N,M; cin >> N >> M;
    VVI A(N,VI(M)); REP(i,N)REP(j,M) cin >> A[i][j];
    REP(i,N) REVERSE(A[i]);

    int l=0, r=N, n=(l+r)/2;
    while(r-l>1){
        VVI B(A);
        int s = 1000;
        set<int> removed;
        while(s > n){
            vector<P> a(M);
            REP(i,M){
                a[i].first = 0;
                a[i].second = i;
            }
            SegmentTree<P> st(a, f, g, P(0,0));
            REP(i,N){
                if(B[i].size()) st.update(B[i].back()-1, P(1,0));
            }
            P mx = st.query(0,M);
            s = mx.first;
            if(s > n){
                removed.insert(mx.second);
                REP(i,N){
                    while(B[i].size() && removed.count(B[i].back()-1)) B[i].pop_back();
                }
            }
        }
        if(s == 0) l = n;
        else r = n;
        n = (l+r)/2;
    }
    int ans = r;
    cout << ans << endl;
    return 0;
}