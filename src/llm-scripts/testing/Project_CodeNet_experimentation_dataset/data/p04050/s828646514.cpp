//fold
#ifndef KHALIL
#include <bits/stdc++.h>
#else
#include "header.h"
#endif
#define endl '\n'
#define mp make_pair
#define tostr(x) static_cast<ostringstream&>((ostringstream()<<dec<<x)).str()
#define rep(i,begin,end) for(auto i = begin;i < end;i++)
#define repr(i,begin,end) for(auto i = begin-1;i >= end;i--)
#define pb push_back
#define sz(a) ((int)(a).size())
#define fi first
#define se second
#define abs(a) ((a) < (0) ? (-1)*(a) : (a))
#define SQ(a) ((a)*(a))
#define eqd(a,b) (abs(a-b)<1e-9)
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
template <typename t> t in(t q){cin >> q;return q;}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v){os << "[";for (int i = 0; i < sz(v); ++i) { os << v[i]; if (i != sz(v) - 1) os << ",";}os << "]";return os;}
template <typename T, typename S>ostream& operator<<(ostream& os, const map<T, S>& v){for (auto it : v)os << "(" << it.first << ":" << it.second << ")";return os;}
template <typename T, typename S>ostream& operator<<(ostream& os, const pair<T, S>& v){os << "(" << v.first << "," << v.second << ")";return os;}
const long double PI = acosl(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int l,int r){return uniform_int_distribution<int>(l, r)(rng);}
inline ll rand(ll l,ll r){return uniform_int_distribution<ll>(l, r)(rng64);}
//endfold
#define  N  (200'005)
#define MOD (1000000000ll + 7ll)
#define OO (1050000000)
#define OOL (1100000000000000000)

//global
int a[N];

int main(){
	//fold
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << setprecision(10);
	//endfold
	int n,m;
	cin >> n >> m;
	int eew = 0;
	rep(i,0,m){
		cin >> a[i];
		if(a[i]&1){
			eew++;
		}
	}
	if(eew == 0){
		vector<int> v;
		vector<int> w;
		v.push_back(a[0]-2);
		v.push_back(1);
		rep(i,1,m){
			v.push_back(a[i]);
		}
		v.push_back(1);
		rep(i,0,sz(v)){
			if(v[i] != 0) w.push_back(v[i]);
		}
		rep(i,0,m){
			cout << a[i] << " ";
		}cout << endl;
		cout << sz(w) << endl;
		rep(i,0,sz(w)){
			cout << w[i] << " ";
		}
		return 0;
	}
	if(eew == 1){
		sort(a,a+m,[](int w,int e){
			return (w&1) > (e&1);
		});
		vector<int> v;
		vector<int> w;
		v.push_back(a[0]-1);
		rep(i,1,m){
			v.push_back(a[i]);
		}
		v.push_back(1);
		rep(i,0,sz(v)){
			if(v[i] != 0) w.push_back(v[i]);
		}
		rep(i,0,m){
			cout << a[i] << " ";
		}cout << endl;
		cout << sz(w) << endl;
		rep(i,0,sz(w)){
			cout << w[i] << " ";
		}
		return 0;
	}
	if(eew == 2){
		vector<int> q;
		rep(i,0,m){
			if(a[i]&1) q.push_back(i);
		}
		vector<int> res = {a[q[0]]};
		vector<int> v;
		vector<int> w;
		rep(i,0,m){
			if(i == q[0] || i == q[1]) continue;
			res.push_back(a[i]);
		}
		res.push_back(a[q[1]]);
		v.push_back(a[q[0]]-1);
		rep(i,1,m-1){
			v.push_back(res[i]);
		}
		v.push_back(a[q[1]]+1);
		rep(i,0,sz(v)){
			if(v[i] != 0) w.push_back(v[i]);
		}
		rep(i,0,m){
			cout << res[i] << " ";
		}cout << endl;
		cout << sz(w) << endl;
		rep(i,0,sz(w)){
			cout << w[i] << " ";
		}
		return 0;
	}
	cout << "Impossible";
	return 0;
}