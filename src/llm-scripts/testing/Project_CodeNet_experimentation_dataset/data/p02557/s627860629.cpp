#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n), aa(n+1,0), bb(n+1,0);
  rep(i,n) {
    cin >> a[i];
    aa[a[i]]++;
  }
  rep(i,n) {
    cin >> b[i];
    bb[b[i]]++;
  }

  rep(i,n){
    if(bb[i+1]+aa[i+1] > n){
      cout << "No" << endl;
      return 0;
    }
  }


  cout << "Yes" << endl;
  rep(i,n){
    aa[i+1] += aa[i];
    bb[i+1] += bb[i];
  }
  
  int x = 0;
  rep(i,n){
    x = max(x,aa[i+1]-bb[i]);
  }
  rep(i,n){
    cout << b[(i-x+n)%n] << " ";
  }
  cout << endl;


}
