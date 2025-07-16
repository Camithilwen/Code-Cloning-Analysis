#include <iostream>
#include<bits/stdc++.h>
#define base 950527
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
vector<P> res;
ll lh,ns,nt,LH,tmp=1,n,s[200005],t[200005],K[200005],S[200005],T[200005];
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>S[i];
    }
    for(int i=0;i<n;i++){
        cin>>T[i];
    }
    for(int i=0;i<n;i++){
        K[i]=S[i]^T[0];
    }
    for(int i=0;i<n;i++){
        s[i]=S[i]^S[(i+1)%n];
        t[i]=T[i]^T[(i+1)%n];
        //cout<<s[i]<<endl;
    }
    //cin>>s>>t;
    ns=n;
    nt=n;
    for(int i=0;i<nt;i++){
        lh=lh*base+s[i];
        LH=LH*base+t[i];
        tmp*=base;
    }
    if(lh==LH)res.push_back({0,K[0]});
    for(int i=0;i<ns-1;i++){
        lh=lh*base-tmp*s[i];
        lh+=s[i];
        //cout<<LH<<" "<<lh<<" "<<i<<endl;
        if(LH==lh)res.push_back({i+1,K[i+1]});
    }
    sort(res.begin(),res.end());
    for(auto x:res){
        cout<<x.first<<" "<<x.second<<endl;
    }
}
