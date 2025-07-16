#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<vi> vii;
typedef map<int, int> mp;
typedef multiset<int> mset;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef vector<int64> vi64;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define form(i,j,k,l) for(int i=j;i<int(k);i+=l)
#define rform(i,j,k,l) for(int i=int(j);i>int(l);i-=l)
#define rep(i, j) for(int i=0;i<int(j);i++)
#define rrep(i, j) for(int i=int(j);i>=0;i--)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forc(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define INF (int)1e9
#define INF64 (int64)1e18
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define F first
#define S  second
const double pie = acos(-1.0);
template <typename T>
T Max(T x, T y)
{
  return (x > y) ? x : y;
}
template <typename T>
T Min(T x, T y)
{
  return (x > y) ? y : x;
}
int gcd(int n1, int n2)
{
  if (n2 != 0) return gcd(n2, n1 % n2);
  else return n1;
}
#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
clock_t time_p = clock();
void rtime() { time_p = clock() - time_p; cerr << "Time Taken : " << (float)1000 * (time_p) / CLOCKS_PER_SEC << "\n";}
int64 binpow(int64 a, int64 b, int64 m) {
  a %= m;
  int64 res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int main()
{ fast;
  int n;
  long long int a, b;
  cin >> n >> a >> b;
  long long int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  long long int ans = 0;
  form(i, 1, n, 1)
  {

    ans = ans + Min((arr[i] - arr[i - 1]) * a, b);
  }
  cout << ans;

}


