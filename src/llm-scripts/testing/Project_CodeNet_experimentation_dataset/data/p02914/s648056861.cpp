#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using ll=long long;
using R=long double;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

template<typename T> vector<T> make_vector(size_t sz){
	return vector<T>(sz);
}

template<typename T,typename... Ts> 
auto make_vector(size_t sz, Ts... ts){
	return vector<decltype(make_vector<T>(ts...))>(sz, make_vector<T>(ts...));
}

template<typename T,typename U,typename... V> 
typename enable_if<is_same<T, U>::value!=0>::type 
fill_value(U &u, const V... v){
	u=U(v...);
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_value(U &u, const V... v){
	for(auto &e:u){
		fill_value<T>(e,v...);
	}
}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

const pid_t pid = getpid();
// Problem Specific Parameter:

ll solve(const vector<ll> &ary){
	vector<ll> a = ary;
	const int n = ary.size();
	const int m = 60;
	
	int c = 0;
	rep(i, n - 1){
		int pivot = i;
		for(; c < m; ++c){
			int cmax = 0;
			rep(k, i, n) {
				const int bit = (a[k] >> (m - 1 - c)) & 1;
				if(chmax(cmax, bit)) pivot = k;
			}
			if(cmax > 0) break;
		}

		if(c == m) break;
		if(pivot != i) swap(a[i], a[pivot]);
		rep(k, i + 1, n){
			const int flag = (a[k] >> (m - 1 - c)) & 1;
			if(flag) a[k] ^= a[i];
		}
		c++;
	}

	ll ret = 0LL;
	rep(i, n) if((ret^a[i]) > ret) ret ^= a[i];
	return ret;
}


int main(void){
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll xorsum = 0LL;
	rep(i, n) xorsum ^= a[i];

	const int m = 60;
	rrep(j, m){
		const int bit = (xorsum >> j) & 1;
		if(bit == 0) continue;
		rep(i, n) if(a[i] >> j & 1) a[i] ^= (1LL << j);
	}

	const ll amax = solve(a);
	const ll bmax = xorsum ^ amax;

	cout << amax + bmax << endl;
	return 0;
}