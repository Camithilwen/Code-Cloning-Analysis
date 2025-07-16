#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=998244353;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

#include<atcoder/fenwicktree>
using namespace atcoder;

int n,q;

int main(){
	cin>>n>>q;
	fenwick_tree<ll> fw(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		fw.add(i,x);
	}
	for(int i=0;i<q;i++){
		int t;
		cin>>t;
		if(t==0){
			int p,x;
			cin>>p>>x;
			fw.add(p,x);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<fw.sum(l,r)<<endl;
		}
	}
}