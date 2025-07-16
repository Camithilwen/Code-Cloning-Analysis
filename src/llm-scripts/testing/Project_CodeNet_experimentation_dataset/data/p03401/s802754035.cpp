#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  int a[n+1];
  a[0] = 0;
  for(int i=1; i<=n; i++) cin >> a[i];
  int s = 0;
  for(int i=0; i<n; i++){
    s += abs(a[i+1]-a[i]);
  }
  s += abs(a[0]-a[n]);
  int de[n];
  for(int i=0; i<n-1; i++){
    de[i] = abs(a[i+2]-a[i]) - abs(a[i+1]-a[i]) -abs(a[i+2]-a[i+1]);
  }
  de[n-1] = abs(a[0]-a[n-1]) -abs(a[n] - a[n-1]) - abs(a[n]-a[0]);
  for(int i=0; i<n; i++){
    cout << s+de[i] << endl;
  }
  return 0;
}
