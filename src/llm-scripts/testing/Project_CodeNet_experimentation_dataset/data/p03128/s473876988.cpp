#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<int,int> P;
ll mod=pow(10,9)+7;
ll INF=pow(10,18);

int main(){
    int N,M;scanf("%d %d",&N,&M);
    vec A(M);
    for(int i=0;i<M;i++) scanf("%lld",&A[i]);
    sort(A.begin(),A.end(),greater<ll>());
    vec n={0,2,5,5,4,5,6,3,7,6};
    mat dp(N+1,vec(M+1,0));
    //漸化式
    for(int i=0;i<N-1;i++){
        if(i>0 && dp[i][0]==0) continue;
        vec v;
        for(int j=0;j<M;j++){
            if(i+n[A[j]]>N) continue;
            v=dp[i];v[0]++;v[j+1]++;
            int t=dp[i+n[A[j]]][0];
            if(v[0]>t){
                dp[i+n[A[j]]]=v;
            }
            else if(v[0]==t){
                for(int k=1;k<=M;k++){
                    if(v[k]>dp[i+n[A[j]]][k]){
                        dp[i+n[A[j]]]=v;
                        break;
                    }
                    else if(v[k]<dp[i+n[A[j]]][k]){
                        break;
                    }
                }
            }
        }
    }
    string ans;
    for(int i=0;i<M;i++){
        char c=A[i]+'0';
        for(int j=0;j<dp[N][i+1];j++) ans+=c;
    }
    cout<<ans<<endl;
    return 0;
}