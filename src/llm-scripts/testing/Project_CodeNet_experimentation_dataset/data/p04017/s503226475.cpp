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

int N, L, LOGN; // LOGN = floor(log2(N))+1;
VI x;
vector<vector<int>> tab,tab2;
void doubling(){
    for(int i=0; i<N; i++){
        int it = UB(x, x[i]+L);
        if(it-1 == i) tab[i][0] = -1;
        else tab[i][0] = it-1;
    }

    for(int k=0; k<LOGN; k++)
        for(int i=0; i<N; i++){
            if(tab[i][k] == -1) tab[i][k+1] = -1;
            else tab[i][k+1] = tab[tab[i][k]][k];
        }
}

int query(int n, long long k){
    int ret = n, count = 0;
    while(k){
        if(k&1) ret = tab[ret][count];
        count++;
        k >>= 1;
        if(ret == -1) return ret;
    }
    return ret;
}

void doubling2(){
    for(int i=0; i<N; i++){
        int it = LB(x,x[i]-L);
        if(it == i) tab2[i][0] = -1;
        else tab2[i][0] = it;
    }

    for(int k=0; k<LOGN; k++)
        for(int i=0; i<N; i++){
            if(tab2[i][k] == -1) tab2[i][k+1] = -1;
            else tab2[i][k+1] = tab2[tab2[i][k]][k];
        }
}

int query2(int n, long long k){
    int ret = n, count = 0;
    while(k){
        if(k&1) ret = tab2[ret][count];
        count++;
        k >>= 1;
        if(ret == -1) return ret;
    }
    return ret;
}

void Main(){
    cin >> N; LOGN = floor(log2(N))+1; x.resize(N); tab.resize(N,VI(LOGN+1)), tab2.resize(N,VI(LOGN+1));
    REP(i,N) cin >> x[i];
    cin >> L;

    doubling(); doubling2();

    int Q; cin >> Q;
    REP(_,Q){
        int a,b; cin >> a >> b; a--; b--;
        int ans;
        if(a < b){
            int l = 0, r = N;
            while(r-l>1){
                int k = (l+r)/2;
                int loc = query(a,k);
                if(loc<b && loc!=-1) l = k;
                else r = k;
            }
            ans = r;
        }
        else{
            int l = 0, r = N;
            while(r-l>1){
                int k = (l+r)/2;
                int loc = query2(a,k);
                if(b<loc) l = k;
                else r = k;
            }
            ans = r;
        }
        cout << ans << en;
    }
    return;
}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}