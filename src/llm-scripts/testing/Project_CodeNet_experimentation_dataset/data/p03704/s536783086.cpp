#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
 
int n,d;
long long v[20],maxv[30];
 
long long qpow(int x,int y){
    long long ans=1;
    while(y){
        if(y&1)ans*=x;
        y>>=1,x*=x;
    }
    return ans;
}
 
long long dfs(long long x,int p){
    if(p==n)return (x==d);
    if(d<x-maxv[p]||d>x+maxv[p])return 0;
    long long ans=0;
    for(int i=-9;i<=9;i++){
        if(p)ans+=dfs(x+v[p]*i,p+1)*(10-abs(i));
        else if(i^9)ans+=dfs(x+v[p]*i,p+1)*(i>=0?9-i:10+i);
    }
    return ans;
}
 
int main(){
    scanf("%d",&d);
    long long ans=0;
    for(int i=1;i<=18;i++){
        memset(maxv,0,sizeof(maxv));
        n=i+1>>1;
        for(int j=0;j<n;j++)v[j]=qpow(10,i-j)-qpow(10,j);
        for(int j=0;j<n;j++)
        for(int k=j;k<n;k++)maxv[j]+=v[k]*9;
        ans+=dfs(0,0)*(i&1?1:10);
    }
    printf("%lld\n",ans);
    return 0;
}