#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,N,j) for(int i = (N-1);i >= (j);i--)
#define _rec(i,N,j) for(int i = (N);i >=(j);i--)
#define ALL(x) x.begin(),x.end()
#define MEM(a,n) memset(a,n,sizeof(a))
#define fst first
#define scd second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int get_int(){int x;scanf("%d",&x);return x;}
LL get_ll(){LL x;scanf("%lld",&x);return x;}
double get_db(){double x;scanf("%lf",&x);return x;}

template<typename T> int chmin(T &a,T b){if(a > b){a = b;return 1;}else return 0;}
template<typename T> int chmax(T &a,T b){if(a < b){a = b;return 1;}else return 0;}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {_for(i,0,v.size()) os << v[i] << " ";return os;}
template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){for(auto a:v) os << a <<" ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){os << v.fst <<" "<<v.scd << " ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const map<T1,T2>& v){for(auto a:v) cout << a << endl;return os;}

static const int dx[8] = { -1,  0, 1, 0,  1, -1,  1, -1};
static const int dy[8] = {0,  1, 0,  -1,  1, -1, -1,  1};
const double pi  = acos(-1.0);
const double eps = 1e-8;
const LL  INF  = 0x3f3f3f3f3f3f3f3f;
const int inf  = 0x3f3f3f3f;

const int maxn = 1e5+5;
unsigned long long sum = 0;
LL ans = 0;
LL one = 1;

unsigned long long A[maxn];
int used[maxn];
int cnt[maxn];

char M[62][maxn];

int N;

int Gauss(int H,int W)
{
    int i,j,col;

    for(col = 0;col < W;col++){

        int pivot = -1;
        for(int row = 0;row < H;row++){
            int bit = 61 - row;
            if(used[bit]) continue;
            if(M[row][col] == 1){
                pivot = row;
                break;
            }
        }

        used[61 - pivot] = 1;
        for(int row = 0;row < H;row++){
            int bit = 61 - row;
            if(used[bit]) continue;
            if(M[row][col] == 1){
                for(j = col;j <= W;j++){
                    M[row][j] ^= M[pivot][j];
                }
            }
        }
    }


    return 0;
}


int bit_n(LL t){
    int ret = 0;
    _for(i,0,N){
        if(t & A[i]) ret++;
    }
    return ret;
}

int main()
{
    cin >> N;
    _for(i,0,N) {
        cin >> A[i];
    }
    MEM(used,0);

    for(int bit = 61;bit >= 0;bit--){
        LL t = one<<bit;
        cnt[bit] = bit_n(t);
    }
    MEM(M,0);

    LL ans = 0;

    for(int bit = 0;bit <= 61;bit++){
        LL t = one<<bit;

        if(cnt[bit] == 0) {
            used[bit] = 1;
            continue;
        }
        else if(cnt[bit] & 1) {
            ans += t;
            used[bit] = 1;
            continue;
        }
        else M[61 - bit][N] = 1;


        _for(i,0,N){
            if(t & A[i]){
                if(!used[bit])
                    M[61-bit][i] = 1;
            }
        }
    }

    /*
    _for(i,54,62){
        if(cnt[61-i] == 0 || (cnt[61-i]&1)) continue;
        _rep(j,0,N){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
    */

    Gauss(62,N);


    _rep(i,0,61){
        int bit = 61 - i;
        if(cnt[bit] == 0 || (cnt[bit]) & 1) continue;
        int ok = 0;

        _for(j,0,N) if(M[i][j]) ok = 1;
        if(!M[i][N]) ok = 1;
        if(ok) ans += (one << (bit+1));

    }

    /*
   _for(i,54,62){
        if(cnt[61-i] == 0 || (cnt[61-i]&1)) continue;
        _rep(j,0,N){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
    */
    cout << ans << endl;

    return 0;
}
