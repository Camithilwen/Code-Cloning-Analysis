// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
//#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,n,maxi=0,f=0,mini=INF;
    ll sum=0;
    string str,sub;
    ll h,w;
    ll m;
    cin>>n>>m;
    if(m==0){
        if(n==1){
            cout<<0<<endl;
        }else if(n==2){
            cout<<10<<endl;
        }else{
            cout<<100<<endl;
        }
        return 0;
    }
    vector<pair<ll,ll>> s(m);

    rep(i,m){
        cin>>a>>b;
        s[i]=make_pair(a,b);
    }
    f=0;
    sort(s.begin(),s.end());
    sum=0;
            if(s[0].first==1) {
                //sum-=100;
                if(s[0].second==0&&n!=1) f=1;

                sum+=100*s[0].second;
            }
            if(s[0].first==2){
                //if(s[0].second==0&&n==2) f=1;

                sum+=10*s[0].second;
               // sum-=10;
            } 
            if(s[0].first==3){
                //sum-=1;
                sum+=1*s[0].second;
            } 
    for(ll i=1;i<m;i++){
        if(s[i-1].first==s[i].first&&s[i-1].second!=s[i].second) f=1;
        else if(s[i-1].first==s[i].first&&s[i-1].second==s[i].second) continue;
        else{
            if(s[i].first==1) {
               // sum-=100;
               if(s[i].second==0&&n!=1) f=1;
                sum+=100*s[i].second;
            }
            if(s[i].first==2) {
               // sum-=10;
                sum+=10*s[i].second;
            }
            if(s[i].first==3) {
              //  sum--;
                sum+=1*s[i].second;
            }
        }
    }
    if(n==1&&sum!=0) sum/=100;
    if(n==2&&sum!=0) sum/=10;
    if(n==3&&sum!=0&&sum<100) sum+=100;
    if(n==2&&sum<10) sum+=10;
    if(f!=1&&sum==0&&n==1){
        cout<<0<<endl;
        return 0;
    }
    
    if(f==1){
        cout<<"-1"<<endl;
    }else{
        cout<<sum<<endl;
    }
    return 0;
}
