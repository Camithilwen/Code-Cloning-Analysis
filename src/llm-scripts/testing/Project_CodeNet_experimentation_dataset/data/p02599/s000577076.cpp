#include <bits/stdc++.h>
using namespace std;
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define chmax(a,b) a=max(a,b)
int n,Q,bl;
int c[500005];
int ans=0,cnt[500005];
struct query{
	int l,r,id;
}q[500005];
int qans[500005];
bool cmp(query a,query b){
	return (a.r/bl)==(b.r/bl)?a.l<b.l:a.r<b.r;
}
void add(int x){
	if(!cnt[c[x]]){
		ans++;
	}
	cnt[c[x]]++;
}
void del(int x){
	cnt[c[x]]--;
	if(!cnt[c[x]]){
		ans--;
	}
}
int main(){
	cin>>n>>Q;
	bl=n/sqrt(Q*2/3);
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	for(int i=1;i<=Q;++i){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+1+Q,cmp);
	int l=0,r=0;
	for(int i=1;i<=Q;++i){
		int ql=q[i].l,qr=q[i].r;
//		cout<<ql<<' '<<qr<<'\n';
		while(l<ql){
			del(l);
			l++;
		}
		while(l>ql){
			l--;
			add(l);
		}
		while(r>qr){
			del(r);
			r--;
		}
		while(r<qr){
			r++;
			add(r);
		}
		qans[q[i].id]=ans;
	}
	for(int i=1;i<=Q;++i){
		cout<<qans[i]<<'\n';
	}
	return 0;
}
