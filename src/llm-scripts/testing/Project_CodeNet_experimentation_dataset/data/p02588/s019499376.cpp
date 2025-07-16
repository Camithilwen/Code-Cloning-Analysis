#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os << "[ "; 
  for(auto v:V)os << v << " "; return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){ os << "{ "; 
  for(auto s:S) os<<s<<" ";  return os<<"}"; 
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
  return os<<"("<<P.first<<","<< P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
  os<<"{ ";for(auto m:M)os<<"("<<m.first<<":"<<m.second<<")";
  return os<<"}";
}
#define cerr cout
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
//For multiset use less_equal operator but it does support erase operations for multiset
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define all(v) (v).begin(),(v).end()
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpii;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mp make_pair


const int mod = 1e9+7;

inline int add(int a,int b){a+=b;if(a>=mod)a-=mod; return a;} 
inline int sub(int a,int b){a-=b;if(a<0) a += mod; return a;}
inline int mul(int a, int b){ return a*1ll*b%mod;}
inline int power(int x, ll y){
  int res = 1;
  while(y){
    if(y&1) res = mul(res , x);
    x = mul(x,x);
    y >>= 1;
  }
  return res;
}

pii sovle(ll n){
  int a = 0 , b = 0;
  while(n%2 == 0){
    ++a;
    n /= 2;
  }
  while(n%5 == 0){
    ++b;
    n /= 5;
  }
  return mp(a,b);
}
const int N = 18;
ll pwr[N];

int main(){
  fio; cout<<fixed<<setprecision(25);	
  pwr[0] = 1;
  for(int i = 1;i < N ; ++i) pwr[i] = pwr[i-1]*10;
  int n; cin >> n; 
  map<pii,ll> m;
  string s;
  for(int i =1 ;i <= n ; ++i){
    cin >> s;
    int id = -1;
    int j = 0;
    for(auto it :s){
      if(it == '.'){
        id = j;
        break;
      }
      ++j;
    }
    ll a = 1 , b = 1;
    if(id == -1){
      a = stoll(s);
    }
    else{
      int len = s.size()-j-1;      
      b = pwr[len];
      s.erase(s.begin()+id);
      a = stoll(s); 
    }
    ll gd = __gcd(a,b);
    a /= gd;
    b /= gd;
    pll p1 = sovle(a);
    pll p2 = sovle(b);
    p1.F -= p2.F;
    p1.S -= p2.S;
    m[p1]++;
  }
  ll ans = 0;
  
  for(auto &it : m){
    for(auto &it2 : m){
      if(it.F.F+it2.F.F >= 0 && it.F.S+it2.F.S >= 0){
        ans += it.S*it2.S; 
        if(it == it2)
          ans -= it.S;
      }
    }
  }
  cout << ans/2 << endl;


  return 0;
}

