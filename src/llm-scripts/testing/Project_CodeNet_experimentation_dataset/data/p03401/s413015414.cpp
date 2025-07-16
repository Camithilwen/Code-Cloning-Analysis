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
const int INT_LARGE = 1000000100;
 
 
//debug func
template<typename T>
void vecprint(vector<T> v) {
    for(auto x : v) {
        cerr << x << " ";
    }
    cerr << endl;
}
 
template<typename T>
void vecvecprint(vector<vector<T>> vv) {
    REP(i, SIZE(vv)) {
        REP(j, SIZE(vv[i])) {
            cerr << vv[i][j] << " ";
        }
        cerr << endl;
    }
}
 
template<typename T>
void pqprint(priority_queue<T> q) {
    while(!q.empty()) {
        cerr << q.top() << " ";
        q.pop();
    }
    cerr << endl;
}
 
template<typename T>
void qprint(queue<T> q) {
    while(!q.empty()) {
        cerr << q.front() << " ";
        q.pop();
    }
    cerr << endl;
}
 
template<typename T>
void vecqprint(vector<queue<T>> v) {
    for(int i = 0; i < v.size(); i++) {
        qprint(v[i]);
    }
}
 
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

int main(void) {
    int n;
    cin >> n;
    VI a(n+2, 0);
    REP(i, n) cin >> a[i+1];
    VI b(n+1);
    REP(i, n+1) b[i] = abs(a[i+1] - a[i]);
    int sum = 0;
    REP(i, n+1) sum += b[i];
    REP(i, n) {
        cout << sum - b[i] - b[i+1] + abs(a[i] - a[i+2]) << endl; 
    }
}