#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,t;
  cin >> n >> t;
  vector<int> v(n);
  int i;
  for(i=0;i<n;i++) cin >> v[i];
  long long cnt = 0;
  for(i=0;i<n-1;i++){
    if(v[i+1]-v[i]<=t) cnt+= v[i+1]-v[i];
    else cnt += t;
  }
  cnt += t;
  cout << cnt << "\n";
  return 0;
}
