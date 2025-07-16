#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  int k,n;
  cin >> k >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  sort(a.rbegin(),a.rend());
  cout << max(2*a[0]-k-1,0);
  return 0;
}