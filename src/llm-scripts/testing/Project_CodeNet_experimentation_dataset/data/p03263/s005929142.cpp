#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int H,W; cin>>H>>W;
  vector<vector<int>> A(H,vector<int>(W));
  rep(i,H){
    rep(j,W){
      cin>>A.at(i).at(j);
    }
  }
  rep(i,H) if(i%2==1) reverse(A.at(i).begin(),A.at(i).end());
  
  vector<int> S;
  vector<bool> F(H*W,false);
  rep(i,H){
    rep(j,W){
      S.push_back(A.at(i).at(j)%2);
    }
  }
  int count=0,temp=0;
  rep(i,H*W-1){
    if(temp==0&&S.at(i)==1)temp++;
    else if(temp==1&&S.at(i)==1)temp--;
    
    if(temp==1){
      F.at(i)=true;
      count++;
    }
  }
  cout<<count<<endl;
  
  rep(i,H*W){
    if(F.at(i)){
      int x=i%W,y=i/W,xd,yd;
      if(y%2==0){
        if(x==W-1) xd=x,yd=y+1;
        else xd=x+1,yd=y;
      }
      else{
        x=W-x-1;
        if(x==0) xd=x,yd=y+1;
        else xd=x-1,yd=y;
      }
      cout<<y+1<<' '<<x+1<<' '<<yd+1<<' '<<xd+1<<endl;
    }
  }
}
