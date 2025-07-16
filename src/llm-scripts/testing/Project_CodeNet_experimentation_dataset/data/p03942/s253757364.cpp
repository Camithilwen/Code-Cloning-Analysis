#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
vector<int> c2is[26];
vector<int> ls,rs;
int N;
string S,T;
int solve(){
	cin>>N;
	cin>>S>>T;
	if(S==T){
		return 0;
	}
	rep(i,N){
		c2is[S[i]-'a'].pb(i);
	}
	int now=N-1;
	int r=N-1;
	for(int i=N-2;i>=-1;i--){
		if(i==-1 || T[i]!=T[i+1]){
			int l=i+1;
			int c = T[i+1] -'a';
			int id = upper_bound(all(c2is[c]),min(now,l))-c2is[c].begin()-1;
			if(id==-1){
				return -1;
			}
			int v = c2is[c][id];
			// show(l);
			// show(r);
			// show(v);
			// puts("");
			ls.pb(v);
			rs.pb(r);

			r=i;
			now=v-1;
		}
	}
	reverse(all(ls));
	reverse(all(rs));
	int K=ls.size();
	// show(ls);
	// show(rs);
	rep(i,K) ls[i]-=i;
	int ans=0;
	rep(i,K){
		int r = rs[i];
		int id = lower_bound(all(ls),r-i)-ls.begin()-i;
//		show(id);
		chmax(ans,id);
	}
	return ans;
}
int main(){
	cout<<solve()<<endl;
}