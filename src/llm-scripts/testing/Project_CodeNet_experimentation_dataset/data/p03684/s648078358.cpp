#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vd=vector<double>;
using vvd=vector<vd>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii=pair<int,int>;
using vs=vector<string>;
#define rep(i,n) range(i,0,n)
#define range(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define LINF    	((ll)1ll<<60)
#define INF     	((int)1<<30)
#define EPS     	(1e-9)
#define MOD     	(1000000007)
#define fcout(a)	cout<<setprecision(a)<<fixed
#define fs 			first
#define sc			second
#define PI			3.141592653589793
template<class S,class T>ostream& operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}
/*
 * UnionFind。O(ｱｯｶｰﾏﾝ)
 */
struct UnionFind{
	vi p;
	UnionFind(int s):p(s,-1){}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a!=b){
			if(p[b]<p[a])swap(a,b);
			p[a]+=p[b];p[b]=a;
		}
	}
	bool same(int a,int b){return root(a)==root(b);}
	int root(int a){return p[a]<0?a:p[a]=root(p[a]);}
};

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
   	int n;
   	cin>>n;
   	using D=tuple<int,int,int>;
   	vector<D> data;
   	
   	rep(i,n){
   	    int x,y;
   	    cin>>x>>y;
   	    data.emplace_back(i,x,y);
   	}
   	vector<D> edge;
   	sort(all(data),[](D a,D b){return get<1>(a)<get<1>(b);});
   	rep(i,n-1){
   	    int a0,a1,a2,b0,b1,b2;
   	    tie(a0,a1,a2)=data[i];
   	    tie(b0,b1,b2)=data[i+1];
   	    edge.emplace_back(b1-a1,a0,b0);
   	}
   	sort(all(data),[](D a,D b){return get<2>(a)<get<2>(b);});
   	rep(i,n-1){
   	    int a0,a1,a2,b0,b1,b2;
   	    tie(a0,a1,a2)=data[i];
   	    tie(b0,b1,b2)=data[i+1];
   	    edge.emplace_back(b2-a2,a0,b0);
   	}
   	int ans=0;
   	UnionFind uf(n);
   	sort(all(edge),[](D a,D b){return get<0>(a)<get<0>(b);});
   	for(auto&e:edge){
   	    int c,a,b;
   	    tie(c,a,b)=e;
   	    if(uf.same(a,b))continue;
   	    uf.unite(a,b);
   	    ans+=c;
   	}
   	cout<<ans<<endl;
}
