#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long ksm(long long u,long long v){
	long long o=1;
	while(v){
		if(v&1)
			o=o*u%mo;
		u=u*u%mo;
		v>>=1;
	}
	return o;
}
int n,k,i,x,ans,f[100005];
int top,nex[200005],to[200005],fir[100005];
void lj(int u,int v){
	top++;
	nex[top]=fir[u];
	fir[u]=top;
	to[top]=v;
}
void ss(int u,int v){
	for(int top1=fir[v];top1;top1=nex[top1]){
		ss(v,to[top1]);
		f[v]=max(f[to[top1]],f[v]);
	}
	if(v==1)
		return;
	f[v]++;
	if(f[v]==k&&u!=1){
		ans++;
		f[v]=0;
	}
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();k=read();
   	x=read();
   	if(x!=1)
   		ans++;
   	for(i=2;i<=n;i++){
   		x=read();   		
   		lj(x,i);
   	}
   	ss(1,1);
   	pus(ans,2);
    return 0;
}