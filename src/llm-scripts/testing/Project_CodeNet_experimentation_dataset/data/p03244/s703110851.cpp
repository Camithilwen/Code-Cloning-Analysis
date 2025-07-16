#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define obit __builtin_popcount
#define pof pop_front
#define For(i,a,n) for(i=a;i<n;i++)
#define all(ar) ar.begin(),ar.end() 
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned short int us;
typedef short int ss;
typedef long double ld;
const ll mod = 1000000007;


bool cmp(pair<int,int> a,pair<int,int> b){
    return a.S > b.S;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    //*/
    ll i,n;
    cin>>n;
    ll ar[n];
    For(i,0,n) cin>>ar[i];
    map<ll,ll> oc0, oc1;
    pair<ll,ll> mx10 = {-1,0},mx11 = {-1,0},mx20 = {-1,0},mx21 = {-1,0};
    for(ll a = 0; a < n;a += 2){
        oc0[ar[a]] += 1;
    }
    for(ll a = 1; a < n;a += 2){
        oc1[ar[a]] += 1;
    }
    vector<pair<ll,ll> > vec0,vec1;
    for(auto itr = oc0.begin(); itr != oc0.end(); ++itr){
        vec0.pb(*itr);
    }
    for(auto itr = oc1.begin(); itr != oc1.end(); ++itr){
        vec1.pb(*itr);
    }
    sort(vec0.begin(),vec0.end(),cmp);
    sort(vec1.begin(),vec1.end(),cmp);
    mx10 = vec0[0];
    mx11 = vec1[0];
    if(vec0.size()>1) mx20 = vec0[1];
    if(vec1.size()>1) mx21 = vec1[1];
    //for(auto k: vec0) cout<<k.F sp<<k.S el;
    //for(auto k: vec1) cout<<k.F sp<<k.S el;
    if(mx11.F != mx10.F){
        int a = mx10.S, b = mx11.S;
        cout<<n - (a + b);
    }
    else{
        int x;
        x = max((mx10.S + mx21.S),(mx11.S + mx20.S));
        cout<< n - x;
    }
    return 0;
}