#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 
vi vx={-1,0,1,0};
vi vy={0,1,0,-1};
using pi = pair<int,int>;

signed main(){
	int a,b; cin>>a>>b;
	vvi v(a,vi(b));
	queue<pi> q;
	rep(i,0,a){
		rep(j,0,b){
			char c; cin>>c;
			if(c=='#'){
				v[i][j]=1;
				q.push(make_pair(i,j));
			}
			else v[i][j]=0;
		}
	}
	while(!q.empty()){
		pi p=q.front(); q.pop();
		int k,l; tie(k,l)=p;
		bool ok=false;
		rep(i,0,4){
			k+=vx[i]; l+=vy[i];
			if(k>=0 && k<a){
				if(l>=0 && l<b){
					if(v[k][l]==1)ok=true;
				}
			}
			k-=vx[i]; l-=vy[i];
		}
		if(!ok){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	
	
	return 0;
}