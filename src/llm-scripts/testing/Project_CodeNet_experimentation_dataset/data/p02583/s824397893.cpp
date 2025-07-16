#include <iostream>
using namespace std;

int func(int x, int y, int z){
//  cout << x << " " << y << " " << z << endl;
  if (x==y||y==z||z==x) return false;
  if (x+y>z&&y+z>x&&z+x>y){
//    cout << "ok" << endl;
    return true;
  }
  return false;
}

int main(void){
  int n,ans;
  int len[200];
  
  cin >> n;
  for (int i=0; i<n; i++) cin >> len[i];
  ans = 0;
  for (int i=0; i<n; i++){
    for (int j=i+1; j<n; j++){
      for (int k=j+1; k<n; k++){
        ans += func(len[i], len[j], len[k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}