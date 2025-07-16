#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,m,X,Y;
  cin >> n >> m >> X >> Y;
  
  int x[n],y[m];
  rep(i,n) cin >> x[i];
  rep(i,m) cin >> y[i];
  
  int flag = 0;
  for(int z = X+1; z <= Y; z++){
    rep(i,n){
      if(z <= x[i]){
        flag = 1;
        break;
      }//if
    }//rep
    rep(i,m){
      if(z > y[i]){
        flag = 1;
        break;
      }//if
    }//rep
    
    if(flag == 0){
      cout << "No War" << endl;
      return 0;
    }
    flag = 0;
  }//for
  
  cout << "War" << endl;
}