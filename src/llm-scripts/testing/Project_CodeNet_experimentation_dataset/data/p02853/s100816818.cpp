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

int ans,x,y;

signed main(){
	read(x,y);
	if(x==1) ans+=3e5;
	if(x==2) ans+=2e5;
	if(x==3) ans+=1e5;
	if(y==1) ans+=3e5;
	if(y==2) ans+=2e5;
	if(y==3) ans+=1e5;
	if(x==1&&y==1) ans+=4e5;
	write(ans);
}