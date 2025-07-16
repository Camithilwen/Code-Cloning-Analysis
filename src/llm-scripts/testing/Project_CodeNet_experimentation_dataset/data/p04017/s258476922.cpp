#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 100010
#define int ll

int N,L,Q;
int A[maxn];
vi adj[maxn];

int twok[maxn][100],depth[maxn];

void twokdecomp(int x,int p){
	twok[x][0] = p;
	for (int i=1;i<=18;i++){ //i <= logmaxn
		if (twok[x][i-1] == -1) break;
		twok[x][i] = twok[twok[x][i-1]][i-1];
	}
	for (auto i: adj[x]){
		if (i != p){
			depth[i] = depth[x] + 1;
			twokdecomp(i,x);
		}
	}
}

int kth_parent(int x,int k){
	
	for (int i=0;i<=18;i++){
		if (k&(1<<i)){
			x = twok[x][i];
		}
		if (x==-1) break;
	}
	return x;

}



int32_t main(){
	fast;
	
	cin>>N;
	FOR(i,1,N) cin>>A[i];
	
	cin>>L>>Q;
	
	FOR(i,1,N-1){
		
		int idx = upper_bound(A+1,A+N+1,A[i] + L) - A;
		
		idx--;
		
		if (i == idx) continue;
		adj[i].pb(idx);
		adj[idx].pb(i);
		
	}
	
	mem(twok,-1);
	
	twokdecomp(N,-1);
		
	FOR(i,0,Q-1){
		int a,b; cin>>a>>b;
		if (a > b) swap(a,b);
		
		int l=0,r=depth[a]+10;
		
		while (l + 1 < r){
			
			int mid = (l+r)/2;
			//cout<<mid<<' '<<kth_parent(a,mid)<<'\n';

			if (kth_parent(a,mid) == -1) r = mid;
			else if (kth_parent(a,mid) > b) r = mid;
			else l = mid;
		}
		
		while (kth_parent(a,l) < b){
			l++;
		}
		cout<<l<<'\n';
		
	}
			
	
	
}
