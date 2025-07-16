#include <bits/stdc++.h>
#define FOR(v, a, b) for(int v = (a); v < (b); ++v)
#define FORE(v, a, b) for(int v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(int v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define LLI long long int
#define fst first
#define snd second
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.71828182845904523536
#endif

#ifdef DEBUG
#include <misc/C++/Debug.cpp>
#else
#define dump(x)
#endif

#define pln(x) cout << (x) << endl
#define gcd __gcd

using namespace std;
template <class T> constexpr T lcm(T m, T n){return m/gcd(m,n)*n;}

template <typename T> using V = vector<T>;
template <typename T, typename U> using P = pair<T,U>;
template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}
template <typename T, typename U> istream& operator>>(istream &is, pair<T,U> &p){is >> p.first >> p.second; return is;}

template <typename T, typename U> T& chmin(T &a, const U &b){return a = (a<=b?a:b);}
template <typename T, typename U> T& chmax(T &a, const U &b){return a = (a>=b?a:b);}
template <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a, (U*)(a+N), v);}


template <typename T> T power(T n, LLI p, const T &e, const function<T(T,T)> &f){
  T ret = e;
  while(p>0){
    if(p&1) ret = f(ret, n);
    n = f(n, n);
    p /= 2;
  }
  return ret;
}



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  while(cin >> N){
    vector<double> x(N); cin >> x;

    int M; cin >> M;
    LLI K; cin >> K;

    vector<int> a(M); cin >> a;
    for(auto &i : a) --i;

    vector<int> b(N-1);
    REP(i,N-1) b[i] = i;

    for(auto i : a){
      swap(b[i-1], b[i]);
    }

    dump(b);

    auto f = [N](const vector<int> &a, const vector<int> &b){
	       vector<int> ret(N-1);
	       REP(i,N-1){
		 ret[i] = a[b[i]];
	       }
	       return ret;
	     };

    vector<int> e(N-1);
    REP(i,N-1) e[i] = i;
    
    auto c = power<vector<int>>(b, K, e, f);
    
    dump(c);

    vector<double> diff(N-1);
    REP(i,N-1) diff[i] = x[i+1] - x[i];

    vector<double> diff2(N-1);
    REP(i,N-1) diff2[i] = diff[c[i]];

    vector<double> ans(N);
    ans[0] = x[0];
    REP(i,N-1) ans[i+1] = ans[i] + diff2[i];
    
    for(auto i : ans) cout << setprecision(15) << i << endl;
  }
  
  return 0;
}
