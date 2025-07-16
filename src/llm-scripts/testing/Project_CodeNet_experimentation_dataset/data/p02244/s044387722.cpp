#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int k;
  cin>>k;
  
  int r,c;
  vector<int> A(8),B(8);
  rep(i,8) A[i]=i;
  rep(i,8) B[i]=-1;
  rep(i,k){
    cin>>r>>c;
    B[r]=c;
  }
  
  char C[8][8];
  rep(i,8){
    rep(j,8) C[i][j]='.';
  }
  
  set<int> p,q;
  do{
    bool b=true;
    rep(i,8){
      if(B[i]!=-1 && B[i]!=A[i]) b=false;
    }
    if(b==false) continue;
    rep(i,8) p.insert(i+A[i]);
    rep(i,8) q.insert(i-A[i]);
    if(p.size()!=8 || q.size()!=8){
      p.clear(); q.clear();
      continue;
    }
    rep(i,8) C[i][A[i]]='Q';
    break;
  }while(next_permutation(ALL(A)));
  
  rep(i,8){
    rep(j,8) cout<<C[i][j];
    cout<<endl;
  }
  
  return 0;
}
