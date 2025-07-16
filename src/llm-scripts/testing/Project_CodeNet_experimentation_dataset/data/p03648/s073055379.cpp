#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
ll int MOD=998244353;
#define N 3000000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    ll int k;
    cin>>k;
    ll int kk=k;
    int n=50;
    ll int a[50]={};
    rep(i,50){
        a[i]=kk/50;
        k-=kk/50;
    }
    rep(i,50){
        if(k>0){
            a[i]++;
            k--;
        }
    }
    cout<<50<<endl;
    rep(i,50){
        a[i]=(ll)51*a[i]-kk+(ll)49;
        cout<<a[i]<<" ";
    }
    return 0;
}