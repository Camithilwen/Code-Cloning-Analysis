#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int K,T;
  cin>>K>>T;
  vector<int> A(T);
  for(int i(0);i<T;i++){
    cin>>A[i];
  }
  sort(A.rbegin(),A.rend());
  int sum(0);
  if(T == 1){
    cout << A[0] - 1 << endl;
  }else{
    for(int i(1);i<T;i++){
      sum += A[i];
    }
    cout << max(A[0]-sum-1,0) << endl;
  }
}

