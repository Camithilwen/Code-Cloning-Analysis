#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	int h, w; cin >> h >> w;
	vector<string> in(h); rep(i, h) cin >> in[i];
	
	vector<vi> d1(h), d2(h - 1), dp(h - 1, vi(w - 1));
	rep(i, h) rep(j, w - 1) d1[i].pb(in[i][j] != in[i][j + 1]);
	rep(i, h - 1) rep(j, w - 1) d2[i].pb(d1[i][j] != d1[i + 1][j]);
	
	//rep(i, h - 1) dbg(d2[i]);
	
	ll ans = max(h, w);
	rep(i, h - 1){
		vi ls(w - 1), rs(w - 1), q;
		rep(j, w - 1){
			dp[i][j] = d2[i][j] ? 0 : (i ? dp[i - 1][j] : 0) + 1;
			ls[j] = j;
			while(q.size() && dp[i][q.back()] >= dp[i][j]){
				ls[j] = ls[q.back()];
				q.pop_back();
			}
			q.pb(j);
		}
		q.clear();
		for(int j = w - 2; j >= 0; j--){
			rs[j] = j;
			while(q.size() && dp[i][q.back()] >= dp[i][j]){
				rs[j] = rs[q.back()];
				q.pop_back();
			}
			q.pb(j);
			ans = max(ans, (rs[j] - ls[j] + 2ll) * (dp[i][j] + 1ll));
		}
		//dbg(i, ls);
	}
	cout << ans << endl;
	return 0;
}