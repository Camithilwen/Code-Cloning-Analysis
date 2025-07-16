#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG

int main() {
  int n;
  cin >> n;
  vector<pair<int,int>> a(n);
  vector<pair<int,int>> b(n);
  rep(i,n)
    cin >> a[i].second >> a[i].first;
  sort(a.rbegin(),a.rend());
  rep(i,n)
    cin >> b[i].first >> b[i].second;
  sort(b.begin(),b.end());
  
  int c=0;
  rep(i,n){
    rep(j,n){
      if((b[i].first>a[j].second)&&(b[i].second>a[j].first)){
        a[j]=make_pair(300,300);
        c++;
        break;
      }
    }
  }
  
  cout << c << endl;
}
      
    
