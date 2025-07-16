#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<long long> A(n);
  for(int i=0;i<n;i++) cin >> A.at(i);
  vector<long long> sa(n+1,0);
  for(int i=0;i<n;i++) sa.at(i+1) = sa.at(i) + A.at(i);
  long long ans = 10000000000000000;
  for(int i=1;i<n-1;i++){
    long long left = sa.at(i+1);
    long long right = sa.at(n) - sa.at(i+1);
    
    int lsplit = min(int(upper_bound(sa.begin(),sa.end(),left/2) - sa.begin() - 2),i-1);
    int rsplit = min(int(upper_bound(sa.begin(),sa.end(),right/2 + left) - sa.begin() - 2),n-2);
    // cout << "rsplit = " << rsplit << endl;
    long long lM = min(max(sa.at(lsplit + 1),sa.at(i+1) - sa.at(lsplit + 1)),max(sa.at(lsplit + 2), sa.at(i+1) - sa.at(lsplit + 2)));
    long long rM = min(max(sa.at(rsplit + 1)-sa.at(i+1),sa.at(n)-sa.at(rsplit+1)) ,max(sa.at(rsplit+2)-sa.at(i+1),sa.at(n) - sa.at(rsplit+2)));
    // cout << "rM = " << rM << endl;
    long long M = max(lM,rM);
    long long m = min(sa.at(i+1) - lM,sa.at(n) - sa.at(i+1) - rM);
    // cout << i << ":" << M-m << " M = "<< M << " m = " << m << endl;
    ans = min(ans, M-m);
  }
  cout << ans << endl;
}
