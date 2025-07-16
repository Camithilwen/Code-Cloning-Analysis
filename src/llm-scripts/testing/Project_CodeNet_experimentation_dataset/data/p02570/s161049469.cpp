#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <set>
#include <iomanip> 
#include <stack>
#define int long long
#define ld long double
#define dbg(x) cout <<#x<<":"<<x<<'\n';
#define dbg2(x,y) cout<<#x<<":"<<x<<' '<<#y<<":"<<y<<'\n';
#define endl '\n'
#define inf 1000000010
#define eps 1e-8l
using namespace std;

const int N=2e5+5;
std::vector<int> g[N],c(N),gd(N),p(N),r(N);
vector<bool> vis(N);
int power(int x,int y){int res = 1;while(y>0){if(y&1)res = (res*x);x = (x*x);y = y>>1;}return res;}

//int n,m;
int n,a,b,da,db,md,nd,m;

int const dpn=2e5+5;
int dp[dpn];

bool comp(pair<int,int> l,pair<int,int> r){
	if(l.first!=r.first)
		return (l.first<r.first);
	return l.second>r.second;
}

int find(int i){
	if(p[i]!=i)
		return p[i]=find(p[i]);
	return i;
}

void join(int x,int y){
	int px=find(x);
	int py=find(y);
	if(r[px]>r[py])
		p[py]=px;
	else if(r[px]<r[py])
		p[px]=py;
	else
		p[py]=px,r[px]++;
}

int32_t main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		//int n;
		//int n;
		int d,t,s;
		cin>>d>>t>>s;
		if((double)d/(double)s<=(double)t)
			cout<<"Yes\n";
		else
			cout<<"No\n";

	}
	return 0;
}
