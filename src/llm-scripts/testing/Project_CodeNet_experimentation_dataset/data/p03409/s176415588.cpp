#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define EXIST(m,v) (m).find((v)) != (m).end()
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

struct MaxFlow{
    int n;
    struct edge{
        int to, cap, rev;
        edge(int to, int cap, int rev):to(to), cap(cap), rev(rev) {}
    };
    vector<vector<edge>> G;
    vector<int> level, iter;

    MaxFlow(int N): n(N){
        G.resize(N);
        level.resize(N);
        iter.resize(N);
    }

    void add_edge(int from, int to, int cap){
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, 0, G[from].size()-1);
    }

    void bfs(int s){
        level.assign(n, -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int i=0; i<G[v].size(); i++){
                edge& e = G[v][i];
                if(0 < e.cap && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f){
        if(v == t) return f;
        for(int& i = iter[v]; i<G[v].size(); i++){
            edge& e = G[v][i];
            if(0 < e.cap && level[v] < level[e.to]){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t){
        // O(|E||V|^2)
        int flow = 0;
        for(;;){
            bfs(s);
            if(level[t] < 0) return flow;
            iter.assign(n, 0);
            int f;
            while((f = dfs(s, t, INF)) > 0){
                flow += f;
            }
        }
    }
};

void Main(){
    int N; cin >> N;
    VI a(N), b(N), c(N), d(N);
    REP(i,N) cin >> a[i] >> b[i];
    REP(i,N) cin >> c[i] >> d[i];

    MaxFlow mf(N+N+2);
    REP(i,N)REP(j,N){
        if(a[i]<c[j] && b[i]<d[j]) mf.add_edge(i,j+N,1);
    }
    REP(i,N){
        mf.add_edge(N+N,i,1);
        mf.add_edge(i+N,N+N+1,1);
    }

    int ans = mf.max_flow(N+N,N+N+1);
    cout << ans << en;
    return;
}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}