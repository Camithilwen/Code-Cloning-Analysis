//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

// ?????¬???????????¬??????
#pragma region MACRO
#define P(x) cout << (x) << endl
#define p(x) cout << (x)
#define PED cout << "\n"
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define REP(i,x,n) for(int i=x; i<(int)n; ++i)
#define repi(i,n) for(int i=0; i<=(int)n; ++i)
#define REPI(i,x,n) for(int i=x; i<=(int)n; ++i)
#define ILP while(true)
#define FOR(i,c) for(__typeof((c).begin())!=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#pragma endregion

// ???
#pragma region TYPE_DEF
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long double> vld;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<string> vs;
#pragma endregion

// Effective std
#pragma region ESTD
template<typename C, typename T> int count(C& c, T t) { return count(ALL(c), t); }
template<typename C, typename F> int count_if(C& c, F f) { return count_if(ALL(c), f); }
template<typename C, typename T> void erase(C& c, T t) { remove(ALL(c), t), c.end(); }
template<typename C> void remove(vector<C>& c, unsigned int index) { c.erase(c.begin()+index); }
template<typename C, typename T, typename U> void replace(C& c, T t, U u) { replace(ALL(c), t, u); }
template<typename C, typename F, typename U> void replace_if(C& c, F f, U u) { (ALL(c), f, u); }
template<typename C> void reverse(C& c) { reverse(ALL(c)); }
template<typename C> void sort(C& c) { sort(ALL(c)); }
template<typename C, typename Pred> void sort(C& c, Pred p) { sort(ALL(c), p); }
#pragma endregion

// ?????°
#pragma region CONST_VAL
constexpr int PI = (2*acos(0.0));
constexpr int EPS = (1e-9);
constexpr int MOD = (int)(1e9+7);
constexpr int INF = 100000000;
#pragma endregion

bool is_small(int h1, int w1, int h2, int w2) {
    int d1 = h1*h1 + w1*w1;
    int d2 = h2*h2 + w2*w2;
    if(d1 < d2) return true;
    else if(d1 > d2) return false;
    else if(h1<h2) return true;
    else return false;
}

int main()
{
    int h, w;
    while(cin>>h>>w, h) {
        int mh = 151;
        int mw = 151;
        for(int i=1; i<=150; ++i) {
            for(int j=i+1; j<=150; ++j) {
                if(i==h&&j==w) continue;
                if(is_small(i,j,h,w)) continue;
                if(is_small(i,j,mh,mw)) {
                    mh = i;
                    mw = j;
                }
            }
        }
        cout << mh << " " << mw << endl;
    }
    return 0;
}