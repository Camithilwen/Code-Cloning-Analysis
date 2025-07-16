#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    ll N,K;
    cin>>N>>K;
    ll cnt=1;
    rep(i,N){
        if(cnt<K){
            cnt*=2;
        }
        else{
            cnt+=K;
        }
    }
    cout<<cnt<<endl;
}
