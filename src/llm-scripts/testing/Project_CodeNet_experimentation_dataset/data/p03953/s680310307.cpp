#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100100;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return f*x;
}
int val[maxn],tmp[maxn],n,num[maxn],m,x,ans[maxn];
long long k;double last[maxn];
int main(){
    n=read();
    for(register int i=1;i<=n;i++) 
        val[i]=read(),tmp[i]=i,ans[i]=i;
    m=read();k=read()*1ll;
    for(register int i=1;i<=m;i++)
        x=read(),swap(tmp[x],tmp[x+1]);
    for(;k;k>>=1){
        if(k&1){
            for(register int i=1;i<=n;i++)
                num[i]=ans[tmp[i]];
            for(register int i=1;i<=n;i++)
                ans[i]=num[i]; 
        }         
        for(register int i=1;i<=n;i++)
            num[i]=tmp[tmp[i]];
        for(register int i=1;i<=n;i++)
            tmp[i]=num[i];
    }
    for(register int i=1;i<=n;i++)
        last[i]=val[ans[i]]-val[ans[i]-1];
    for(register int i=1;i<=n;i++)
        printf("%.1lf\n",last[i]+=last[i-1]);
}