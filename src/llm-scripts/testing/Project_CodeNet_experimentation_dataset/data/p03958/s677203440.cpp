#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int k,t; cin >> k >> t;
  int mx = 0;
  vi a(t);
  rep(i,t){
    cin >> a[i];
    chmax(mx,a[i]);
  }
  if((k+1)/2 < mx){
    cout << (mx-(k+1)/2)*2-1;
  }else{
    cout << 0;
  }
  cout << "\n";
  return 0;
}
