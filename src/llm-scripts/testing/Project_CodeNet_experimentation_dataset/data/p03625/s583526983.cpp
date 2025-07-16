/***

    Muhammad Imdad-Ul-Haque Rakib(Attari)
    CSE'19
    Chittagong,Bangladesh

***/


#include<bits/stdc++.h>


/**Definitions**/


#define   ld             long double
#define   ll             long long
#define   boost_         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define   pb             push_back
#define   ppb            pop_back
#define   ull            unsigned long long
#define   over           return 0
#define   scan(i,n,a)    for(i=0;i<n;i++) cin>>a[i]
#define   MP             make_pair
#define   spc            " "

using namespace std;


/** Predefined Functions **/


int gcd(int x,int y){
    if(x==0) return y;
    else return gcd(y%x,x);
}
bool sortbysec(const pair<int,int>&a, const pair<int,int>&b){ return (a.second<b.second); }
bool sortbysecinrev(const pair<int,int>&a, const pair<int,int>&b){ return (a.second>b.second); }
bool sortbysize(string &s1,string &s2){ return s1.size() < s2.size(); }
bool sortinrev(const pair<int,int> &a, const pair<int,int> &b){ return (a.first > b.first); }


/** Main Function **/


int main(){

    boost_;
    ll n;
    cin>>n;
    ll a[n],i,a1=0,a2=0,a3=0;
    vector<ll>v,q;
    map<ll,ll>mp;
    scan(i,n,a);

    sort(a,a+n,greater<int>());

    for(i=0;i<n;++i){
        mp[a[i]]++;
        if(mp[a[i]]==1) q.pb(a[i]);
    }

    for(i=0;i<q.size();++i){
        if(mp[q[i]]>=2) v.pb(q[i]);
        if(v.size()==2) break;
    }
    if(v.size()==0) cout<<0<<endl;
    else{

       if(v.size()==1){if(mp[v[0]]>=4) cout<<v[0]*v[0]<<endl; else cout<<0<<endl;}
       else{
           if(mp[v[0]]>=4) cout<<v[0]*v[0]<<endl;
           else cout<<v[0]*v[1]<<endl;
       }
    }


    over;
}
