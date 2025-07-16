#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
signed main(){
    ll n;cin>>n;
    cout<<0<<endl;
    string s;cin>>s;
    if(s=="Vacant"){
        return 0;
    }
    cout<<n/2<<endl;
    string t;cin>>t;
    if(t=="Vacant"){
        return 0;
    }
    ll l,r;
    if(n/2%2){
    if(s==t){
        l=0,r=n/2;
    }else{
        l=n/2;
        r=n-1;
        cout<<n-1<<endl;
        cin>>s;
        if(s=="Vacant"){
            return 0;
        }
        swap(s,t);
    }
    }else{
        if(s!=t){
        l=0,r=n/2;
    }else{
        l=n/2;
        r=n-1;
        cout<<n-1<<endl;
        cin>>s;
        if(s=="Vacant"){
            return 0;
        }
        swap(s,t);
    }
    }
    while(1){
        ll mid=(r+l)/2;
        cout<<mid<<endl;
        string d;
        cin>>d;
        if(d=="Vacant"){
            return 0;
        }
        if((mid-l)%2){
            if(d==s){
                r=mid;
                t=d;
            }else{
                l=mid;
                s=d;
            }
        }else{
            if(d==s){
                l=mid;
                s=d;
            }else{
                r=mid;
                t=d;
            }
        }
    }
}