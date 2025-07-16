#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 5e5+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;

int N,Q;
int c[maxn];
int last[maxn],nx[maxn];
int root[maxn];
struct Tree
{
	struct node{
		int l,r;
		int sum;
	}tr[maxn*4 + maxn*19];
	int tail = 0;
	int build(int l,int r){
		int cur = ++tail;
		if(l == r) return cur;
		int mid = (l+r)>>1;
		tr[cur].l = build(l,mid);
		tr[cur].r = build(mid+1,r);
		return cur;
	}
	int insert(int pre,int l,int r,int x){
		int cur = ++tail;
		tr[cur] = tr[pre];
		if(l == r){
			tr[cur].sum++;
			return cur;
		}else{
			int mid = (l+r)>>1;
			if(x <= mid) tr[cur].l = insert(tr[pre].l,l,mid,x);
			else tr[cur].r = insert(tr[pre].r,mid+1,r,x);
			tr[cur].sum = tr[tr[cur].l].sum + tr[tr[cur].r].sum;
			return cur;
		}
	}
	int query(int cur,int pre,int l,int r,int R){
		if(l == r){
			if(R>l) return tr[cur].sum - tr[pre].sum;
			else return 0;
		}else{
			int mid = (l+r)>>1;
			if(R<=mid) return query(tr[cur].l,tr[pre].l,l,mid,R) + tr[tr[cur].r].sum - tr[tr[pre].r].sum;
			else return query(tr[cur].r,tr[pre].r,mid+1,r,R);
		}
	}
}tree;
void init(){
	for(int i = 1;i<=N;i++){
		if(last[c[i]]){
			nx[last[c[i]]] = i;
		}
		last[c[i]] = i;
	}
	for(int i = 1;i<=N;i++)  if(nx[i] == 0) nx[i] = N+1;
}
void solve(){
	root[0] = tree.build(1,N+1);
	for(int i = 1;i<=N;i++){
		root[i] = tree.insert(root[i-1],1,N+1,nx[i]);
	}
	while(Q--){
		int l,r;cin>>l>>r;
		int ans = tree.query(root[r],root[l-1],1,N+1,r);
		cout<<ans<<'\n';
	}
}
int main(){
	// debug;
	ios;

	cin>>N>>Q;
	for(int i =1;i<=N;i++) cin>>c[i];
	init();
	solve();
	
	return 0;
}
