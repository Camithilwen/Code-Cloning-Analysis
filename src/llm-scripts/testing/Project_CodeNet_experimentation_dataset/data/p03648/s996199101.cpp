#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
int main(){
    scanf("%lld",&k);
    int n=50;
    vector<ll> v(n,n-1);
    for(int i=0;i<n;i++)v[i]+=k/n;
    for(int i=0;i<n;i++)v[i]-=k%n;
    for(int i=0;i<k%n;i++)v[i]+=n+1;
    printf("%d\n",n);
    for(int i=0;i<n;i++)printf("%lld ",v[i]);
    printf("\n");
    return 0;
}