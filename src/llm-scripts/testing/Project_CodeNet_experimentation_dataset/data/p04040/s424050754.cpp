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
long long n,m,a,b,i,j,jc[200005],ny[200005],ans;
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
long long C(long long u,long long v){
	return jc[u]*ny[v]%mo*ny[u-v]%mo;
}
long long Q(long long u,long long v){
	return C(u+v,v);
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    n=read();m=read();a=read();b=read();
    jc[0]=1;
    for(i=1;i<=n+m;i++)
   		jc[i]=jc[i-1]*i%mo;
   	ny[n+m]=ksm(jc[n+m],mo-2);
   	for(i=n+m-1;i>=0;i--)
   		ny[i]=ny[i+1]*(i+1)%mo;
   	ans=Q(n-1,m-1);
   	for(i=1;i<=b;i++)
   		ans=(ans-Q(n-a-1,i-1)*Q(a-1,m-i)%mo+mo)%mo;
   	pus(ans,2);
    return 0;
}