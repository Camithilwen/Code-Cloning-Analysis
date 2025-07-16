#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<iomanip>

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

#define debug(x) cout<<(#x)<<"="<<(x)<<", ";
#define debug1(x) debug(x) cout<<'\n';
#define debug2(x1, x2) debug(x1) debug(x2) cout<<'\n';
#define debug3(x1, x2, x3) debug(x1) debug(x2) debug(x3) cout<<'\n';
#define debug4(x1, x2, x3, x4) debug(x1) debug(x2) debug(x3) debug(x4) cout<<'\n';
#define debug5(x1, x2, x3, x4, x5) debug(x1) debug(x2) debug(x3) debug(x4) debug(x5) cout<<'\n';

#define fcout cout<<fixed<<setprecision(15)
#define repp(i,j,k) for(int i=j; i<k; ++i)
#define rep(i,j) repp(i,0,j)
#define rrep(i,j,k) for(int i=j; i>=k; --i)
#define all(x) (x).begin(), (x).end()
#define sort(x) sort(x.begin(), x.end())
#define lb(x,val) lower_bound(x.begin(), x.end(), val)
#define ub(x,val) upper_bound(x.begin(), x.end(), val)
#define pb(x) emplace_back(x);

typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef tuple<int, int, lli> tiil;

//const lli M=998244353ll;
const lli M=1000000007ll;
const double D=1.0;

int main(){
	fast_io
	int a,b,c; cin>>a>>b>>c;
	cout<<max(a*b, max(a+b,a-b));
	return 0;
}