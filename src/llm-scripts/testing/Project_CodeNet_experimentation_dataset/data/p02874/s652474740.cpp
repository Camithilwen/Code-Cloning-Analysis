#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
 
int gi() {
	int x=0,o=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*o;
}
 
struct dat {
	int l,r;
	bool operator<(const dat &A) const {
		return r<A.r;
	}
} a[N];
 
int n,pre1[N],suf1[N],pre2[N],suf2[N],ans;
 
int len(int l,int r) {
	if(l>r) return 0;
	return r-l+1;
}
 
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) a[i].l=gi(),a[i].r=gi();
	sort(a+1,a+n+1);
	pre2[0]=1e9;
	for(int i=1;i<=n;i++) {
		pre1[i]=max(pre1[i-1],a[i].l);
		pre2[i]=min(pre2[i-1],a[i].r);
	}
	suf2[n+1]=1e9;
	for(int i=n;i;i--) {
		suf1[i]=max(suf1[i+1],a[i].l);
		suf2[i]=min(suf2[i+1],a[i].r);
	}
	for(int i=1;i<=n;i++) {
		int L=max(pre1[i-1],suf1[i+1]);
		int R=min(pre2[i-1],suf2[i+1]);
		ans=max(ans,a[i].r-a[i].l+1+len(L,R));
		if(i^n) ans=max(ans,len(pre1[i],pre2[i])+len(suf1[i+1],suf2[i+1]));
	}
	cout<<ans;
	return 0;
}
