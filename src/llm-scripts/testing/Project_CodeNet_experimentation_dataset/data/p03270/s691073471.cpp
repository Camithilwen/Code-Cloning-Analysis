#include <bits/stdc++.h>
using namespace std;
#define N 4444
#define mod 998244353
int n,k,C[N][N],pw2[N];
int c(int n,int m){
    if (m>n||m<0)
        return 0;
    return C[n][m];
}
int calc(int m,int n){return c(n+m-1,m-1);}
int Get(int v,int n,int k){
    int ans=0;
    int lim=max(0,v/2-max(0,v-1-k));
    for (int i=0;i<=lim;i++)
        ans=(1LL*pw2[i]*C[lim][i]%mod*calc(k-lim*2+i,n-i)+ans)%mod;
    return ans;
}
int main(){
    pw2[0]=1;
    for (int i=1;i<N;i++)
        pw2[i]=pw2[i-1]*2%mod;
    for (int i=0;i<N;i++)
        C[i][0]=C[i][i]=1;
    for (int i=1;i<N;i++)
        for (int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    scanf("%d%d",&k,&n);
    for (int i=2;i<=2*k;i++)
        if (i&1)
            printf("%d\n",Get(i,n,k));
        else
            printf("%d\n",(Get(i-1,n,k-1)+Get(i-1,n-1,k-1))%mod);
    return 0;
}