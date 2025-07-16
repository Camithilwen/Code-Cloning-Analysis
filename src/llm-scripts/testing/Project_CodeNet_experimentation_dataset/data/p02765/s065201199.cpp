#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  int n,r;
  cin >> n >> r;
  int ans=0;
  if(n<=9){
    ans=r+100*(10-n);
  }
  else{
    ans=r;
  }
  cout << ans << endl;
  

  return 0;

}
