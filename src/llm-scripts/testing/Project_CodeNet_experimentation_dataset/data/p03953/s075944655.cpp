#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+1;
double s[N];
int n,m;ll k;
int a[N],p[N],u[N],tmp[N];
int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	m=read();scanf("%lld",&k);
	for(int i=1;i<=n;i++) p[i]=i,u[i]=i;
	for(int i=1;i<=m;i++){
		int x=read();
		swap(p[x],p[x+1]);
	}
	while(k){
		if(k&1){
			for(int i=1;i<=n;i++) tmp[i]=u[p[i]];
			for(int i=1;i<=n;i++) u[i]=tmp[i];
		}	
		for(int i=1;i<=n;i++) tmp[i]=p[p[i]];
		for(int i=1;i<=n;i++) p[i]=tmp[i];
		k>>=1;
	}
	for(int i=1;i<=n;i++) s[i]=a[u[i]]-a[u[i]-1]+s[i-1];
	for(int i=1;i<=n;i++) printf("%.1lf\n",s[i]);
	return 0;
}