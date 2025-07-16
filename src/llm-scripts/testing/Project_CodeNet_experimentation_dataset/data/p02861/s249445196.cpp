# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define f first 
# define s second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

# define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
# define debug cerr<<"ERROR"<<endl
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;

const int dx[]={1,0,-1,0,-1,-1,1,1};
const int dy[]={0,1,0,-1,-1,1,-1,1}; 
const int inf=1e9,mod=1e9+7,N=2e5+5;

int f(int x){
	return x*x;
}

void solve(){
	int n;
	cin>>n;
	vector<int>x(n),y(n),v;
	rep(i,n)cin>>x[i]>>y[i];
	forn(i,n)v.pb(i);
	int cnt=0;
	double ans=0;
	do{	
		cnt++;
		rep(i,n-1){
			ans+=sqrt(f(x[v[i]-1]-x[v[i+1]-1])+f(y[v[i]-1]-y[v[i+1]-1]));
		}
	}
	while(next_permutation(all(v)));
	double res=ans/cnt;
	printf("%.12f",res);
}

int main(){
 	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)solve();
}