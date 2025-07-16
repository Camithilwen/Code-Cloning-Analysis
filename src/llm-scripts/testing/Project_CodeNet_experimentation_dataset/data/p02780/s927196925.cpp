#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N,K;cin>>N>>K;
    vector<int> p(N);
    for (int i = 0; i < N; i++){
        cin>>p[i];
    }
    int ans=0;
    for (int i = 0; i < K; i++){
        ans+=p[i]+1;
    }
    int sum=ans;
    for (int i = 0; i < N-K; i++){
        sum=sum-p[i]+p[i+K];
        ans=max(ans,sum);
    }
    cout<<ans/2;
    if(ans%2!=0)cout<<".5"<<endl;
}