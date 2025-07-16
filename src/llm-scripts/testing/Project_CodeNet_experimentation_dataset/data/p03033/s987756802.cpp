#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct ppp{ll l,r,v,tag;}tree[4000005];

struct ttt{ll s,t,x;}b[200005];

bool cmp(ttt l,ttt r){return l.x>r.x;}

ll p[200005];

set<ll> k;

vector<ll> a;

void push(ll i){

    tree[i*2].tag=tree[i].tag;

	tree[i*2+1].tag=tree[i].tag;

	tree[i*2].v=(tree[i*2].r-tree[i*2].l+1)*tree[i*2].tag;

	tree[i*2+1].v=(tree[i*2+1].r-tree[i*2+1].l+1)*tree[i*2+1].tag;

	tree[i].tag=0;

}

void buildtree(ll i,ll l,ll r){

	tree[i].l=l;tree[i].r=r;

	if(l==r){

		tree[i].v=-1;

		return;

	}

	buildtree(i*2,l,(l+r)/2);

	buildtree(i*2+1,(r+l)/2+1,r);

	tree[i].v=tree[i*2].v+tree[i*2+1].v;

}

void update(ll i,ll l,ll r,ll k){

    if(tree[i].l>=l&&tree[i].r<=r){

        tree[i].tag=k;

		tree[i].v=(tree[i].r-tree[i].l+1)*k;

        return ;

    }

    if(tree[i].tag) push(i);

    ll m=(tree[i].l+tree[i].r)/2;

    if(l<=m) update(i*2,l,r,k);

    if(r>m) update(i*2+1,l,r,k);

    tree[i].v=tree[i*2].v+tree[i*2+1].v;

}

ll query(ll i,ll l,ll r){

    if(tree[i].l>=l&&tree[i].r<=r){

        return tree[i].v;

    }

    if(tree[i].tag) push(i);

    ll m=(tree[i].r+tree[i].l)/2,ans=0;

    if(l<=m) ans+=query(i*2,l,r);

    if(r>m) ans+=query(i*2+1,l,r);

    return ans;

}

int main(){

	ll n,q;

	cin>>n>>q;

	a.push_back(-1e9);

	for(ll i=1;i<=n;i++){

		cin>>b[i].s>>b[i].t>>b[i].x;

		k.insert(max(b[i].s-b[i].x,(ll)0));

		k.insert(max(b[i].t-1-b[i].x,(ll)0));

	}

	for(ll i=1;i<=q;i++){

		cin>>p[i];k.insert(p[i]);

	}

	for(auto x:k){

		a.push_back(x);

	}

	buildtree(1,1,a.size());

	sort(b+1,b+1+n,cmp);

	for(ll i=1;i<=n;i++){

		ll l=lower_bound(a.begin(),a.end(),max((ll)0,b[i].s-b[i].x))-a.begin();

		ll r=lower_bound(a.begin(),a.end(),max((ll)0,b[i].t-b[i].x-1))-a.begin();

		update(1,l,r,b[i].x);

	}

	for(ll i=1;i<=q;i++){

		ll l=lower_bound(a.begin(),a.end(),p[i])-a.begin();

		cout<<query(1,l,l)<<endl;

	}

}