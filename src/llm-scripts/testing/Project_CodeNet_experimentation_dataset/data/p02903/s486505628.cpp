#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h,w;
  cin >> h >> w;

  int a,b;
  cin >> a >> b;

  rep(i,h){
    rep(j,w){
      bool left,up;
      if(j<a) left = true;
      else left = false;

      if(i<b) up = true;
      else up = false;
      cout << (left^up);
    }
    cout << endl;
  }
  
  return 0;
    

}
