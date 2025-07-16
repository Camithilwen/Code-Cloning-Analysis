#include <bits/stdc++.h>
#define name "bai3"
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define maxn 100009
#define ll long long
using namespace std;
const int mod=1e9+7;
int n,a[maxn*2],xd[maxn*2];
ll p[maxn];
//ll q[maxn*2];
/*ll mu(int a, int b){
    if(b==0) return 1;
    ll tg=mu(a,b/2);
    tg=(tg*tg)%mod;
    if(b%2)tg=(tg*a)%mod;
    return tg;
}
ll c(int a, int b){
    ///return b!/(a!*(b-a)!)
    if(a==0)return 0;
    if(a>b)return 0;
    return (((p[b]*q[a])%mod)*q[b-a])%mod;
}*/
int main()
{
    cin >> n;
    int s=0;
    p[0]=1;
    fto(i,1,n)p[i]=(p[i-1]*i)%mod;
    /*q[0]=1;
    q[1]=1;
    fto(i,2,n*2) q[i]=mu(p[i],mod-2);*/
    fto(i,1,n*2){
        char c;
        cin >> c;
        if(c=='B')a[i]=1;
        else a[i]=0;
        if(a[i]==s){
            xd[i]=-1;
        }
        else{
            xd[i]=1;
        }
        s^=1;
    }
    int s1=0,s2=0;
    ll res=1;
    fto(i,1,n*2)
    if(xd[i]==1)++s1;
    else{
        if(s1>s2)res=(res*(s1-s2))%mod;
        else res=0;
        if(res==0)break;
        ++s2;
    }
    if(s1!=s2)res=0;
    cout << res*p[n]%mod;
    return 0;
}
/*
BWWB
WWWW


*/
