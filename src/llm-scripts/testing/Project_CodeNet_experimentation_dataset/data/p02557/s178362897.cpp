#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n),asum(n+1,0),bsum(n+1,0);
  rep(i,n){
    cin >> a[i];
    asum[a[i]]++;
  }
  rep(i,n){
    cin >> b[i];
    bsum[b[i]]++;
  }
  rep(i,n+1){
    if(asum[i] + bsum[i] > n){
      cout << "No\n";
      return 0;
    }
  }
  rep(i,n){
    asum[i+1] += asum[i];
    bsum[i+1] += bsum[i];
  }
  int d = 0;
  rep(i,n+1){
    d = max(asum[i]-bsum[i-1],d);
  }
  cout << "Yes\n";
  rep(i,n){
    cout << b[(n+i-d)%n] << " ";
  }
  return 0;
}