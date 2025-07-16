#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define re_ return

ll e[19];

ll DFS(ll n, ll m, char k)
{
//    printf("%lld %lld\n", n, m);
    n=abs(n);
    if(m==-1) re_ !n;
    if(!m) re_ n? 0: 10;
    int i=n/e[m];
    if(i>9) re_ 0;
    if((n+i)%10==0)
        re_ max(10-i-k, 0)*DFS((n-i*e[m]+i)/10, m-2, 0);
    else if((n+i+1)%10==0)
        re_ max(10-i-1-k, 0)*DFS((n-(i+1)*e[m]+i+1)/10, m-2, 0);
    re_ 0;
}

int main()
{
    ll n, i, r=0;
    scanf("%lld", &n);
    for(i=e[0]=1; i<19; ++i) e[i]=e[i-1]*10;
//    printf("%lld\n", e[18]);
    for(i=1; i<19; ++i) r+=DFS(n, i, 1);
//    DFS(n, 8, 1);
    printf("%lld\n", r);
    re_ 0;
}
