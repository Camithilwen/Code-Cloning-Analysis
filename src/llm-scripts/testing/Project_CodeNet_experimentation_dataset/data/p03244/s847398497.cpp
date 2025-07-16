#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi v(n); rep(i,n) cin >> v[i];
  map<int,int> odd,even;
  rep(i,n){
    if(i % 2 == 0) even[v[i]]++;
    else odd[v[i]]++;
  }
  int mx_odd1 = 0, mx_even1 = 0, num_odd1, num_even1;
  for(auto x : odd) if(chmax(mx_odd1,x.second)) num_odd1 = x.first;
  for(auto x : even) if(x.first != num_odd1 && chmax(mx_even1,x.second)) num_even1 = x.first;

  int mx_odd2 = 0, mx_even2 = 0, num_odd2, num_even2;
  for(auto x : even) if(chmax(mx_even2,x.second)) num_even2 = x.first;
  for(auto x : odd) if(x.first != num_even2 && chmax(mx_odd2,x.second)) num_odd2 = x.first;

  int res = max(mx_odd1+mx_even1,mx_odd2+mx_even2);
  cout << n - res;
  cout << "\n";
  return 0;
}
