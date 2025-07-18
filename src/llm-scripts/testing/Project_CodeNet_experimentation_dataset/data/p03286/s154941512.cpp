#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<int>> vvint;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<int, vector<int>, greater<int>> spqint; //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;     //小さい順に取り出し
typedef priority_queue<int, vector<int>, less<int>> bpqint;    //大きい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;        //大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define TS to_string
#define BS binary_search
#define LB lower_bound
#define UB upper_bound
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


int INF = 1e9;
int NIL = -1;
ll MOD = 1000000007;
ll LINF = 1e18;
double EPS = 1e-9;
double PI = M_PI;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}
//-----------------------------------------

//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::chrono::system_clock::time_point start,end;
    start = std::chrono::system_clock::now();

    ll n ;
    cin >> n ;
    string ans = "" ;
    vll vecp ;
    vll vecm ;
    map<ll,string> mapp ;
    map<ll,string> mapm ;
    if(n==0){
        cout << 0 <<endl;
        return 0 ;
    }

    ll m = 16 ;

    for (int bitt = 0; bitt < (1 << m); bitt++) {
        bitset<16> bits(bitt); 
        ll tmp = 0 ;

        /*
        if(bits.any()==false){
            continue ;
        }
        */

        for(ll j=0;j<m;j++){
            if(bits[j]==1){
                tmp += pow(4,j) ;
            }
        }
        vecp.PB(tmp) ;
        stringstream ss ;
        ss << bits ;
        string ts = ss.str() ;
        mapp[tmp] = ts ; 
    }

    for (int bitt = 0; bitt < (1 << m); bitt++) {
        bitset<16> bits(bitt); 
        ll tmp = 0 ;

        /*
        if(bits.any()==false){
            continue ;
        }
        */

        for(ll j=0;j<m;j++){
            if(bits[j]==1){
                tmp -= 2*pow(4,j) ;
            }
        }
        vecm.PB(tmp) ;
        stringstream ss ;
        ss << bits ;
        string ts = ss.str() ;
        mapm[tmp] = ts ; 
    }

    sort(ALL(vecp)) ;
    sort(ALL(vecm)) ;

    ll ansi, ansj ;

    REP(i,SZ(vecp)){
        ll hog = n - vecp[i] ;
        if(BS(ALL(vecm),hog)){
            ansi = vecp[i] ;
            ansj = hog ;
            break ;
        }
    }
    string ps = mapp[ansi] ;
    string ms = mapm[ansj] ;

    REP(i,SZ(ps)){
        ans += ms[i] ;
        ans += ps[i] ;
    }
    string nans = "" ;
    REP(i,SZ(ans)){
        if(nans=="" && ans[i]=='0'){
            continue ;
        }
        else{
            nans += ans[i] ;
        }
    }

    cout << nans <<endl;





    end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count();
    //std::cout << elapsed <<"ms"<< std::endl;

    

    return 0;
}

