#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<pair<int,int>> a(N),b(N);
  for(int i(0);i<N;i++){
    cin>>a[i].second>>a[i].first;
  }
  for(int i(0);i<N;i++){
    cin>>b[i].first>>b[i].second;
  }
  sort(a.rbegin(),a.rend());
  sort(b.begin(),b.end());
  int ans(0);
  int used[100] = {0};
  for(int i(0);i<N;i++){
    for(int j(0);j<N;j++){
      if(a[j].second < b[i].first){
        if(used[j] == 0 && a[j].first < b[i].second){
          used[j] = 1;
          ans++;
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

