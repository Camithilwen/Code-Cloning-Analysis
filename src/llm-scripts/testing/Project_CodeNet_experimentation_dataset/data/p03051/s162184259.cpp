#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5+15;
const int mod = 1e9+7;
const int M = (1<<22);
int A[N];

int add(int x,int y) {
    return (x+y)%mod;
}
int mul(int x,int y) {
    return (ll)x*y%mod;
}

int dp[M];
int sum[M],X[M];

void solve() {
    int n;
    scanf("%d",&n);
    int g = 0;
    for(int i=0;i<n;++i) {
        scanf("%d",&A[i]);
        g^= A[i];
    }
    int c = 0;
    int ret = 0;
    ++dp[0];
    if(g>0) {
        for(int i=0;i<n-1;++i) {
            c^= A[i];
            if(c==0) {
                ret = add(ret,dp[g]);
                int u = dp[g];
                dp[0] = add(dp[0],u);
            } else if(c==g) {
                int u = dp[0];
                dp[g] = add(dp[g],u);
            }
        }
        ret = add(ret,1);
    } else {
        int k = 0;
        for(int i=0;i<n-1;++i) {
            c^= A[i];
            if(c==0) {
                ret= add(ret,dp[0]);
                dp[0] = add(dp[0],dp[0]);
                ++k;
            } else {
                int x = k - sum[c];
                sum[c] = k;
                int v = mul(x,X[c]);
                dp[c] = add(dp[c],v);
                X[c] = add(1,add(X[c],dp[c]));
                ret = add(1,add(ret,dp[c]));
            }
        }
        ret = add(ret,1);
    }
    printf("%d\n", ret);
}

int main(){
    //freopen("input.txt","r",stdin);
    solve();
}
