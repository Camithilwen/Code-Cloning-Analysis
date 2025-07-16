#include<bits/stdc++.h>
#define mo 1000000007
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
long long n,m,i,j,x,y,flag,book[100005],sd[100005],sum,c,p,ans;
long long top,nex[400005],to[400005],fir[100005];
void lj(int u,int v){
	top++;
	nex[top]=fir[u];
	fir[u]=top;
	to[top]=v;
}
void ss(int v,int w){
	sd[v]=w;
	for(int top1=fir[v];top1;top1=nex[top1])
		if(sd[to[top1]]==0)
			ss(to[top1],w+1);
		else if(sd[v]>sd[to[top1]]){ 
			if((sd[v]-sd[to[top1]]&1)==0)
				flag=1;
		}
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();m=read();
   	for(i=1;i<=m;i++){
		x=read();y=read();
		lj(x,y);
		lj(y,x);
		book[x]=1;
		book[y]=1;
	}
	for(i=1;i<=n;i++)
		if(book[i]==0)
			sum++;
	for(i=1;i<=n;i++)
		if(book[i]==1&&sd[i]==0){
			flag=0;
			ss(i,1);
			if(flag==1)
				p++;
			else
				c++;
		}
	ans=sum*n*2-sum*sum+c*c*2+p*(p+c*2);
	pus(ans,2);
    return 0;
}