#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i,n) cin >> A[i];
  sort(A.begin(),A.end());
  rep(i,n-1){
    if(A[i]!=A[i+1])continue;
    cout << "NO" <<endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
