
#include <bits/stdc++.h>

using namespace std;

/* g++ -g -fsanitize=address -lasan -std=c++11 -Dfoo_ */

/* freopen("input.txt", "rt", stdin); */
/* freopen("output.txt", "wt", stdout); */

#define ALL(c)          (c).begin(), (c).end()
#define ALLR(c)         (c).rbegin(), (c).rend()
#define FOR(i,a,b)      for (int i=(a); i < (b); ++i)
#define FORR(i,a,b)     for (int i=(a); i > (b); --i)
#define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
                             i != (c).end(); ++i)
#define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
                             i != (c).rend(); ++i)
#define SZ(array)       (sizeof(array)/sizeof(array[0]))
#define lc(x)           (x<<1)     /* 2*x */
#define rc(x)           (x<<1 | 1) /* 2*x+1 */
#define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */

typedef long long       LL;
typedef map<int,int>    MII;
typedef pair<int,int>   PII;
typedef set<int>        SI;
typedef vector<bool>    VB;
typedef vector<double>  VD;
typedef vector<int>     VI;
typedef vector<string>  VS;

/* check if a key is in container C */
template <class C>
inline bool in_(const typename C::key_type& k, const C& A)
{ return A.find(k) != A.end(); }
inline bool in_(const string& s, const string& S)
{ return S.find(s) != string::npos; }

int n,m,v,p;
vector<LL> A;

bool P(const int i, int v)
{
    if (n-i <= p)
        return true;
    /* everyone pick i */
    const LL x = A[i]+m;
    /*
     * We need i to be in the top p, so everyone can pick any of the
     * top p-1 w/o effecting i.
     */
    int j = n - min(p,v);
    if (x < A[n-p])
        return false;
    v -= n-(j+1)+1;             /* the top ones can't effect i */
    v -= i;                     /* anyone before i can't catch i */
    if (v > 0) {
        /*
         * m people, each select v number of problems. We need to
         * distribute the selection in a box such that max in the
         * box not exceed x.
         */
        while (A[j] > x)
            j--;
        const int y = j-i;      /* box width */
        LL vol = x*y;           /* box volume */
        FOR(k,i+1,j+1)
            vol -= A[k];
        return vol >= 1LL * v*m;
    }
    return true;
}

int main()
{
#ifdef foo_
    freopen("foo", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> v >> p) {
        A.resize(n);
        FOR(i,0,n)
            cin >> A[i];
        sort(ALL(A));
        int lo = 0, hi = n-1;
        while (lo < hi) {
            const int mid = (lo+hi)/2;
            if (P(mid,v))
                hi = mid;
            else
                lo = mid+1;
        }
        cout << n-lo << endl;
    }
    return 0;
}
