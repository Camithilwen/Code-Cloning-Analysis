#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005,ha=1e9+7;
 
inline int add(int x,int y){ x+=y; return x>=ha?x-ha:x;}
inline void ADD(int &x,int y){ x+=y; if(x>=ha) x-=ha;}
 
inline int ksm(int x,int y){
    int an=1;
    for(;y;y>>=1,x=x*(ll)x%ha) if(y&1) an=an*(ll)x%ha;
    return an;
}
 
int jc[N],ni[N],f[N],n,a,b,c,d,ans,inv[N];
 
inline void init(){
    jc[0]=1;
    for(int i=1;i<=n;i++) jc[i]=jc[i-1]*(ll)i%ha;
    ni[n]=ksm(jc[n],ha-2);
    for(int i=n;i;i--) ni[i-1]=ni[i]*(ll)i%ha;
}
 
inline void dp(){
    f[0]=1;
    for(int i=a;i<=b;i++) // 最外层枚举 队伍的人数
        for(int m=i*c,j=min(i*d,n);j>=m;j--) // 第二层枚举 已经选好的人数
            for(int k=c,now=ksm(ni[i],c),M=j-c*i;k<=d&&M>=0;k++,M-=i,now=now*(ll)ni[i]%ha)
                /* 第三层枚举 这种人数的队伍选几个*/
                ADD(f[j],jc[j]*(ll)now%ha*(ll)ni[M]%ha*(ll)f[M]%ha*(ll)ni[k]%ha);
}
 
int main(){
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    init(),dp(),printf("%d\n",f[n]);
    return 0;
}