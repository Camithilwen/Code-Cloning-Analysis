#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<vector<int>> v(n,vector<int>(n-1));
  rep(i,n)rep(j,n-1)cin >> v[i][j],v[i][j]--;
  set<P> st;
  vector<P> nxt;
  rep(i,n){
    if(i < v[i][0])nxt.push_back(make_pair(v[i][0],i));
    else nxt.push_back(make_pair(i,v[i][0]));
  }
  vector<int> l(n,1);
  int roop = n*(n-1)/2;
  ll res = 0;
  while(roop){
    if(nxt.empty())break;
    vector<P> k;
    for(auto au : nxt){
      if(st.count(au)){
        roop--;
        if(l[au.first] < n-1)k.push_back(make_pair(max(au.first,v[au.first][l[au.first]]),min(au.first,v[au.first][l[au.first]])));
        if(l[au.second] < n-1)k.push_back(make_pair(max(au.second,v[au.second][l[au.second]]),min(au.second,v[au.second][l[au.second]])));
        l[au.first]++;
        l[au.second]++;
      }else{
        st.insert(au);
      }
    }
    nxt = k;
    res++;
  }
  cout << (!roop ? res : -1) << endl;







  


  return 0;
}