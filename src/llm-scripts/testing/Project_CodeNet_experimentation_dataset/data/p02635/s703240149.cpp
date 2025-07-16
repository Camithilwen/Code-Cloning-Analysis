#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
using namespace std;int M=998244353,N,K,a,s[303],d[303][303][303]={1};main(){string S;cin>>S>>K;K=min((int)S.size(),K);for(auto c:S)c=='0'?++N:++s[N];f(i,0,N)f(j,0,K)f(k,0,j)f(l,-min(k,s[i]),K-j)(d[i+1][j+max(l,0)][k+l]+=d[i][j][k])%=M;f(i,0,K)(a+=d[N+1][i][0])%=M;cout<<a;}