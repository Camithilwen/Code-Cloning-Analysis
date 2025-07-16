#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int pds=998244353;
const int N=1000086;
int q1[N+5],q2[N+5];
int Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a%pds)
        if(b&1) ans=1ll*ans*a%pds;
    return ans;
}
void Init()
{
    q1[0]=1;
    for(int i=1;i<=N;i++)
        q1[i]=1ll*q1[i-1]*i%pds;
    q2[N]=Pow(q1[N],pds-2);
    for(int i=N-1;i>=0;i--)
        q2[i]=1ll*q2[i+1]*(i+1)%pds;
}
int C(const int &n,const int &m){return 1ll*q1[n]*q2[m]%pds*q2[n-m]%pds;}
int invC(const int &n,const int &m){return 1ll*q2[n]*q1[m]%pds*q1[n-m]%pds;}
int main()
{
    int n,m;Init();
    cin>>n>>m;
    int t=min(n,m),ans=0;
    for(int i=1;i<=t;i++)
    {
    	ans=(ans+1ll*C(2*i,i)*C(n+m-2*i,n-i))%pds;
    }
    ans=1ll*ans*invC(n+m,n)%pds*q2[2]%pds;
    cout<<(ans+max(n,m))%pds;
    return 0;
}