#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<char,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;




int main(){
    string N;
    cin >> N;
    ll n=N.size();
    ll ans=0;
    vector<ll> keta(n,0);
    for(ll i=0;i<n;i++){
        keta[i]=N[i]-'0'
    ;}
    for(ll i=n-1;i>=0;i--){
        if(keta[i]==10){
            if(i>0){
                keta[i-1]++;
                keta[i]=0;
            }
            else ans+=1;
        }
        else if(keta[i]<=4){
            ans+=keta[i];
        }
        else if(keta[i]>=6&&keta[i]<=9){
            ans+=10-keta[i];
            if(i>0){
                keta[i-1]++;
            }
            else ans+=1;
        }
        else if(keta[i]=5){
            if(i==0){
                ans+=5; 
            }
            else if(keta[i-1]<=4){
                ans+=5;
            }
            else if(keta[i-1]>=5){
                ans+=5;
                keta[i-1]+=1;
            }
        }
    ;}
    cout<<ans<<endl;
    
    return 0;
}
