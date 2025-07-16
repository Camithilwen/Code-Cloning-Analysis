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

const ll MOD=1000000007;

ll N;
ll A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    ll cnt0=3;
    vector<ll> cnt(N,0);
    ll ans=1;
    rep(i,N){
        if(A[i]==0){
            ans*=cnt0;
            cnt0--;
        }else{
            ans*=cnt[A[i]-1];
            cnt[A[i]-1]--;
        }
        cnt[A[i]]++;
        ans%=MOD;
    }
    ans+=MOD;
    ans%=MOD;

    cout<<ans<<endl;
}