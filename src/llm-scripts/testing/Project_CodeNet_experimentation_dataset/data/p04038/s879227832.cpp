#include<bits/stdc++.h>
using namespace std;

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}
 
void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

const int maxn = 2e3+10;
const int maxm = maxn*maxn;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int add(int x,int y) {return x+y>mod?x+y-mod:x+y;}
int del(int x,int y) {return x-y<0?x-y+mod:x-y;}
int mul(int x,int y) {return 1ll*x*y-1ll*x*y/mod*mod;}

int n,k,f[maxn][maxn],fac[maxm],ifac[maxm],inv[maxm];

void prepare() {
    inv[0]=inv[1]=fac[0]=ifac[0]=f[0][0]=1;
    for(int i=2;i<maxm;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
    for(int i=1;i<maxm;i++) fac[i]=mul(fac[i-1],i);
    for(int i=1;i<maxm;i++) ifac[i]=mul(ifac[i-1],inv[i]);
}

int c(int nn,int mm) {return mul(fac[nn],mul(ifac[mm],ifac[nn-mm]));}

int main() {
    read(n),read(k);prepare();if(k==1) puts("1"),exit(0);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            f[i][j]=add(f[i-1][j],mul(f[i][j-1],mul(n-j+1,c(n*k-i-(k-1)*(j-1)-1,k-2))));
    write(f[n][n]);
    return 0;
}
