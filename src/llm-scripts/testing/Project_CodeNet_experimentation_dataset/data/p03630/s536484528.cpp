#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

const ll MOD = (ll)1e9 + 7;
const ll MOD2 = 998244353;
const ll LLINF = (ll)1e18;
const ll INTINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max<T>(a,b);}
template <class T> void chmin(T& a, const T b){a=min<T>(a,b);}
void YN(bool flg) {cout << ((flg) ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << ((flg) ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << ((flg) ? "yes" : "no") << endl;}

long long Maximum_Rectangle(vector<long long>& ar){
	ar.push_back(0);
	stack<pair<long long,long long>> st;
	long long res = 0;
	for(long long r = 0; r < ar.size(); ++r){
		long long vr = ar[r];
		if(st.empty()){
			st.push({vr,r});
			continue;
		}

		long long vl = st.top().first, l = st.top().second;
		if(vl < vr) st.push({vr,r});
		if(vl < vr || vl == vr)	continue;
		
		while(vl > vr) {
			res = max(res,vl*(r - l));
			st.pop();

			if(st.size() && st.top().first > vr) vl = st.top().first, l = st.top().second;
			else break;
		}
		st.push({vr,l});
	}
	ar.pop_back();
	return res;
}

int main() {

	ll H,W; cin >> H >> W;
	string S1,S2;
	cin >> S1;
	V<V<ll>> flg(H,V<ll>(W,0)),cnt(H,V<ll>(W+1,0));	
	for(int i = 0; i < H - 1; ++i){
		cin >> S2;
		for(int j = 0; j < W - 1; ++j){
			int a = (S1[j] == '#');
			int b = (S1[j + 1] == '#');
			int c = (S2[j] == '#');
			int d = (S2[j + 1] == '#');
			int tmp = a+b+c+d;
			if(tmp == 1 || tmp == 3) flg[i][j] = 1;			
		}
		S1 = S2;
	}

	for(int j = 0; j < W; ++j){
		if(!flg[0][j]) cnt[0][j] = 1;
		for(int i = 1; i < H; ++i){
			if(flg[i][j]) continue;
			cnt[i][j] = cnt[i-1][j] + 1;
		}
	}
	ll ans = max(H,W);
	for(int i = 1; i < H; ++i){
		stack<pair<ll,ll>> st;
		st.push({cnt[i-1][0]+1,0});
		for(ll j = 1; j <= W; ++j){
			
			ll vj = cnt[i-1][j]+1;
			if(st.empty()){
				st.push({vj,j});
				continue;
			}

			ll vk = st.top().first, k = st.top().second;
	
			if(vk < vj) st.push({vj,j});
			if(vk < vj || vk == vj)	continue;

			while(1){
				chmax(ans,vk*(j - k + (j!=W?1:0)));
				st.pop();
				if(st.size() && st.top().first > vj) vk = st.top().first, k = st.top().second;
				else break;
			}
			st.push({vj,k});
		}
	}
	//for(int i = 0; i < H; ++i) print(i,cnt[i]);
	cout << ans << endl;

	return 0;
}
