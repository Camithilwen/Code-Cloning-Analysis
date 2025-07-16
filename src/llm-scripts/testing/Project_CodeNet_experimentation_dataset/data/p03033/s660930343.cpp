#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
 
// debug templates 
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";
 

void solve(){
	int n,q; cin >> n >> q;
	// [S,T),X
	set<pair<int,pair<int,int>>> st;
	FOR(n){
		int s,t,x; cin >> s >> t >> x;
		// [s-x,t-x) are the starting positions of people that get stuck in this blockade
		st.insert({s-x,{1,x}});
		st.insert({t-x,{-1,x}});
	}
	FOR(q){
		int d; cin >> d;
		st.insert({d,{2,i}});
	}
	int ans[q];
	memset(ans,0,sizeof(ans));
	set<int> blocked;
	// if type 1 then add x to blocked
	// if type -1 remove from blocked
	// if type 2 then check if it is being blocked currently
	for(pair<int,pair<int,int>> xx : st){
		if(xx.second.first == 1){
			blocked.insert(xx.second.second);
		} else if(xx.second.first == -1){
			blocked.erase(xx.second.second);
		} else{
			if(blocked.empty()){
				ans[xx.second.second] = -1;
			} else{
				ans[xx.second.second] = *(blocked.begin());
			}
		}
	}
	for(int yy : ans) cout << yy << '\n';
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	return 0;
}
 
