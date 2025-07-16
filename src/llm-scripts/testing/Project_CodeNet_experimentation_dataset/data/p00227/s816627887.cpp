#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m,n+m){
    vector<int>ve(n);
    ll ans=0;
    for(int i=0;i<n;i++){
      cin>>ve[i];ans+=ve[i];
    }
    sort(ve.begin(),ve.end(),greater<int>());
    for(int i=m-1;i<n;i+=m)
      ans-=ve[i];
    cout<<ans<<endl;
  }
  return 0;
}

