#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int N=1e5+5;
int n,m,p,a[N],b[N],ans=1e9;

signed main(){
	read(n,m,p);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++) read(b[i]);
	ans=*min_element(a+1,a+1+n)+*min_element(b+1,b+1+n);
	while(p--){
		int x,y,z;
		read(x,y,z);
		ans=min(ans,a[x]+b[y]-z);
	}
	write(ans);
}