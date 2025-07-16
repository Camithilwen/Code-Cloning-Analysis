#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


int main(){
    ll N;
    cin >> N;
    vector<double> A(N,0);
    for(ll i=0;i<N;i++){
        cin>>A[i]
    ;}
    sort(A.begin(), A.end());
    ll ans=0;
    for(ll i=N-1;i>=1;i--){
        for(ll j=0;j<=40;j++){
            if(upper_bound(A.begin(), A.end()-(N-i), (1<<j)-A[i])!=lower_bound(A.begin(), A.end()-(N-i), (1<<j)-A[i]))
            {*lower_bound(A.begin(), A.end()-(N-i), (1<<j)-A[i])-=0.0000001;ans++;break;}
        }
    ;}
    cout<<ans<<endl;
    return 0;
}
