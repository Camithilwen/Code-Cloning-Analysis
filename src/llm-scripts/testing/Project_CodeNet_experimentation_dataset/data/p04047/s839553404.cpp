#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define mx 1000008

#define pii pair<int,int>
#define pi acos(-1.0)
#define pb push_back
#define ss second
#define ff first
typedef long long int ll;
///adjacent move
int fx[4]={0,+1,0,-1};
int fy[4]={+1,0,-1,0};
///knight
ll prime[mx];
void seive()
{
    for(int i=2;i<mx;i+=2) prime[i]=2;
    for(int i=3;i<mx;i+=2) prime[i]=i;
    ll sq=sqrt(mx);
    for(int i=3;i<=sq;i+=2){
        if(prime[i]==i){
            for(int j=i*i;j<mx;j+=i){
                if(prime[j]==j) prime[j]=i;
            }
        }
    }
}
int a[1000004];
ll f[2000004];
ll po[2000004];
int main()
{
    //seive();
    int t=1;
    //cin>>t;


    int c=0;
    vector<ll>vec;
    for(int i=2;i<mx;i++){
        if(prime[i]==i){
            vec.push_back(i);
        }
    }
    while(t--){
        ll n,m;

        cin>>n;

        ll a[n*2+7];
        for(int i=1;i<=2*n;i++) cin>>a[i];
        ll sum=0;
        sort(a+1,a+2*n+1);
        for(int i=1;i<=2*n;i++){
            if(i&1) sum+=a[i];
        }
        cout<<sum<<endl;
    }
}
