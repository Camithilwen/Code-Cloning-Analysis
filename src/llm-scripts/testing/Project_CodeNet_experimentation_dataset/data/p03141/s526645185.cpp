#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;

ll N;
ll A[100000], B[100000];
ll sum[100000];

int main(){
    cin>>N;
    rep(i,N){
        cin>>A[i]>>B[i];
        sum[i]=A[i]+B[i];
    }

    ll ans=0;
    rep(i,N) ans-=B[i];

    sort(sum,sum+N,greater<>());

    for(int i=0;i<N;i+=2) ans+=sum[i];

    cout<<ans<<endl;
}