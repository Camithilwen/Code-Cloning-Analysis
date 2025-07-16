#include "bits/stdc++.h"
 
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long LL;
typedef priority_queue<int> PQ_DESC;
typedef priority_queue<int, vector<int>, greater<int>> PQ_ASC;
typedef priority_queue<PII> PQ_DESC_PII;
typedef priority_queue<PII, vector<PII>, greater<PII>> PQ_ASC_PII;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;

#define SORT_ASC(c) sort((c).begin(), (c).end())
#define SORT_DESC(c) sort((c).begin(), (c).end(), greater<typeof((c).begin())>())
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define FORL(i,a,b) for(LL i=(a);i<(b);++i)
#define REPL(i,n)  FORL(i,0,n)
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
 
const double EPS = 1e-10;
const double PI  = acos(-1.0);
 
template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
   /* Credits: Thomas Draper */
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator itr1 = first;
   Iterator itr2 = last;
   ++itr1;
   if (last == itr1)
      return false;
   itr1 = last;
   --itr1;
   itr1 = k;
   --itr2;
   while (first != itr1)
   {
      if (*--itr1 < *itr2)
      {
         Iterator j = k;
         while (!(*itr1 < *j)) ++j;
         iter_swap(itr1,j);
         ++itr1;
         ++j;
         itr2 = k;
         rotate(itr1,j,last);
         while (last != j)
         {
            ++j;
            ++itr2;
         }
         rotate(k,itr2,last);
         return true;
      }
   }
   rotate(first,k,last);
   return false;
}

inline double get_time_sec(void){
    return static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count())/1000000000;
}

template<typename T>
T gcd(T a, T b) {
    if(a > b) swap(a, b);
    if(a == 0) return b;
    else return gcd(b%a, a);
}

template<typename T>
map<T, T> prime_list(T n) {
    map<T, T> ret;
    for(T i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            ret[i] = 0;
            while(n % i == 0) {
                n /= i;
                ret[i]++;
            }
        } 
    }
    if(n != 1) ret[n]++;
    return ret;
}

#define MOD 1000000007

LL mypow(LL a, LL n) {
    if(n == 1) return a % MOD;
    if(n % 2 == 1) return (a * mypow(a, n-1)) % MOD;
    LL t = mypow(a, n/2);
    return (t * t) % MOD; 
}

int main(void) {
    int n;
    cin >> n;
    VPII ab, cd;
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        ab.push_back(make_pair(a, b));
    }
    REP(i, n) {
        int c, d;
        cin >> c >> d;
        cd.push_back(make_pair(c, d));
    }
    auto cmpx = [](PII x, PII y) {
        return x.first < y.first;
    };
    auto cmpy = [](PII x, PII y) {
        return x.second > y.second;
    };
    sort(ALL(ab), cmpy);
    sort(ALL(cd), cmpx);

    REP(i, n) {
        cerr << "a, b: " << ab[i].first << ", " << ab[i].second << endl;
    }
    REP(i, n) {
        cerr << "c, d: " << cd[i].first << ", " << cd[i].second << endl;
    }

    vector<bool> flgsab(n, true), flgscd(n, true);
    int ans = 0;
    REP(i, n) {
        REP(j, n) {
            if(cd[i].first > ab[j].first && cd[i].second > ab[j].second && flgsab[j] && flgscd[i]) {
                cerr << "a, b: c, d: " << ab[j].first << ", " << ab[j].second << ": " << cd[i].first << ", " << cd[i].second << endl;
                ans++;
                flgsab[j] = false;
                flgscd[i] = false;
                break;
            }
        }
    }
    cout << ans << endl;
}