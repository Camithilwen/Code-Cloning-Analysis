// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<random>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) {rep(_,v.size())cout<<" "<<v[_];cout<<endl;}
#define show2d(v) {rep(__,v.size())show1d(v[__]);}
using namespace std;
//kaewasuretyuui
typedef long long ll;
#define int ll
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
#define mt make_tuple
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
typedef vector<vt>vvt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
#define yes cout<<"Yes\n"
#define no cout<<"No\n"

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m,q;
	cin>>n>>m>>q;
	int out=0,mi=inf;
	vi a(n),b(m);
	rep(i,n)cin>>a[i],cmin(mi,a[i]);
	out+=mi;
	mi=inf;
	rep(i,m)cin>>b[i],cmin(mi,b[i]);
	out+=mi;

	rep(i,q){
		int x,y,z;
		cin>>x>>y>>z;
		cmin(out,a[x-1]+b[y-1]-z);
	}
	cout<<out<<endl;

}
