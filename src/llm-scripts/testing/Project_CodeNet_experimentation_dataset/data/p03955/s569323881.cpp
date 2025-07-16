#include <bits/stdc++.h>
using namespace std;

#define dump(...) cout<<"# "<<#__VA_ARGS__<<'='<<(__VA_ARGS__)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

using uint=unsigned;
using ll=long long;
using ull=unsigned long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vd=vector<double>;
using vvd=vector<vd>;
using vs=vector<string>;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}

template<typename Tuple>
void print_tuple(ostream&,const Tuple&){}
template<typename Car,typename... Cdr,typename Tuple>
void print_tuple(ostream& os,const Tuple& t){
	print_tuple<Cdr...>(os,t);
	os<<(sizeof...(Cdr)?",":"")<<get<sizeof...(Cdr)>(t);
}
template<typename... Args>
ostream& operator<<(ostream& os,const tuple<Args...>& t){
	print_tuple<Args...>(os<<'(',t);
	return os<<')';
}

template<typename Ch,typename Tr,typename C>
basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){
	os<<'[';
	for(auto i=begin(c);i!=end(c);++i)
		os<<(i==begin(c)?"":" ")<<*i;
	return os<<']';
}

constexpr int INF=1e9;
constexpr int MOD=1e9+7;
constexpr double EPS=1e-9;

struct FenwickTree{
	vector<ll> data;
	FenwickTree(int n):data(n+1){}
	void Add(int i,int x){
		for(i++;i<data.size();i+=i&-i)
			data[i]+=x;
	}
	ll Sum(int i){
		ll res=0;
		for(;i;i-=i&-i)
			res+=data[i];
		return res;
	}
	ll Sum(int i,int j){
		return Sum(j)-Sum(i);
	}
};

ll InversionNumber(const vi& a)
{
	FenwickTree ft(a.size());
	ll res=0;
	rep(i,a.size()){
		res+=ft.Sum(a[i],a.size());
		ft.Add(a[i],1);
	}
	return res;
}

bool test(vector<tuple<int,int,int>> src,vector<tuple<int,int,int>> dst)
{
	int n=src.size();
	rep(i,n){
		int x,y,z;
		tie(x,y,z)=src[i];
		src[i]=x<z?mt(x,y,z):mt(z,y,x);
		tie(x,y,z)=dst[i];
		dst[i]=x<z?mt(x,y,z):mt(z,y,x);
	}
	sort(all(src)); sort(all(dst));
	return src==dst;
}

tuple<bool,bool> calc(vector<tuple<int,int,int>> src,vector<tuple<int,int,int>> dst)
{
	int m=src.size(),flip=0;
	rep(i,m){
		int x,y,z;
		tie(x,y,z)=src[i];
		src[i]=x<z?mt(x,y,z):(flip++,mt(z,y,x));
		tie(x,y,z)=dst[i];
		dst[i]=x<z?mt(x,y,z):(flip++,mt(z,y,x));
	}
	map<tuple<int,int,int>,int> f;
	rep(i,m) f[dst[i]]=i;
	vi a(m);
	rep(i,m) a[i]=f[src[i]];
	return mt(InversionNumber(a)&1,flip&1);
}

bool solve(int n,vvi grid)
{
	array<bool,2> inv,flip;
	rep(i,2){
		vector<tuple<int,int,int>> src,dst;
		rep(j,n) if(j%2==i){
			if(j/2%2==0){
				src.emplace_back(mt(3*j+1,3*j+2,3*j+3));
				dst.emplace_back(mt(grid[0][j],grid[1][j],grid[2][j]));
			}
			else{
				src.emplace_back(mt(3*j+3,3*j+2,3*j+1));
				dst.emplace_back(mt(grid[2][j],grid[1][j],grid[0][j]));
			}
		}
		if(!test(src,dst)) return false;
		tie(inv[i],flip[i])=calc(src,dst);
	}
	return inv[0]==flip[1]&&inv[1]==flip[0];
}

int main()
{
	for(int n;cin>>n&&n;){
		vvi grid(3,vi(n));
		rep(i,3) rep(j,n) cin>>grid[i][j];
		cout<<(solve(n,grid)?"Yes":"No")<<endl;
	}
}
