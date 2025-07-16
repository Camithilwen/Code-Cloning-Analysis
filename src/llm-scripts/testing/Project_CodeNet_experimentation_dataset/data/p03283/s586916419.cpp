#include <bits/stdc++.h>
using namespace std;

int N,M,Q,m;
const int maxn=600000+5;
int siz;
int C[maxn],a[maxn],ret[maxn];
struct node{
	int l,r,id;
	bool operator<(const node& other)const{
		return other.r > r;
	}
}x[maxn],y[maxn];

void add(int x,int v){
	for(int i=x;i<=m;i+=i&-i) C[i]+=v;
}

int sum(int x){
	int ret=0;
	for(int i=x;i;i-=i&-i) ret+=C[i];
	return ret;
}

int main(){
	cin>>N>>M>>Q;
	for(int i=0;i<M;i++){
		cin>>x[i].l>>x[i].r;
		a[siz++]=x[i].l;
		a[siz++]=x[i].r;
	}
	for(int i=0;i<Q;i++){
		cin>>y[i].l>>y[i].r;
		y[i].id=i;
		a[siz++]=y[i].l;
		a[siz++]=y[i].r;
	}
	sort(a,a+siz);
	m=unique(a,a+siz)-a;
	for(int i=0;i<M;i++){
		x[i].l=lower_bound(a,a+m,x[i].l)-a+1;
		x[i].r=lower_bound(a,a+m,x[i].r)-a+1;
	}
	for(int i=0;i<Q;i++){
		y[i].l=lower_bound(a,a+m,y[i].l)-a+1;
		y[i].r=lower_bound(a,a+m,y[i].r)-a+1;
	}
	sort(x,x+M);
	sort(y,y+Q);
	int j=0;
	for(int i=0;i<Q;i++){
		while(j<M&&x[j].r<=y[i].r) add(x[j++].l,1);
		ret[y[i].id]=j-sum(y[i].l-1);
	}
	for(int i=0;i<Q;i++) cout<<ret[i]<<endl;
	return 0;
}