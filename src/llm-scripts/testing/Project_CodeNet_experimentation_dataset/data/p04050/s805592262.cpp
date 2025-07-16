#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
int n,m,a[105],tot;
vector<int> ans;
signed main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){a[i]=read(); if(a[i]&1)tot++;}
	if(m==1){
		if(a[1]==1)cout<<1<<endl<<1<<endl<<1<<endl; else
		if(a[1]&1)cout<<a[1]<<endl<<2<<endl<<a[1]/2<<" "<<a[1]/2+1<<endl;
		else if(a[1]==2)cout<<a[1]<<endl<<2<<endl<<1<<" "<<1<<endl;
		else cout<<a[1]<<endl<<2<<endl<<a[1]/2-1<<" "<<a[1]/2+1<<endl;
		return 0;
	}
	if(tot>2){
		puts("Impossible"); return 0;
	}
	for(int i=2;i<m;i++)if(a[i]&1){
		if(a[1]&1)swap(a[i],a[m]); else swap(a[1],a[i]);
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<" "; puts("");
	a[1]++; a[m]--;
	for(int i=1;i<=m;i++)if(a[i])ans.push_back(a[i]);
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<" ";
}