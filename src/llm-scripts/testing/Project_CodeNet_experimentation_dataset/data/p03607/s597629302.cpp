#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
  int n; cin >>n;
  vector<ll> a(n);
  rep(i,n) cin >>a[i];
  map<ll,ll>  mp;
  rep(i,n) mp[a[i]]++;
  ll ans=0;
  for(auto x :mp){
    if(x.second%2==1) ans++;
  }
  cout <<ans<<endl;
}