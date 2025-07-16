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

int getsum(const vvi& sums,int t,int b,int l,int r)
{
	if(l>=r || t>=b) return 0;
	return sums[b][r]-sums[t][r]-sums[b][l]+sums[t][l];
}

void chmax(int& a,int b)
{
	a=max(a,b);
}

int main()
{
	for(int h,w;cin>>h>>w && h|w;){
		vs grid(h);
		rep(i,h) cin>>grid[i];

		int ci=-1,cj=-1;
		rep(i,h) rep(j,w) if(grid[i][j]=='E') ci=i,cj=j;

		vvi sums(h+1,vi(w+1));
		rep(i,h) rep(j,w)
			sums[i+1][j+1]=(grid[i][j]=='o')+sums[i+1][j]+sums[i][j+1]-sums[i][j];

		int T=h-1-ci,B=ci,L=w-1-cj,R=cj;

		int dp[T+1][B+1][L+1][R+1]={};
		rep(t,T+1) rep(b,B+1) rep(l,L+1) rep(r,R+1){
			if(t!=T && ci+t+1<h-b)
				chmax(dp[t+1][b][l][r],dp[t][b][l][r]+getsum(sums,ci+(t+1),ci+(t+1)+1,max(cj-r,l),min(cj+l+1,w-r)));
			if(b!=B && t<=ci-(b+1))
				chmax(dp[t][b+1][l][r],dp[t][b][l][r]+getsum(sums,ci-(b+1),ci-(b+1)+1,max(cj-r,l),min(cj+l+1,w-r)));
			if(l!=L && cj+l+1<w-r)
				chmax(dp[t][b][l+1][r],dp[t][b][l][r]+getsum(sums,max(ci-b,t),min(ci+t+1,h-b),cj+(l+1),cj+(l+1)+1));
			if(r!=R && l<=cj-(r+1))
				chmax(dp[t][b][l][r+1],dp[t][b][l][r]+getsum(sums,max(ci-b,t),min(ci+t+1,h-b),cj-(r+1),cj-(r+1)+1));
		}

		int res=0;
		rep(t,T+1) rep(b,B+1) rep(l,L+1) rep(r,R+1) chmax(res,dp[t][b][l][r]);
		cout<<res<<endl;
	}
}
